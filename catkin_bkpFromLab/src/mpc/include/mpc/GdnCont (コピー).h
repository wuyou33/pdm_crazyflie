#pragma once
#include <ros/ros.h>
#include <Eigen/Core>
#include <Eigen/Geometry>

//MPCステップ関数
#define N 20
#define NUM_STATE 9
#define NUM_IMPUT 4
#define kmax 1	//イタレーション回数 イタレーション回数変更時は下のv,v2などの計算を変更しなければならない

class CGdnCont
{
public:
	CGdnCont(void);

	//制御演算
	void ResetCont(double pos[3],double vel[3]);
	Eigen::MatrixXd GdnCont(double pos[3], double vel[3],int signal,double next_ref_x,double next_ref_y,double next_ref_z);

protected:
	
	int SW;
	double dt,obj_a[3],obj[3],ref_X,ref_Y,ref_Z,rx,ru,phi_max,Rr;
	Eigen::Matrix<double,NUM_IMPUT*N,1> U;
	Eigen::Matrix<double,NUM_IMPUT*N,1> dU;
	Eigen::Matrix<double,NUM_STATE,1> U_ob;
	Eigen::Matrix<double,NUM_STATE,1> X;
	Eigen::Matrix<double,NUM_STATE,1> X_ob;
	Eigen::Matrix<double,NUM_STATE,1> Xe_ob;
	Eigen::Matrix<double,NUM_STATE,1> dX;

	Eigen::MatrixXd FDGMRES(Eigen::Matrix<double,NUM_IMPUT*N,1> U,Eigen::Matrix<double,NUM_STATE,1> X,Eigen::Matrix<double,NUM_STATE,1> dX,double obj[3]);
	Eigen::MatrixXd CalcF(Eigen::Matrix<double,NUM_IMPUT*N,1> U,Eigen::Matrix<double,NUM_STATE,1> X,double obj[3]);

	Eigen::Matrix<double,NUM_STATE,NUM_STATE> S;
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> Q;
	Eigen::Matrix<double,NUM_IMPUT,NUM_IMPUT> R;
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> A_model;
	Eigen::Matrix<double,NUM_STATE,NUM_IMPUT> B_model;
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> A_ob;
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> B_ob;

};

