#include <ros/ros.h> // Debug
#include <iostream> // Debub
#include <Eigen/Core>
#include"mpc.h"

#define kmax 1	//max number of iteration of Givens rotations

//checking empty matrix
bool isEmpty(Eigen::Matrix<double,2,2> z)
{
	bool checkIfEmpty = true;

	for(int row(0); row<z.rows(); ++row)
		for(int col(0); col<z.cols(); ++col)
		{
			if(z(row,col) !=0)
			{
				checkIfEmpty = false;
				break;
			}
		}
	return checkIfEmpty;
}

mpcController::mpcController(void)
{
	U       = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	dU      = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	x       = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	xOld    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	dx      = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	xOb     = Eigen::Matrix<double,N_STATE_OB,1>::Zero();
	UOb     = Eigen::Matrix<double,N_INPUT_OB,1>::Zero();
	S       = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	Q       = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	R       = Eigen::Matrix<double,N_INPUT_MODEL,N_INPUT_MODEL>::Zero();
	A_model = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	B_model = Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL>::Zero();
	A_ob    = Eigen::Matrix<double,N_STATE_OB,N_STATE_OB>::Zero();
	B_ob    = Eigen::Matrix<double,N_STATE_OB,N_INPUT_OB>::Zero();

	//MPC parameters
	///////////////////////////////////////////////////////////////////
	//S
	S(0,0) = 8.0; //x
	S(1,1) = 8.0; //y
	S(2,2) = 8.0;//z
	S(3,3) = 3.0;//vx
	S(4,4) = 3.0;//vy
	S(5,5) = 3.0; //vz
	S(6,6) = 30.0;//yaw [rad]
	//Q
	Q(0,0) = 8.0; //x
	Q(1,1) = 8.0; //y
	Q(2,2) = 8.0;  //z
	Q(3,3) = 1.0;  //vx
	Q(4,4) = 1.0;  //vy
	Q(5,5) = 1.0;  //vz
	Q(6,6) = 15.0;  //yaw [rad]
	//R
	R(0,0) = 5000.0; //fx
	R(1,1) = 5000.0; //fy
	R(2,2) = 5.0; //yawRate [rad/s]
	R(3,3) = 5000.0; //fz

	//Drone model
	///////////////////////////////////////////////////////////////////
	//A_model
        double Am[N_STATE_MODEL][N_STATE_MODEL] = MODEL_A;
        for(int i=0;i<N_STATE_MODEL;i++)
        	for(int j=0;j<N_STATE_MODEL;j++)
        		A_model(i,j) = Am[i][j];

	//B_model
        double Bm[N_STATE_MODEL][N_INPUT_MODEL] = MODEL_B;
        for(int i=0;i<N_STATE_MODEL;i++)
        	for(int j=0;j<N_INPUT_MODEL;j++)
        		B_model(i,j) = Bm[i][j];

	//A_ob
	const double Aobs[N_STATE_OB][N_STATE_OB] = OBSERVER_A;
	 for(int i=0;i<N_STATE_OB;i++)
		for(int j=0;j<N_STATE_OB;j++)
			A_ob(i,j) = Aobs[i][j];

	//B_ob
	double Bobs[N_STATE_OB][N_INPUT_OB] = OBSERVER_B;
	for(int i=0;i<N_STATE_OB;i++)
		for(int j=0;j<N_INPUT_OB;j++)
			B_ob(i,j) = Bobs[i][j];

	dt = 0.01;	//sampling time [s]

	rx = 8000.0;	// collision avoidance penalty weight 3000
	ru = 600000.0;	// input constraint penalty weight 10000
	Rr = 0.4;	//radius of collision [m]
	alphaMax = 0.1745; 	// max angle with horizontal plane [rad] 10 [deg] = 0.1745 [rad]
	///////////////////////////////////////////////////////////////////
}

