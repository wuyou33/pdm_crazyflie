#ifndef GDNCONT_H
#define GDNCONT_H

#include <Eigen/Geometry>
#include "stateModelStructure.h"
#include "Param_MPC.h"

////////////////////////////////////////////////////////
class CGdnCont
{
public:
	CGdnCont(void);

	//制御演算
	void ResetCont(MPCData);
	Eigen::MatrixXd GdnCont(MPCData,int signal,double next_ref_x,double next_ref_y,double next_ref_z);

protected:
	
	int Initflg;

	double dt,obj_a[3],obj[3],ref_X,ref_Y,ref_Z,rx,ru,phi_max,Rr;
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> U;
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> dU;
	Eigen::Matrix<double,N_STATE_MODEL,1> U_ob;
	Eigen::Matrix<double,N_STATE_MODEL,1> X;
	Eigen::Matrix<double,N_STATE_MODEL,1> X_ob;
	Eigen::Matrix<double,N_STATE_MODEL,1> dX;

	Eigen::MatrixXd FDGMRES(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U,Eigen::Matrix<double,N_STATE_MODEL,1> X,Eigen::Matrix<double,N_STATE_MODEL,1> dX,double obj[3]);
	Eigen::MatrixXd CalcF(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U,Eigen::Matrix<double,N_STATE_MODEL,1> X,double obj[3]);

	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> S;
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> Q;
	Eigen::Matrix<double,N_INPUT_MODEL,N_INPUT_MODEL> R;
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> A_model;
	Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL> B_model;
	Eigen::Matrix<double,N_STATE_OB,N_STATE_OB> A_ob;
	Eigen::Matrix<double,N_STATE_OB,N_INPUT_OB> B_ob;

};