CGdnCont::CGdnCont(void)
{	
	U       = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	dU      = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	U_ob    = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	X       = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	dX      = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	Xe_ob   = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	X_ob    = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	S       = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::Zero();
	Q       = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::Zero();
	R       = Eigen::Matrix<double,NUM_IMPUT,NUM_IMPUT>::Zero();
	A_model = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::Zero();
	B_model = Eigen::Matrix<double,NUM_STATE,NUM_IMPUT>::Zero();
	A_ob    = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::Zero();
	B_ob    = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::Zero();

	//MPCパラメータ
	///////////////////////////////////////////////////////////////////
	//SQR 160929変更
/*
	//S
	S(0,0) = 2500000.0; //x
	S(1,1) = 2500000.0; //y
	S(2,2) = 5000000.0;//z
	S(3,3) = 1000.0;//vx
	S(4,4) = 1000.0;//vy
	S(5,5) = 100000.0; //vz	
	S(6,6) = 1.0;//ax
	S(7,7) = 1.0;//ay
	S(8,8) = 1.0;//az
	//Q
	Q(0,0) = 25000000.0; //x	0,0,5.0
	Q(1,1) = 25000000.0; //y	1,1,5.0
	Q(2,2) = 5000000.0;  //z
	Q(3,3) = 10.0;  //vx
	Q(4,4) = 10.0;  //vy
	Q(5,5) = 100000.0;  //vz
	Q(6,6) = 1.0;  //ax
	Q(7,7) = 1.0;  //ay
	Q(8,8) = 1.0;  //az
	//R
	R(0,0) = 1.0;
	R(1,1) = 1.0;
	R(2,2) = 1.0;
	R(3,3) = 1.0;
*/

	//S
	S(0,0) = 2000000.0; //x
	S(1,1) = 2000000.0; //y
	S(2,2) = 1.0;//z
	S(3,3) = 1.0;//vx
	S(4,4) = 1.0;//vy
	S(5,5) = 1.0; //vz	
	S(6,6) = 1.0;//ax
	S(7,7) = 1.0;//ay
	S(8,8) = 1.0;//az
	//Q
	Q(0,0) = 20000000.0; //x	0,0,5.0
	Q(1,1) = 20000000.0; //y	1,1,5.0
	Q(2,2) = 1.0;  //z
	Q(3,3) = 1.0;  //vx
	Q(4,4) = 1.0;  //vy
	Q(5,5) = 1.0;  //vz
	Q(6,6) = 1.0;  //ax
	Q(7,7) = 1.0;  //ay
	Q(8,8) = 1.0;  //az
	//R
	R(0,0) = 1.0;
	R(1,1) = 1.0;
	R(2,2) = 1.0;
	R(3,3) = 1.0;

/*	S(0,0) = 350000.0; //x
	S(1,1) = 350000.0; //y
	S(2,2) = 19000000000.0;//z
	S(3,3) = 10000.0;//vx
	S(4,4) = 10000.0;//vy
	S(5,5) = 1000.0; //vz	
	S(6,6) = 1000.0;//ax
	S(7,7) = 1000.0;//ay
	S(8,8) = 1000.0;//az
	//Q
	Q(0,0) = 350000.0; //x	0,0,5.0
	Q(1,1) = 350000.0; //y	1,1,5.0
	Q(2,2) = 19000000000.0;  //z
	Q(3,3) = 10000.0;  //vx
	Q(4,4) = 10000.0;  //vy
	Q(5,5) = 1000.0;  //vz
	Q(6,6) = 1000.0;  //ax
	Q(7,7) = 1000.0;  //ay
	Q(8,8) = 1000.0;  //az
	//R
	R(0,0) = 100.0;
	R(1,1) = 100.0;
	R(2,2) = 1.0;
	R(3,3) = 200.0;
*/
/*	//S
	S(0,0) = 840000.0; //x
	S(1,1) = 840000.0; //y
	S(2,2) = 47000000000.0;//z
	S(3,3) = 90000.0;//vx
	S(4,4) = 90000.0;//vy
	S(5,5) = 850000.0; //vz	
	S(6,6) = 15000.0;//ax
	S(7,7) = 15000.0;//ay
	S(8,8) = 600000000.0;//az
	//Q
	Q(0,0) = 500000.0; //x	0,0,5.0
	Q(1,1) = 500000.0; //y	1,1,5.0
	Q(2,2) = 30000000000.0;  //z
	Q(3,3) = 100000.0;  //vx
	Q(4,4) = 100000.0;  //vy
	Q(5,5) = 800000.0;  //vz
	Q(6,6) = 15000.0;  //ax
	Q(7,7) = 15000.0;  //ay
	Q(8,8) = 500000000.0;  //az
	//R
	R(0,0) = 100.0;
	R(1,1) = 100.0;
	R(2,2) = 1.0;
	R(3,3) = 200.0;
*/
	//モデルパラメータ
	///////////////////////////////////////////////////////////////////
	//A_model
	A_model(0,3) = 1.0;	A_model(0,6) = 0.0;
	A_model(1,4) = 1.0;	A_model(1,7) = 0.0;
	A_model(2,5) = 1.0;	A_model(2,8) = 0.0;
	A_model(3,3) = 0.0;	A_model(3,6) = 1.0;
	A_model(4,4) = 0.0;	A_model(4,7) = 1.0;
	A_model(5,5) = 0.0;	A_model(5,8) = 1.0;
	A_model(6,3) = -4.1649;	A_model(6,6) = -2.7347;
	A_model(7,4) = -4.1649;	A_model(7,7) = -2.7347;
	A_model(8,5) = -4.3403;	A_model(8,8) = -3.8333;

	//B_model
	B_model(6,0) = 0.4165;
	B_model(7,1) = 0.4165;
	B_model(8,3) = 0.00086806;

	//A_ob
	A_ob(0,0) = 0.9903;		A_ob(0,1) = 0.0020;	A_ob(0,2) = 0.0000099501; 
	A_ob(1,0) = -0.0077;		A_ob(1,1) = 0.9516;	A_ob(1,2) = 0.0096; 
	A_ob(2,0) = 0.0028;		A_ob(2,1) = -0.1574;	A_ob(2,2) = 0.9722;
	A_ob(3,3) = 0.9903;		A_ob(3,4) = 0.0020;	A_ob(3,5) = 0.0000099501; 
	A_ob(4,3) = -0.0077;		A_ob(4,4) = 0.9516;	A_ob(4,5) = 0.0096; 
	A_ob(5,3) = 0.0028;		A_ob(5,4) = -0.1574;	A_ob(5,5) = 0.9728;
	A_ob(6,6) = 0.9985;		A_ob(6,7) = 0.0099;	A_ob(6,8) = 0.000048765;
	A_ob(7,6) = -0.00011549;	A_ob(7,7) = 0.9996;	A_ob(7,8) = 0.0098;
	A_ob(8,6) = 0.00012614;		A_ob(8,7) = -0.0426;	A_ob(8,8) = 0.9622;
 

	//B_ob
	B_ob(0,0) = 0.0097;		B_ob(0,1) = 0.0080;			B_ob(0,2) = 0.000000013914;
	B_ob(1,0) = 0.0077;		B_ob(1,1) = 0.0481;			B_ob(1,2) = 0.000020302;
	B_ob(2,0) = -0.0028;		B_ob(2,1) = 0.1163;			B_ob(2,2) = 0.0041;
	B_ob(3,3) = 0.0097;		B_ob(3,4) = 0.0080;			B_ob(3,5) = 0.000000013914;
	B_ob(4,3) = 0.0077;		B_ob(4,4) = 0.0481;			B_ob(4,5) = 0.000020302;
	B_ob(5,3) = -0.0028;		B_ob(5,4) = 0.1163;			B_ob(6,5) = 0.0041;
	B_ob(6,6) = 0.0015;		B_ob(6,7) = 0.00011685;			B_ob(6,8) = 0.00000000014157;
	B_ob(7,6) = 0.00011549;		B_ob(7,7) = 0.00014548;			B_ob(7,8) = 0.000000042850;
	B_ob(8,6) = -0.00012614;	B_ob(8,7) = -0.0000014092;		B_ob(8,8) = 0.0000085157;

	dt = 0.01;	//サンプリングタイム
	obj_a[0] = 0.0;		obj_a[1] = 10.0;	obj_a[2] = 0.0;	//障害物位置（絶対位置）
	rx = 3000.0;	//状態拘束重み 3000
	ru = 5.0;	//入力拘束重み 10000
	Rr = 0.5;	//半径
	phi_max = 10.0*3.14/180;	//最大傾斜
	///////////////////////////////////////////////////////////////////
}