///////////////////////////////////////////////////////////////////////////
//制御演算初期化
void mpcController::ResetCont(StateData stateData)
{
	initFlag = 0;

	U     = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	dU    = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	x     = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	xOld  = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	dx    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	xOb  = Eigen::Matrix<double,N_STATE_OB,1>::Zero();
	UOb  = Eigen::Matrix<double,N_INPUT_OB,1>::Zero();

	// No reference to track
	xRef = stateData.xPos;
	yRef = stateData.yPos;
	zRef = -1.0 * stateData.zPos;

	// Reset observer
	xOb(0,0) = xRef;
	xOb(1,0) = yRef;
	xOb(2,0) = zRef;
	xOb(3,0) = stateData.xVel;
	xOb(4,0) = stateData.yVel;
	xOb(5,0) = -1.0 * stateData.zVel;

	// Input from Joystick
	U(0,0)    = stateData.rollFromJoystick;
	U(1,0)    = stateData.pitchFromJoystick;
	U(2,0)    = stateData.yawRateFromJoystick;
	U(3,0)    = stateData.thrustFromJoystick;
}

//////////////////////////////////////////////////////////////////////////////
//誘導制御演算(MPC)
Eigen::MatrixXd mpcController::mpcControllerLoop(StateData stateData,int newRefFlag ,double xRefNext,double yRefNext,double zRefNext)
{
	if(newRefFlag == 1)
	{
		// update reference
		xRef = xRefNext;
		yRef = yRefNext;
		zRef = zRefNext;
	}

	// old state, shifted with respect to reference
	xOld << 	xOb(0,0) - xRef,		//x = [x,y,z,vx,vy,vz,yaw]'
				xOb(1,0) - yRef,
				xOb(2,0) - zRef,
				xOb(3,0),
				xOb(4,0),
				xOb(5,0),
				stateData.yaw; // MUST BE IN RADIAN

	UOb << stateData.xPos,			//UOb = measurements and commands [x,y,z,vx,vy,vz,φ,θ,T]'
		stateData.yPos,
		-1.0 * stateData.zPos,
		stateData.xVel,
		stateData.yVel,
		-1.0 * stateData.zVel,
		-1.0*U(0,0)/(U(3,0)+MASS_GRAVITY),			//Fy to roll: roll ~ tan(roll) = -cos(pitch)*Fy/Fz
		U(1,0)/(U(3,0)+MASS_GRAVITY),				//Fx to pitch: pitch ~ tan(pitch) = Fx/Fz
		U(3,0);
	// State update
	xOb  = A_ob * xOb + B_ob * UOb;

	// Current state, shifted with respect to reference
	x << 	xOb(0,0) - xRef,		//x = [x,y,z,vx,vy,vz,yaw]'
			xOb(1,0) - yRef,
			xOb(2,0) - zRef,
			xOb(3,0),
			xOb(4,0),
			xOb(5,0),
			stateData.yaw; // MUST BE IN RADIAN

	//differentiate state
	dx  = (x-xOld) / dt;


	// if C/GMRES not initialized, initialize it.
	if(initFlag == 0){
		initFlag = 1;
		dx = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
		U  = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	}

	// FDGMRES
	dU = FDGMRES(U,x,dx);
	U += dU * dt;

	return	U;
}