/*
CGdnCont::CGdnCont(void)
{	
	U       = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	dU      = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	U_ob    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	X       = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	dX      = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	X_ob    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	S       = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	Q       = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	R       = Eigen::Matrix<double,N_INPUT_MODEL,N_INPUT_MODEL>::Zero();
	A_model = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	B_model = Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL>::Zero();
	A_ob    = Eigen::Matrix<double,N_STATE_OB,N_STATE_OB>::Zero();
	B_ob    = Eigen::Matrix<double,N_STATE_OB,N_INPUT_OB>::Zero();

	//MPCパラメータ
	///////////////////////////////////////////////////////////////////
	//S
	S(0,0) = 500.0; //x
	S(1,1) = 500.0; //y
	S(2,2) = 1.0;//z
	S(3,3) = 100.0;//vx
	S(4,4) = 100.0;//vy
	S(5,5) = 1.0; //vz	
	S(6,6) = 1.0;//ax
	S(7,7) = 1.0;//ay
	S(8,8) = 1.0;//az
	//Q
	Q(0,0) = 150.0; //x	0,0,5.0
	Q(1,1) = 150.0; //y	1,1,5.0
	Q(2,2) = 1.0;  //z
	Q(3,3) = 100.0;  //vx
	Q(4,4) = 100.0;  //vy
	Q(5,5) = 1.0;  //vz
	Q(6,6) = 1.0;  //ax
	Q(7,7) = 1.0;  //ay
	Q(8,8) = 1.0;  //az
	//R
	R(0,0) = 1.0;
	R(1,1) = 1.0;
	R(2,2) = 1.0;
	R(3,3) = 1.0;

	//行列読み込み
	///////////////////////////////////////////////////////////////////
	//A_model
        double Am[N_STATE_MODEL][N_STATE_MODEL] = MODEL_A;
        for(int i=0;i<N_STATE_MODEL;i++)
		for(int j=0;j<N_STATE_MODEL;j++)	A_model(i,j) = Am[i][j];

	//B_model
        double Bm[N_STATE_MODEL][N_INPUT_MODEL] = MODEL_B;
        for(int i=0;i<N_STATE_MODEL;i++)
		for(int j=0;j<N_INPUT_MODEL;j++)	B_model(i,j) = Bm[i][j];

	//A_ob
	const double Aobs[N_STATE_OB][N_STATE_OB] = OBSERVER_A;
	 for(int i=0;i<N_STATE_OB;i++)
		for(int j=0;j<N_STATE_OB;j++)		A_ob(i,j) = Aobs[i][j];

	//B_ob
	double Bobs[N_STATE_OB][N_INPUT_OB] = OBSERVER_B;
	for(int i=0;i<N_STATE_OB;i++)
		for(int j=0;j<N_INPUT_OB;j++)		B_ob(i,j) = Bobs[i][j];

	dt = 0.01;	//サンプリングタイム

	obj_a[0] = 0.0;		obj_a[1] = 10.0;	obj_a[2] = 0.0;	//障害物位置（絶対位置）
	rx = 3000.0;	//状態拘束重み 3000
	ru = 5.0;	//入力拘束重み 10000
	Rr = 0.5;	//半径
	phi_max = 30.0;	//最大傾斜
	///////////////////////////////////////////////////////////////////
}

///////////////////////////////////////////////////////////////////////////
//制御演算初期化
void CGdnCont::ResetCont(MPCData mpcdata)
{	
	Initflg = 0;

	U     = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	dU    = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	X     = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	dX    = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	X_ob  = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	U_ob  = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	

	//目標値生成
	ref_X = mpcdata.xpos;
	ref_Y = mpcdata.ypos;
	ref_Z = -1.0 * mpcdata.zpos;

	//オブザーバ状態、入力初期化
	X_ob(0,0) = ref_X;
	X_ob(1,0) = ref_Y;
	X_ob(2,0) = ref_Z;
	X_ob(3,0) = mpcdata.xvel;
	X_ob(4,0) = mpcdata.yvel;
	X_ob(5,0) = -1.0 * mpcdata.zvel;

	U(0,0)    = mpcdata.phi;
	U(1,0)    = mpcdata.the;
	U(2,0)    = mpcdata.psi;
	U(3,0)    = mpcdata.thr;

	//障害物位置生成（相対位置）
	obj[0] = obj_a[0] - ref_X;
	obj[1] = obj_a[1] - ref_Y;
	obj[2] = obj_a[2] - ref_Z;
}

//////////////////////////////////////////////////////////////////////////////
//誘導制御演算(MPC)
Eigen::MatrixXd CGdnCont::GdnCont(MPCData mpcdata,int signal,double next_ref_x,double next_ref_y,double next_ref_z)
{
	if(1 == signal)
	{
		//目標値生成
		ref_X = next_ref_x;
		ref_Y = next_ref_y;
		ref_Z = next_ref_z;

		//障害物位置生成（相対位置）
		obj[0] = obj_a[0] - ref_X;
		obj[1] = obj_a[1] - ref_Y;
		obj[2] = obj_a[2] - ref_Z;
	}

	// 状態誤差計算
	X << 	X_ob(0,0) - ref_X,		//X = [x,y,z,vx,vy,vz,ax,ay,az]'
		X_ob(1,0) - ref_Y,
		X_ob(2,0) - ref_Z,
		X_ob(3,0),
		X_ob(4,0),
		X_ob(5,0),
		X_ob(6,0),
		X_ob(7,0),
		X_ob(8,0);

	//同一次元オブザーバ(20160907)
	U_ob << mpcdata.xpos,			//U_ob = [x,y,z,vx,vy,vz,φ,θ,T]'
		mpcdata.ypos,
		-1.0 * mpcdata.zpos,
		mpcdata.xvel,
		mpcdata.yvel,
		-1.0 * mpcdata.zvel,
		U(0,0),
		U(1,0),
		U(3,0);

	X_ob  = A_ob * X_ob + B_ob * U_ob;

	//dXの計算
	dX = X * (-1.0);
	dX += X;
	dX  = dX / dt;
	
	//初期入力の決定
	if(0 == Initflg){
		Initflg = 1;
		dX = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
		U  = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	}
	
	// FDGMRES
	dU = FDGMRES(U,X,dX,obj_a);
	U += dU * dt;

	return	U;
}

////////////////////////////////////////////////////////////////////////////////////
//FDGMRES
Eigen::MatrixXd CGdnCont::FDGMRES(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U, Eigen::Matrix<double,N_STATE_MODEL,1> X,Eigen::Matrix<double,N_STATE_MODEL,1> dX,double obj_a[3])
{
	//FDGMRESパラメータ
	/////////////////////////////////////////////
	double	h = 0.1;	//微小進み
	double	zeta = 10.0;	//ゼータ
	/////////////////////////////////////////////

	int i,j;
	int k = 0;
	double rho = 0.0;
	double bufd;
	double w1,w2;

	//行列の生成
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> buf;		buf = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> buf2;		buf2 = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> r;			r = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::MatrixXd v(N_INPUT_MODEL*N,kmax);		        v = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,kmax+1,kmax+1> hh;			hh = Eigen::Matrix<double,kmax+1,kmax+1>::Zero();
	Eigen::Matrix<double,kmax+1,1> c;			c = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> s;			s = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> g;			g = Eigen::Matrix<double,kmax+1,1>::Zero();
	
	buf  = CalcF(U, X,obj_a);
	buf2 = CalcF(U, X + dX * h,obj_a);

	r = buf*(-1.0)*zeta - (buf2 - buf)/h;
	rho = 0.0;
	
        for(i = 0; i < N_INPUT_MODEL*N; i++) rho += pow(r(i,0),2.0);
	
        rho    = sqrt(rho);
	g(0,0) = rho;	v = r/rho;
	
	//iteration
	while(k<kmax){
		//(a)
		k += 1;
		//(b)	
                Eigen::MatrixXd vtemp(N_INPUT_MODEL*N,1);

                vtemp = v;
                v.resize(N_INPUT_MODEL*N,2);
                v << vtemp, (CalcF(U+vtemp*h,X+dX*h,obj_a) - CalcF(U, X+dX*h,obj_a))/h;

		for(j = 0; j < k; j++){
			hh.block(j,k-1,1,1) = (v.block(0,0,N_INPUT_MODEL*N,1)).transpose()*v.block(0,k,N_INPUT_MODEL*N,1);	//160721
			vtemp.resize(N_INPUT_MODEL*N,2);
	                vtemp = v;
			v << vtemp.block(0,0,N_INPUT_MODEL*N,1),vtemp.block(0,k,N_INPUT_MODEL*N,1) - vtemp.block(0,j,N_INPUT_MODEL*N,1)*hh(j,k-1);
		}
		
		//(c)
		bufd = 0.0;
		for(i = 0; i < N_INPUT_MODEL*N; i++) bufd += pow(v(i,k),2.0);
		bufd      = sqrt(bufd);
		hh(k,k-1) = bufd;

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
		bufd = 0.0;
		for(i = k-1; i <=k; i++) bufd += pow(hh(i,k-1),2.0);
		bufd = sqrt(bufd);

		if(bufd != 0.0){
			c(k-1,0) = hh(k-1,k-1)/bufd;
			s(k-1,0) = -1.0*hh(k,k-1)/bufd;

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
Eigen::MatrixXd CGdnCont::CalcF(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U, Eigen::Matrix<double,N_STATE_MODEL,1> X,double obj_a[3])
{
	int i,j;
	double bufd;

	Eigen::Matrix<double,N_STATE_MODEL,N+1> xstar;		xstar = Eigen::Matrix<double,N_STATE_MODEL,N+1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> ustar;		ustar = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,1> f;			f = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N+1> lamda;		lamda = Eigen::Matrix<double,N_STATE_MODEL,N+1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> dfdx;		dfdx = Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,1> buf;			buf = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,1> buf2;			buf2 = Eigen::Matrix<double,N_STATE_MODEL,1>::Zero();
	Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL> dfdu;		dfdu = Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> F;			F = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL,1> buf3;			buf3 = Eigen::Matrix<double,N_INPUT_MODEL,1>::Zero();
	Eigen::Matrix<double,N_INPUT_MODEL,1> buf4;			buf4 = Eigen::Matrix<double,N_INPUT_MODEL,1>::Zero();

	//入力系列の生成
	for(i = 0; i < N_INPUT_MODEL*N; i++){
		ustar(i,0) = U(i,0);
	}

	//状態系列の生成		160713 
	for(i = 0; i < N_STATE_MODEL; i++){
		xstar(i,0) = X(i,0);
	}

	for(i = 0; i < N; i++){
		//for(j = 0; j < 3; j++) f(j,0) = xstar(j+3,j);
		//f(3,0) = -kxy*(la+lb*sin(ustar(N_INPUT_MODEL*i+3,0)))*xstar(3,i) + ustar(N_INPUT_MODEL*i,1) / m;
		//f(4,0) = -kxy*(la+lb*cos(ustar(N_INPUT_MODEL*i+3,0)))*xstar(N_INPUT_MODEL,i) + ustar(N_INPUT_MODEL*i+1,0) / m;
		//f(5,0) = -kz*xstar(5,i) + ustar(N_INPUT_MODEL*i+2,0) / m; // + m*g		//モデルを変更

		f = A_model*xstar.block(0,i,N_STATE_MODEL,1) + B_model*ustar.block(N_INPUT_MODEL*i,0,N_INPUT_MODEL,1); //+g 変更後 //160721

		for(j = 0; j < N_STATE_MODEL; j++) xstar(j,i+1) = xstar(j,i)+f(j,0)*dt;
	}

	//ラグランジュ乗数の生成
	buf2 = S*xstar.block(0,N,N_STATE_MODEL,1)*2.0;		//160721

	for(i = 0; i < N_STATE_MODEL; i++) lamda(i,N) = buf2(i,0);

		//df/dx	160713 モデル変更
		//for(j = 0; j < 3; j++) dfdx(j,j+3) = 1.0;
		//dfdx(3,3) = -kxy*(la+lb*sin(ustar(N_INPUT_MODEL*i+3,0))/m);
		//dfdx(4,4) = -kxy*(la+lb*cos(ustar(N_INPUT_MODEL*i+3,0))/m);
		//dfdx(5,5) = -kz/m;
	
	dfdx = A_model;		//変更後
	for(i = N-1; i >= 0; i--){
		//dp/dx
		for(j = 0; j < 2; j++) buf(j,0) = xstar(j,i)-obj_a[j];	//bufは障害物との相対位置		
		bufd = 0.0;
		
		for(j = 0; j < N_STATE_MODEL; j++) bufd += pow(buf(j,0),2.0);

		//-buf*2.0*rx/(0.0001-(pow(Rr,2.0)-bufd))//状態拘束log
		//-buf*4.0*max(0,pow(Rr,2.0)-bufd)//状態拘束max
		buf2 = (Q.transpose())*xstar.block(0,i,N_STATE_MODEL,1)*2.0 + (dfdx.transpose())*lamda.block(0,i+1,N_STATE_MODEL,1) - buf*4.0*rx*std::max(0.0,pow(Rr,2.0)-bufd);//状態拘束max  //160721

		for(j = 0; j < N_STATE_MODEL; j++) lamda(j,i) = lamda(j,i+1) + buf2(j,0) * dt;
	}

	//Fの計算
	dfdu = B_model;		//変更後
	for(i = 0; i < N; i++){
		//入力拘束
		buf4(0,0) = ustar(N_INPUT_MODEL*i,0);
		buf4(1,0) = ustar(N_INPUT_MODEL*i+1,0);
		buf4 = buf4*4.0*ru*std::max(0.0,pow(ustar(N_INPUT_MODEL*i,0),2.0)+pow(ustar(N_INPUT_MODEL*i+1,0),2.0)-pow(phi_max,2.0));

		buf3 = (R.transpose())*ustar.block(N_INPUT_MODEL*i,0,N_INPUT_MODEL,1)*2.0 + (dfdu.transpose())*lamda.block(0,i+1,N_STATE_MODEL,1)*2.0 + buf4;  //160721
		for(j = 0; j < N_INPUT_MODEL; j++)	F(N_INPUT_MODEL*i+j,0) = buf3(j,0);
	}
 	return F;
}
*/

#endif