/*
CGdnCont::CGdnCont(void)
{
	int i;

	this->U.SetSize(4*N,1);	this->U.SetAllZero();
	this->dU.SetSize(4*N,1);	this->dU.SetAllZero();
	this->X.SetSize(6,1);	this->X.SetAllZero();
	this->dX.SetSize(6,1);	this->dX.SetAllZero();

	this->S.SetSize(6,6);	this->S.SetAllZero();
	this->Q.SetSize(6,6);	this->Q.SetAllZero();
	this->R.SetSize(4,4);	this->R.SetAllZero();

	// MPCパラメータ
	///////////////////////////////////////////////
	// S
	this->S.SetAt(0,0,60.0);//x
	this->S.SetAt(1,1,60.0);//y
	this->S.SetAt(2,2,200.0);//z
	this->S.SetAt(3,3,500.0);//vx
	this->S.SetAt(4,4,500.0);//vy
	this->S.SetAt(5,5,10.0);//vz
	// Q
	this->Q.SetAt(0,0,20.0);//x　　0,0,5.0
	this->Q.SetAt(1,1,20.0);//y　　1,1,5.0
	this->Q.SetAt(2,2,5.0);//z
	this->Q.SetAt(3,3,2.0);//vx
	this->Q.SetAt(4,4,2.0);//vy
	this->Q.SetAt(5,5,2.0);//vz
	// R
	for(i = 0; i < 4; i++) this->R.SetAt(i,i,200.0);

	this->dt = 0.1;	// サンプリングタイム
	this->obj_a[0] = 0.0;	this->obj_a[1] = -0.2;	this->obj_a[2] = 1.3;	// 障害物位置（絶対位置）
	this->rx = 0.0;	//状態拘束重み 3000
	this->ru = 10000.0;	//入力拘束重み 10000
	this->Rr = 0.4;	//半径
	this->phi_max = 10.0*3.14/180;	//最大傾斜角
	///////////////////////////////////////////////
}
*/

///////////////////////////////////////////////////////////////////////////
//制御演算初期化
void CGdnCont::ResetCont(double pos[3],double vel[3])
{	
	SW = 0;

	U     = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	dU    = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	X     = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	dX    = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	Xe_ob = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	X_ob  = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	U_ob  = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	

	//目標値生成
	ref_X = pos[0];
	ref_Y = pos[1];
	ref_Z = -1.0*pos[2];//160726
			//160713//160719

	X_ob << pos[0],
		 vel[0],
		 0,
		 pos[1],
		 vel[1],
		 0,
		 pos[2],
		 vel[2],
		 0;

	//障害物位置生成（相対位置）
	obj[0] = obj_a[0] - ref_X;
	obj[1] = obj_a[1] - ref_Y;
	obj[2] = obj_a[2] - ref_Z;
}

/*
//////////////////////////////////////////////////////////////////////////
// 制御演算初期化
void CGdnCont::ResetCont(SensorData c_SensorData)
{
	this->SW = 0;

	this->U.SetAllZero();
	this->dU.SetAllZero();
	this->X.SetAllZero();
	this->dX.SetAllZero();

	// 目標値生成
	this->m_RefData.X = c_SensorData.PosX;
	this->m_RefData.Y = c_SensorData.PosY;
	this->m_RefData.Z = - c_SensorData.PosZ;
	this->m_RefData.roll = 0.0;
	this->m_RefData.pitch = 0.0;
	this->m_RefData.yaw = 0.0;
	this->m_RefData.Fx = 0.0;
	this->m_RefData.Fy = 0.0;
	this->m_RefData.Fz = 0.0;
	this->m_RefData.thrust = 0.264*9.81;

	// 障害物位置生成（相対位置）
	this->obj[0] = this->obj_a[0] - this->m_RefData.X;
	this->obj[1] = this->obj_a[1] - this->m_RefData.Y;
	this->obj[2] = this->obj_a[2] - this->m_RefData.Z;

}
*/