////////////////////////////////////////////////////////////////////////////////////
//FDGMRES
Eigen::MatrixXd mpcController::FDGMRES(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U, Eigen::Matrix<double,N_STATE_MODEL,1> x,Eigen::Matrix<double,N_STATE_MODEL,1> dx)
{
	//FDGMRESパラメータ
	/////////////////////////////////////////////
	double	h = 0.1;		// FDGMRES step size
	double	zeta = 10.0;	// stabilizing matrix parameter
	/////////////////////////////////////////////

	int i,j;
	int k = 0;
	double rho = 0.0;
	double normVector;
	double w1,w2;

	// Initialization
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> F_Ux;		F_Ux = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> F_Uxdx;		F_Uxdx = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
//	Eigen::Matrix<double,N_INPUT_MODEL*N,1> F_UdUxdx;	F_UdUxdx = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> b;			b = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> r;			r = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::MatrixXd v(N_INPUT_MODEL*N,kmax);		    v = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,kmax+1,kmax+1> hh;				hh = Eigen::Matrix<double,kmax+1,kmax+1>::Zero();
	Eigen::Matrix<double,kmax+1,1> c;					c = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> s;					s = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> g;					g = Eigen::Matrix<double,kmax+1,1>::Zero();

	F_Ux  = CalcF(U, x);
	F_Uxdx = CalcF(U, x + dx * h);
	// Not implemented yet
//	F_UdUxdx = CalcF(U +dUHat, x + dx * h);

//	b = F_Ux*(-1.0)*zeta - (F_Uxdx - F_Ux)/h;
//	r = b - (F_UdUxdx - F_Uxdx)/h;
	// r = b only if dUHat = 0
	r = F_Ux*(-1.0)*zeta - (F_Uxdx - F_Ux)/h;

	// residual norm
	rho = 0.0;
	for(i = 0; i < N_INPUT_MODEL*N; i++)
		rho += pow(r(i,0),2.0);

	rho    = sqrt(rho);
	g(0,0) = rho;
	v = r;
	if (rho > 0)
		// normalization
		v = v/rho;

	// FDGMRES iteration
	while ((k<kmax) && (rho > 0))
	{
		//(a) Counter increase
		k += 1;
		//(b) Forward approximation of dF in direction of v_k
		Eigen::MatrixXd vTmp(N_INPUT_MODEL*N,1);

		vTmp = v;
		// Add a line. Beware, resize function, destruct previous content.
		v.resize(N_INPUT_MODEL*N,k+1);
		// Update v
		v << vTmp, (CalcF(U+vTmp*h,x+dx*h) - CalcF(U, x+dx*h))/h;

        // Orthogonal basis: Gramm-Schmidt process
		for(j = 0; j < k; j++){
			hh.block(j,k-1,1,1) = (v.block(0,0,N_INPUT_MODEL*N,1)).transpose()*v.block(0,k,N_INPUT_MODEL*N,1);
			vTmp.resize(N_INPUT_MODEL*N,2);
	                vTmp = v;
			v << vTmp.block(0,0,N_INPUT_MODEL*N,1),vTmp.block(0,k,N_INPUT_MODEL*N,1) - vTmp.block(0,j,N_INPUT_MODEL*N,1)*hh(j,k-1);
		}

		//(c)
		normVector = 0.0;
		for(i = 0; i < N_INPUT_MODEL*N; i++)
			normVector += pow(v(i,k),2.0);
		normVector      = sqrt(normVector);
		hh(k,k-1) = normVector;

		//(d)
		if(hh(k,k-1) != 0.0)
		{
			vTmp = v;
	        v.block(0,k,N_INPUT_MODEL*N,1) = vTmp.block(0,k,N_INPUT_MODEL*N,1)/hh(k,k-1);
		}

		//(e) Given rotations to solve problem
		if(k>1){
			for(i = 0; i < k-1; i++){
				w1 = c(i,0)*hh(i,k-1) - s(i,0)*hh(i+1,k-1);
				w2 = s(i,0)*hh(i,k-1) + c(i,0)*hh(i+1,k-1);
				hh(i,k-1)   = w1;
				hh(i+1,k-1) = w2;
			}
		}
		normVector = 0.0;
		for(i = k-1; i <=k; i++)
			normVector += pow(hh(i,k-1),2.0);
		normVector = sqrt(normVector);

		if(normVector != 0.0){
			c(k-1,0) = hh(k-1,k-1)/normVector;
			s(k-1,0) = -1.0*hh(k,k-1)/normVector;

			hh(k-1,k-1) = c(k-1,0)*hh(k-1,k-1)-s(k-1,0)*hh(k,k-1);
			hh(k,k-1)   = 0.0;

			w1 = c(k-1,0)*g(k-1,0) - s(k-1,0)*g(k,0);
			w2 = s(k-1,0)*g(k-1,0) + c(k-1,0)*g(k,0);

			g(k-1,0) = w1;
			g(k,0)   = w2;
		}

		//(f) Update residual norm
		rho = g(k,0);
		if(rho < 0) rho = -1.0 * rho;
	}

//	dU = v.block(0,0,N_INPUT_MODEL*N,k)*(hh.block(0,0,k,k)).inverse()*g.block(0,0,k,1);

	if(isEmpty(hh))	dU = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	else	dU = v.block(0,0,N_INPUT_MODEL*N,k)*(hh.block(0,0,k,k)).inverse()*g.block(0,0,k,1);

	return dU;
}

