#include <ros/ros.h> //Debug
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
	UOb    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	x       = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	dx      = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	xOb    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
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
	S(0,0) = 500.0; //x
	S(1,1) = 500.0; //y
	S(2,2) = 1.0;//z
	S(3,3) = 100.0;//vx
	S(4,4) = 100.0;//vy
	S(5,5) = 1.0; //vz
	S(6,6) = 1.0;//yaw
	//Q
	Q(0,0) = 150.0; //x
	Q(1,1) = 150.0; //y
	Q(2,2) = 1.0;  //z
	Q(3,3) = 100.0;  //vx
	Q(4,4) = 100.0;  //vy
	Q(5,5) = 1.0;  //vz
	Q(6,6) = 1.0;  //yaw
	//R
	R(0,0) = 1.0; //fx
	R(1,1) = 1.0; //fy
	R(2,2) = 1.0; //fz
	R(3,3) = 1.0; //yawRate

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

	dt = 0.01;	//sampling time

	rx = 3000.0;	// collision avoidance penalty weight 3000
	ru = 5.0;	// input constraint penalty weight 10000
	Rr = 0.5;	//radius of collision
	alphaMax = 30.0;	// max angle with horizontal plane
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
	dx    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	xOb  = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	UOb  = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();

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

	// State, shifted to reference
	x << 	xOb(0,0) - xRef,		//x = [x,y,z,vx,vy,vz,ax,ay,az]'
		xOb(1,0) - yRef,
		xOb(2,0) - zRef,
		xOb(3,0),
		xOb(4,0),
		xOb(5,0),
		xOb(6,0),
		xOb(7,0),
		xOb(8,0);

	// Observer update (20160907)
	UOb << stateData.xPos,			//UOb = [x,y,z,vx,vy,vz,φ,θ,T]'
		stateData.yPos,
		-1.0 * stateData.zPos,
		stateData.xVel,
		stateData.yVel,
		-1.0 * stateData.zVel,
		U(0,0),
		U(1,0),
		U(3,0);

	xOb  = A_ob * xOb + B_ob * UOb;

	//differentiate state
	dx = x * (-1.0);
	dx += x;
	dx  = dx / dt;

	// if C/GMRES not initialized, initialize it.
	if(initFlag == 0){
		initFlag = 1;
		dx = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
		U  = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
		ROS_INFO("Init");
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
	double	h = 0.1;	// FDGMRES step size
	double	zeta = 10.0;	// stabilizing matrix parameter
	/////////////////////////////////////////////

	int i,j;
	int k = 0;
	double rho = 0.0;
	double distanceRobotsSquared;
	double w1,w2;

	// Initialization
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> buf;		buf = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> buf2;		buf2 = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> r;			r = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::MatrixXd v(N_INPUT_MODEL*N,kmax);		        v = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,kmax+1,kmax+1> hh;			hh = Eigen::Matrix<double,kmax+1,kmax+1>::Zero();
	Eigen::Matrix<double,kmax+1,1> c;			c = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> s;			s = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> g;			g = Eigen::Matrix<double,kmax+1,1>::Zero();

	buf  = CalcF(U, x);
	buf2 = CalcF(U, x + dx * h);

	r = buf*(-1.0)*zeta - (buf2 - buf)/h;
	rho = 0.0;
	for(i = 0; i < N_INPUT_MODEL*N; i++)
		rho += pow(r(i,0),2.0);

	rho    = sqrt(rho);
	g(0,0) = rho;	v = r/rho;

	// FDGMRES iteration
	while(k<kmax){
		//(a)
		k += 1;
		//(b)
                Eigen::MatrixXd vtemp(N_INPUT_MODEL*N,1);

                vtemp = v;
                v.resize(N_INPUT_MODEL*N,2);
                v << vtemp, (CalcF(U+vtemp*h,x+dx*h) - CalcF(U, x+dx*h))/h;

		for(j = 0; j < k; j++){
			hh.block(j,k-1,1,1) = (v.block(0,0,N_INPUT_MODEL*N,1)).transpose()*v.block(0,k,N_INPUT_MODEL*N,1);	//160721
			vtemp.resize(N_INPUT_MODEL*N,2);
	                vtemp = v;
			v << vtemp.block(0,0,N_INPUT_MODEL*N,1),vtemp.block(0,k,N_INPUT_MODEL*N,1) - vtemp.block(0,j,N_INPUT_MODEL*N,1)*hh(j,k-1);
		}

		//(c)
		distanceRobotsSquared = 0.0;
		for(i = 0; i < N_INPUT_MODEL*N; i++) distanceRobotsSquared += pow(v(i,k),2.0);
		distanceRobotsSquared      = sqrt(distanceRobotsSquared);
		hh(k,k-1) = distanceRobotsSquared;

		//(d)
		if(hh(k,k-1) != 0.0) {
		  vtemp = v;
	          v.block(0,k,N_INPUT_MODEL*N,1) = vtemp.block(0,k,N_INPUT_MODEL*N,1)/hh(k,k-1);
		}

		//(e)
		if(k>1){
			for(i = 0; i < k-1; i++){
				w1 = c(i,0)*hh(i,k-1) - s(i,0)*hh(i+1,k-1);
				w2 = s(i,0)*hh(i,k-1) + c(i,0)*hh(i+1,k-1);
				hh(i,k-1)   = w1;
				hh(i+1,k-1) = w2;
			}
		}
		distanceRobotsSquared = 0.0;
		for(i = k-1; i <=k; i++) distanceRobotsSquared += pow(hh(i,k-1),2.0);
		distanceRobotsSquared = sqrt(distanceRobotsSquared);

		if(distanceRobotsSquared != 0.0){
			c(k-1,0) = hh(k-1,k-1)/distanceRobotsSquared;
			s(k-1,0) = -1.0*hh(k,k-1)/distanceRobotsSquared;

			hh(k-1,k-1) = c(k-1,0)*hh(k-1,k-1)-s(k-1,0)*hh(k,k-1);
			hh(k,k-1)   = 0.0;

			w1 = c(k-1,0)*g(k-1,0) - s(k-1,0)*g(k,0);
			w2 = s(k-1,0)*g(k-1,0) + c(k-1,0)*g(k,0);

			g(k-1,0) = w1;
			g(k,0)   = w2;
		}

		//(f)
		//rho = g(k,0);
		//if(rho < 0) rho = -1.0 * rho;
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

	Eigen::Matrix<double,N_STATE_MODEL,N+1> xStar;		xStar = Eigen::Matrix<double,N_STATE_MODEL,N+1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> uStar;		uStar = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N+1> lambdaStar;		lambdaStar = Eigen::Matrix<double,N_STATE_MODEL,N+1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,1> f;			f = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> dfdx;		dfdx = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL> dfdu;		dfdu = Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> F;			F = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();

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

	for(i = 0; i < N; i++)
	{
		// forward computation of state
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
	double obj_a[3] = {0.0, 0.0, 0.0}; //temp
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
		dPdu = dPdu*4.0*ru*std::max(0.0,pow(uStar(N_INPUT_MODEL*i,0),2.0)+pow(uStar(N_INPUT_MODEL*i+1,0),2.0)-pow(alphaMax,2.0));

		dHdu = (R.transpose())*uStar.block(N_INPUT_MODEL*i,0,N_INPUT_MODEL,1)*2.0 + (dfdu.transpose())*lambdaStar.block(0,i+1,N_STATE_MODEL,1)*2.0 + dPdu;
		for(j = 0; j < N_INPUT_MODEL; j++)
			F(N_INPUT_MODEL*i+j,0) = dHdu(j,0);
	}

 	return F;
}