//////////////////////////////////////////////////////////////////////////////
//誘導制御演算(MPC)
Eigen::MatrixXd CGdnCont::GdnCont(double pos[3],double vel[3],int signal,double next_ref_x,double next_ref_y,double next_ref_z)
{
	if(1 == signal)
	{
		//目標値生成
		ref_X = next_ref_x;	//コマンドラインからの入力はここに入れる
		ref_Y = next_ref_y;
		ref_Z = next_ref_z;
		//障害物位置生成（相対位置）
		obj[0] = obj_a[0] - ref_X;
		obj[1] = obj_a[1] - ref_Y;
		obj[2] = obj_a[2] - ref_Z;
	}

	//状態の更新
	dX = X * (-1.0);

	//std::cout << "dX" << std::endl << dX << std::endl << std::endl;

////////同一次元オブザーバ(20160907)
	U_ob << pos[0],			//U_ob = [x,vx,φ,y,vy,θ,z,vz,T]'
		vel[0],
		U(0,0),
		pos[1],
		vel[1],
		U(1,0),
		-1.0 * pos[2],
		vel[2],
		U(3,0);

	Xe_ob = X_ob;	//Xe_ob,X_ob = [x,vx,ax,y,vy,ay,z,vz,az]'
	X_ob  = A_ob * X_ob + B_ob * U_ob;

	X << Xe_ob(0,0) - ref_X,		//X = [x,y,z,vx,vy,vz,ax,ay,az]'
	     Xe_ob(3,0) - ref_Y,
	     Xe_ob(6,0) - ref_Z,
	     Xe_ob(1,0),
	     Xe_ob(4,0),
	     Xe_ob(7,0),
	     Xe_ob(2,0),
	     Xe_ob(5,0),
	     Xe_ob(8,0);
////////

	dX += X;
	dX  = dX / dt;
	
	//初期入力の決定
	if(0 == SW){
		SW = 1;
		dX = Eigen::Matrix<double,NUM_STATE,1>::Zero();
		U  = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	}
	
	// FDGMRES
	dU = FDGMRES(U,X,dX,obj_a);

	U += dU * dt;
////////オブザーバデバッグ用
	Eigen::Matrix<double,NUM_IMPUT * N + NUM_STATE + NUM_STATE,1> U_temp;
	U_temp << U, 
		  Xe_ob,
		  U_ob;

	return	U_temp;
////////

//	return U;	//オブザーバのデバッグが終わればこっちに戻す
}

/*
//////////////////////////////////////////////////////////////////////////
// 誘導制御演算(MPC)
void CGdnCont::GdnCont(RefNext c_RefNext, SensorData c_SensorData)
{
	// 目標値生成
	if(c_RefNext.SW == 1){
		this->m_RefData.X = c_RefNext.X;
		this->m_RefData.Y = c_RefNext.Y;
		this->m_RefData.Z = c_RefNext.Z;
		// 障害物位置生成（相対位置）
		this->obj[0] = this->obj_a[0] - this->m_RefData.X;
		this->obj[1] = this->obj_a[1] - this->m_RefData.Y;
		this->obj[2] = this->obj_a[2] - this->m_RefData.Z;
	}

	//時間計測
	timeBeginPeriod(1);
	int bef = timeGetTime();

	// 状態の更新
	this->dX = this->X * (-1.0);
	this->X.SetAt(0,0,c_SensorData.PosX - this->m_RefData.X);
	this->X.SetAt(1,0,c_SensorData.PosY - this->m_RefData.Y);
	this->X.SetAt(2,0,-c_SensorData.PosZ - this->m_RefData.Z);
	this->X.SetAt(3,0,c_SensorData.Vx);
	this->X.SetAt(4,0,c_SensorData.Vy);
	this->X.SetAt(5,0,c_SensorData.Vz);
	this->dX += this->X;
	this->dX = this->dX / this->dt;

	// 初期入力の決定
	if(this->SW == 0){
		this->SW = 1;
		this->dX.SetAllZero();	//最初だけゼロ
		this->U.SetAllZero();//本来計算あり
	}

	// FDGMRES	
	this->FDGMRES();
	this->U += this->dU * this->dt;

	// 制御入力生成（外力ベクトルto姿勢と推力変換）
	this->m_RefData.Fx  = this->U.ElementAt(0,0);
	this->m_RefData.Fy  = this->U.ElementAt(1,0);
	this->m_RefData.Fz  = this->U.ElementAt(2,0)-0.264*9.81;	if(this->U.ElementAt(2,0) >= 0.264*9.81) this->m_RefData.Fz = -0.0001;	//目標姿勢生成にFzが0はダメ
	this->m_RefData.yaw = this->U.ElementAt(3,0);
	this->F2Att();

	//時間計測
	this->mpctime = timeGetTime() - bef;
	timeEndPeriod(1);
	
}
*/