/////////////////////////////////////////////////////////////////////////
//Fの計算
Eigen::MatrixXd mpcController::CalcF(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U, Eigen::Matrix<double,N_STATE_MODEL,1> x)
{
	int i,j;
	double distanceRobotsSquared;

	Eigen::Matrix<double,N_STATE_MODEL,N+1> xStar;			xStar = Eigen::Matrix<double,N_STATE_MODEL,N+1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> uStar;			uStar = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N+1> lambdaStar;		lambdaStar = Eigen::Matrix<double,N_STATE_MODEL,N+1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,1> f;				f = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> dfdx;	dfdx = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL> dfdu;	dfdu = Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> F;				F = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();

	Eigen::Matrix<double,N_STATE_MODEL,1> robotObs;		robotObs = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,1> dHdx;			dHdx = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL,1> dHdu;			dHdu = Eigen::Matrix<double,N_INPUT_MODEL,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL,1> dPdu;			dPdu = Eigen::Matrix<double,N_INPUT_MODEL,1>::Zero();

	//init uStar
	for(i = 0; i < N_INPUT_MODEL*N; i++)
		uStar(i,0) = U(i,0);

	// init xStar
	for(i = 0; i < N_STATE_MODEL; i++)
		xStar(i,0) = x(i,0);

	// forward computation of state
	for(i = 0; i < N; i++)
	{
		f = A_model*xStar.block(0,i,N_STATE_MODEL,1) + B_model*uStar.block(N_INPUT_MODEL*i,0,N_INPUT_MODEL,1); //+g 変更後 //160721
		for(j = 0; j < N_STATE_MODEL; j++)
			xStar(j,i+1) = xStar(j,i)+f(j,0)*dt;
	}

	// backward computation of co-state variable

	dHdx = S*xStar.block(0,N,N_STATE_MODEL,1)*2.0;

	// init lambdaStar
	for(i = 0; i < N_STATE_MODEL; i++)
		lambdaStar(i,N) = dHdx(i,0);

	// Derivative of Hamiltonian with respect to x
	dfdx = A_model;
	// temp
	double obj_a[3] = {100.0, 100.0, 100.0}; //temp
	//temp
	for(i = N-1; i >= 0; i--){
		// collision penalty derivation with respect to x dp/dx
		for(j = 0; j < 2; j++)
			robotObs(j,0) = xStar(j,i)-obj_a[j];
		distanceRobotsSquared = 0.0;

		// squared of distance between two robots
		for(j = 0; j < N_STATE_MODEL; j++)
			distanceRobotsSquared += pow(robotObs(j,0),2.0);

		dHdx = (Q.transpose())*xStar.block(0,i,N_STATE_MODEL,1)*2.0 + (dfdx.transpose())*lambdaStar.block(0,i+1,N_STATE_MODEL,1) - robotObs*4.0*rx*std::max(0.0,pow(Rr,2.0)-distanceRobotsSquared);

		for(j = 0; j < N_STATE_MODEL; j++)
			lambdaStar(j,i) = lambdaStar(j,i+1) + dHdx(j,0) * dt;
	}

	// Derivative of Hamiltonian with respect to u
	dfdu = B_model;		//

	for(i = 0; i < N; i++)
	{
		dPdu(0,0) = uStar(N_INPUT_MODEL*i,0); //u1 = Fx
		dPdu(1,0) = uStar(N_INPUT_MODEL*i+1,0); //u2 = Fy
		// Derivative of input penalty function
		dPdu = dPdu*4.0*ru*std::max(0.0,pow(uStar(N_INPUT_MODEL*i,0),2.0)+pow(uStar(N_INPUT_MODEL*i+1,0),2.0)-pow(MASS_GRAVITY*alphaMax,2.0));
		dHdu = (R.transpose())*uStar.block(N_INPUT_MODEL*i,0,N_INPUT_MODEL,1)*2.0 + (dfdu.transpose())*lambdaStar.block(0,i+1,N_STATE_MODEL,1)*2.0 + dPdu;
		for(j = 0; j < N_INPUT_MODEL; j++)
			F(N_INPUT_MODEL*i+j,0) = dHdu(j,0);
	}




 	return F;
}