////////////////////////////////////////////////////////////////////////////////////
//FDGMRES
Eigen::MatrixXd CGdnCont::FDGMRES(Eigen::Matrix<double,NUM_IMPUT*N,1> U, Eigen::Matrix<double,NUM_STATE,1> X,Eigen::Matrix<double,NUM_STATE,1> dX,double obj_a[3])
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
	Eigen::Matrix<double,NUM_IMPUT*N,1> buf;		buf = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	Eigen::Matrix<double,NUM_IMPUT*N,1> buf2;		buf2 = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	Eigen::Matrix<double,NUM_IMPUT*N,1> r;			r = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	Eigen::MatrixXd v(NUM_IMPUT*N,kmax);		        v = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	Eigen::Matrix<double,kmax+1,kmax+1> hh;		hh = Eigen::Matrix<double,kmax+1,kmax+1>::Zero();
	Eigen::Matrix<double,kmax+1,1> c;			c = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> s;			s = Eigen::Matrix<double,kmax+1,1>::Zero();
	Eigen::Matrix<double,kmax+1,1> g;			g = Eigen::Matrix<double,kmax+1,1>::Zero();
	
	buf  = CalcF(U, X,obj_a);
	buf2 = CalcF(U, X + dX * h,obj_a);

	r = buf*(-1.0)*zeta - (buf2 - buf)/h;
	rho = 0.0;
	
        for(i = 0; i < NUM_IMPUT*N; i++) rho += pow(r(i,0),2.0);
	
        rho    = sqrt(rho);
	g(0,0) = rho;
	v      = r/rho;
	
	//iteration
	while(k<kmax){
		//(a)
		k += 1;
		//(b)	
                Eigen::MatrixXd vtemp(NUM_IMPUT*N,1);

                vtemp = v;
                v.resize(NUM_IMPUT*N,2);
                v << vtemp, (CalcF(U+vtemp*h,X+dX*h,obj_a) - CalcF(U, X+dX*h,obj_a))/h;

		for(j = 0; j < k; j++){
			hh.block(j,k-1,1,1) = (v.block(0,0,NUM_IMPUT*N,1)).transpose()*v.block(0,k,NUM_IMPUT*N,1);	//160721
			vtemp.resize(NUM_IMPUT*N,2);
	                vtemp = v;
			v << vtemp.block(0,0,NUM_IMPUT*N,1),vtemp.block(0,k,NUM_IMPUT*N,1) - vtemp.block(0,j,NUM_IMPUT*N,1)*hh(j,k-1);
		}
		
		//(c)
		bufd = 0.0;
		for(i = 0; i < NUM_IMPUT*N; i++) bufd += pow(v(i,k),2.0);
		bufd      = sqrt(bufd);
		hh(k,k-1) = bufd;

		//(d)
		if(hh(k,k-1) != 0.0) {
		  vtemp = v;
	          v.block(0,k,NUM_IMPUT*N,1) = vtemp.block(0,k,NUM_IMPUT*N,1)/hh(k,k-1);
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

	dU = v.block(0,0,NUM_IMPUT*N,k)*(hh.block(0,0,k,k)).inverse()*g.block(0,0,k,1);

	return dU;
}

/*
//////////////////////////////////////////////////////////////////////////
// FDGMRES
void CGdnCont::FDGMRES(void)
{
	// FDGMRESパラメータ
	////////////////////////////////////////////////////
	int		kmax = 1;		// イタレーション回数
	double	h = 0.1;	// 微小進み
	double	zeta = 10.0;	// ゼータ
	////////////////////////////////////////////////////

	int i,j;
	int k = 0;
	double rho = 0.0;
	double bufd;
	double w1,w2;
	
	// 行列の生成
	CUMatrix<double, const double&> buf,buf2,r,v,hh,c,s,g;
	buf.SetSize(4*N,1);	buf.SetAllZero();
	buf2.SetSize(4*N,1);	buf2.SetAllZero();
	r.SetSize(4*N,1);	r.SetAllZero();
	v.SetSize(4*N,kmax+1);	v.SetAllZero();
	hh.SetSize(kmax+1,kmax+1);	hh.SetAllZero();
	c.SetSize(kmax+1,1);	c.SetAllZero();
	s.SetSize(kmax+1,1);	s.SetAllZero();
	g.SetSize(kmax+1,1);	g.SetAllZero();


	buf = this->CalcF(this->U, this->X);
	buf2 = this->CalcF(this->U, this->X + this->dX * h);
	r = buf*(-1.0)*zeta - (buf2-buf)/h;

	rho = 0.0;
	for(i = 0; i < 4*N; i++) rho += pow(r.ElementAt(i,0), 2.0);
	rho = sqrt(rho);

	g.SetAt(0,0,rho);
	v.SetAtGrow(0,0, r / rho);

	// iteration
	while(k<kmax){
		//(a)
		k+=1;
		//(b)
		v.SetAtGrow(0,k,(this->CalcF(this->U+v.Extract(0,4*N,k-1,1)*h, this->X+this->dX*h) - this->CalcF(this->U, this->X+this->dX*h))/h);
		for(j = 0; j < k; j++){
			hh.SetAt(j,k-1,this->Trans(v.Extract(0,4*N,j,1))*v.Extract(0,4*N,k,1));
			v.SetAtGrow(0,k,v.Extract(0,4*N,k,1)-v.Extract(0,4*N,j,1)*hh.ElementAt(j,k-1));
		}
		//(c)
		bufd = 0.0;
		for(i = 0; i < 4*N; i++) bufd += pow(v.ElementAt(i,k), 2.0);
		bufd = sqrt(bufd);
		hh.SetAt(k,k-1,bufd);
		//(d)
		if(hh.ElementAt(k,k-1) != 0.0) v.SetAtGrow(0,k,v.Extract(0,4*N,k,1)/hh.ElementAt(k,k-1));
		//(e)
		if(k>1){
			for(i = 0; i < k-1; i++){
				w1 = c.ElementAt(i,0)*hh.ElementAt(i,k-1) - s.ElementAt(i,0)*hh.ElementAt(i+1,k-1);
				w2 = s.ElementAt(i,0)*hh.ElementAt(i,k-1) + c.ElementAt(i,0)*hh.ElementAt(i+1,k-1);
				hh.SetAt(i,k-1,w1);
				hh.SetAt(i+1,k-1,w2);
			}
		}
		bufd = 0.0;
		for(i = k-1; i <= k; i++) bufd += pow(hh.ElementAt(i,k-1), 2.0);
		bufd = sqrt(bufd);
		if(bufd != 0.0){
			c.SetAt(k-1,0, hh.ElementAt(k-1,k-1)/bufd);
			s.SetAt(k-1,0, - hh.ElementAt(k,k-1)/bufd);
			hh.SetAt(k-1,k-1,c.ElementAt(k-1,0)*hh.ElementAt(k-1,k-1)-s.ElementAt(k-1,0)*hh.ElementAt(k,k-1));
			hh.SetAt(k,k-1,0.0);

			w1 = c.ElementAt(k-1,0)*g.ElementAt(k-1,0) - s.ElementAt(k-1,0)*g.ElementAt(k,0);
			w2 = s.ElementAt(k-1,0)*g.ElementAt(k-1,0) + c.ElementAt(k-1,0)*g.ElementAt(k,0);
			g.SetAt(k-1,0,w1);
			g.SetAt(k,0,w2);
		}
		//(f)
		//rho = g.ElementAt(k,0);
		//if(rho < 0) rho = -1.0 * rho;
	}

	this->dU = v.Extract(0,4*N,0,k)*((hh.Extract(0,k,0,k)).Inverse())*g.Extract(0,k,0,1);

	// 行列の解放
	buf.RemoveAll();
	buf2.RemoveAll();
	r.RemoveAll();
	v.RemoveAll();
	hh.RemoveAll();
	c.RemoveAll();
	s.RemoveAll();
	g.RemoveAll();

}
*/

/////////////////////////////////////////////////////////////////////////
//Fの計算
Eigen::MatrixXd CGdnCont::CalcF(Eigen::Matrix<double,NUM_IMPUT*N,1> U, Eigen::Matrix<double,NUM_STATE,1> X,double obj_a[3])
{
	int i,j;
	double bufd;

	Eigen::Matrix<double,NUM_STATE,N+1> xstar;		xstar = Eigen::Matrix<double,NUM_STATE,N+1>::Zero();
	Eigen::Matrix<double,NUM_IMPUT*N,1> ustar;		ustar = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	Eigen::Matrix<double,NUM_STATE,1> f;			f = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	Eigen::Matrix<double,NUM_STATE,N+1> lamda;		lamda = Eigen::Matrix<double,NUM_STATE,N+1>::Zero();
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> dfdx;	dfdx = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::Zero();
	Eigen::Matrix<double,NUM_STATE,1> buf;			buf = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	Eigen::Matrix<double,NUM_STATE,1> buf2;		buf2 = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	Eigen::Matrix<double,NUM_STATE,NUM_IMPUT> dfdu;	dfdu = Eigen::Matrix<double,NUM_STATE,NUM_IMPUT>::Zero();
	Eigen::Matrix<double,NUM_IMPUT*N,1> F;			F = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	Eigen::Matrix<double,NUM_IMPUT,1> buf3;		buf3 = Eigen::Matrix<double,NUM_IMPUT,1>::Zero();
	Eigen::Matrix<double,NUM_IMPUT,1> buf4;		buf4 = Eigen::Matrix<double,NUM_IMPUT,1>::Zero();

	//入力系列の生成
	for(i = 0; i < NUM_IMPUT*N; i++){
		ustar(i,0) = U(i,0);
	}

	//状態系列の生成		160713 
	for(i = 0; i < NUM_STATE; i++){
		xstar(i,0) = X(i,0);
	}

	for(i = 0; i < N; i++){
		//for(j = 0; j < 3; j++) f(j,0) = xstar(j+3,j);
		//f(3,0) = -kxy*(la+lb*sin(ustar(NUM_IMPUT*i+3,0)))*xstar(3,i) + ustar(NUM_IMPUT*i,1) / m;
		//f(4,0) = -kxy*(la+lb*cos(ustar(NUM_IMPUT*i+3,0)))*xstar(NUM_IMPUT,i) + ustar(NUM_IMPUT*i+1,0) / m;
		//f(5,0) = -kz*xstar(5,i) + ustar(NUM_IMPUT*i+2,0) / m; // + m*g		//モデルを変更

		f = A_model*xstar.block(0,i,NUM_STATE,1) + B_model*ustar.block(NUM_IMPUT*i,0,NUM_IMPUT,1); //+g 変更後 //160721

		for(j = 0; j < NUM_STATE; j++) xstar(j,i+1) = xstar(j,i)+f(j,0)*dt;
	}

	//ラグランジュ乗数の生成
	buf2 = S*xstar.block(0,N,NUM_STATE,1)*2.0;		//160721

	for(i = 0; i < NUM_STATE; i++) lamda(i,N) = buf2(i,0);

		//df/dx	160713 モデル変更
		//for(j = 0; j < 3; j++) dfdx(j,j+3) = 1.0;
		//dfdx(3,3) = -kxy*(la+lb*sin(ustar(NUM_IMPUT*i+3,0))/m);
		//dfdx(4,4) = -kxy*(la+lb*cos(ustar(NUM_IMPUT*i+3,0))/m);
		//dfdx(5,5) = -kz/m;
	
	dfdx = A_model;		//変更後
	for(i = N-1; i >= 0; i--){
		//dp/dx
		for(j = 0; j < 2; j++) buf(j,0) = xstar(j,i)-obj_a[j];	//bufは障害物との相対位置		
		bufd = 0.0;
		
		for(j = 0; j < NUM_STATE; j++) bufd += pow(buf(j,0),2.0);

		//-buf*2.0*rx/(0.0001-(pow(Rr,2.0)-bufd))//状態拘束log
		//-buf*4.0*max(0,pow(Rr,2.0)-bufd)//状態拘束max
		buf2 = (Q.transpose())*xstar.block(0,i,NUM_STATE,1)*2.0 + (dfdx.transpose())*lamda.block(0,i+1,NUM_STATE,1) - buf*4.0*rx*std::max(0.0,pow(Rr,2.0)-bufd);//状態拘束max  //160721

		for(j = 0; j < NUM_STATE; j++) lamda(j,i) = lamda(j,i+1) + buf2(j,0) * dt;
	}

	//Fの計算
	dfdu = B_model;		//変更後
	for(i = 0; i < N; i++){
		//入力拘束
		buf4(0,0) = ustar(NUM_IMPUT*i,0);
		buf4(1,0) = ustar(NUM_IMPUT*i+1,0);
		buf4 = buf4*4.0*ru*std::max(0.0,pow(ustar(NUM_IMPUT*i,0),2.0)+pow(ustar(NUM_IMPUT*i+1,0),2.0)-pow(phi_max,2.0));

		buf3 = (R.transpose())*ustar.block(NUM_IMPUT*i,0,NUM_IMPUT,1)*2.0 + (dfdu.transpose())*lamda.block(0,i+1,NUM_STATE,1)*2.0 + buf4;  //160721
		for(j = 0; j < NUM_IMPUT; j++)	F(NUM_IMPUT*i+j,0) = buf3(j,0);
	}
 	return F;
}
/*
//////////////////////////////////////////////////////////////////////////
// Fの計算
CUMatrix<double, const double&> CGdnCont::CalcF(CUMatrix<double, const double&> ustar, CUMatrix<double, const double&> xinit)
{
	// モデルパラメータ
	///////////////////////////////////////////
	double la = 1.0;	// 抵抗係数パラメータ
	double lb = 0.2;	// 抵抗係数パラメータ
	double kxy = 0.01;	// 抵抗係数パラメータ（XY軸）
	double kz = 0.07;	// 抵抗係数パラメータ（Z軸）
	double m = 0.264;	// 質量
	double g = 9.81;	// 重力加速度
	///////////////////////////////////////////

	int i,j;
	double bufd;
	CUMatrix<double, const double&> xstar,f,lambda,dfdx,buf,buf2,dfdu,F,buf3,buf4;
	xstar.SetSize(6,N+1);	xstar.SetAllZero();
	f.SetSize(6,1);			f.SetAllZero();
	lambda.SetSize(6,N+1);	lambda.SetAllZero();
	dfdx.SetSize(6,6);		dfdx.SetAllZero();
	buf.SetSize(6,1);		buf.SetAllZero();
	buf2.SetSize(6,1);		buf2.SetAllZero();
	dfdu.SetSize(6,4);		dfdu.SetAllZero();
	F.SetSize(4*N,1);		F.SetAllZero();
	buf3.SetSize(4,1);		buf3.SetAllZero();
	buf4.SetSize(4,1);		buf4.SetAllZero();

	// 状態系列の生成
	for(i = 0; i < 6; i++){
		xstar.SetAt(i,0,xinit.ElementAt(i,0));
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < 3; j++) f.SetAt(j,0,xstar.ElementAt(j+3,i));
		f.SetAt(3,0,(-kxy*(la+lb*sin(ustar.ElementAt(4*i+3,0)))*xstar.ElementAt(3,i) + ustar.ElementAt(4*i,0)) / m);
		f.SetAt(4,0,(-kxy*(la+lb*cos(ustar.ElementAt(4*i+3,0)))*xstar.ElementAt(4,i) + ustar.ElementAt(4*i+1,0)) / m);
		f.SetAt(5,0,(-kz*xstar.ElementAt(5,i) + ustar.ElementAt(4*i+2,0)) / m);// + m*g

		for(j = 0; j < 6; j++) xstar.SetAt(j,i+1,xstar.ElementAt(j,i)+f.ElementAt(j,0)*this->dt);
	}
	

	// ラグランジュ乗数の生成
	buf2 = this->S*xstar.Extract(0,6,N,1)*2.0;
	for(i = 0; i < 6; i++) lambda.SetAt(i,N,buf2.ElementAt(i,0));
	for(i = N-1; i >= 1; i--){
		//df/dx
		for(j = 0; j < 3; j++) dfdx.SetAt(j,j+3,1.0);
		dfdx.SetAt(3,3,-kxy*(la+lb*sin(ustar.ElementAt(4*i+3,0)))/m);
		dfdx.SetAt(4,4,-kxy*(la+lb*cos(ustar.ElementAt(4*i+3,0)))/m);
		dfdx.SetAt(5,5,-kz/m);
		//dp/dx
		for(j=0;j<2;j++) buf.SetAt(j,0,xstar.ElementAt(j,i)-this->obj[j]);	//jが0,1,2で球，0,1までで円筒
		bufd = 0.0;
		for(j=0;j<6;j++) bufd += pow(buf.ElementAt(j,0),2.0);
		// - buf*2.0*this->rx/(0.0001-(pow(this->Rr,2.0)-bufd))//状態拘束log
		// - buf*4.0*this->rx*max(0,pow(this->Rr,2.0)-bufd)//状態拘束max
		buf2 = this->Trans(Q)*xstar.Extract(0,6,i,1)*2.0 + this->Trans(dfdx)*lambda.Extract(0,6,i+1,1) - buf*4.0*this->rx*max(0,pow(this->Rr,2.0)-bufd);//状態拘束max

		for(j=0;j<6;j++) lambda.SetAt(j,i,lambda.ElementAt(j,i+1) + buf2.ElementAt(j,0) * this->dt);
	}

	// Fの計算
	for(i = 0; i < N; i++){
		for(j = 0; j < 3; j++) dfdu.SetAt(j+3,j,1.0/m);
		dfdu.SetAt(3,3,-kxy*lb*cos(ustar.ElementAt(4*i+3,0))/m*xstar.ElementAt(3,i));
		dfdu.SetAt(4,3,-kxy*lb*sin(ustar.ElementAt(4*i+3,0))/m*xstar.ElementAt(4,i));
		//入力拘束
		buf4.SetAt(0,0,ustar.ElementAt(4*i,0));
		buf4.SetAt(1,0,ustar.ElementAt(4*i+1,0));
		buf4 = buf4*4.0*this->ru*max(0,pow(ustar.ElementAt(4*i,0),2.0)+pow(ustar.ElementAt(4*i+1,0),2.0)-pow(m*g*sin(this->phi_max),2.0));

		buf3 = this->Trans(this->R)*ustar.Extract(4*i,4,0,1)*2.0 + this->Trans(dfdu)*lambda.Extract(0,6,i+1,1)*2.0 + buf4;
		for(j = 0; j < 4; j++) F.SetAt(4*i+j,0,buf3.ElementAt(j,0));
	}

	// 行列の解放
	xstar.RemoveAll();
	f.RemoveAll();
	lambda.RemoveAll();
	dfdx.RemoveAll();
	buf.RemoveAll();
	buf2.RemoveAll();
	dfdu.RemoveAll();
	buf3.RemoveAll();
	buf4.RemoveAll();

	return F;
}
*/
