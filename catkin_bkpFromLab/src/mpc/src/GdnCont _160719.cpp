#include"stdAfx.h"
#include"GdnCont.h"
#define NUM_STATE 9
#define NUM_IMPUT 4

CGdnCont::CGdnCont(void)
{
	int i;
	this->U(NUM_IMPUT*N,1);		this->U = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	this->dU(NUM_IMPUT*N,1);	this->dU = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	this->X(NUM_STATE,1);		this->X = Eigen::Matrix<double,NUM_STATE,1>::zero();
	this->dX(NUM_STATE,1);		this->dX = Eigen::Matrix<double,NUM_STATE,1>::zero();
	
	this->S(NUM_STATE,NUM_STATE);		this->S = Eigen::Matrix9d::zero();
	this->Q(NUM_STATE,NUM_STATE);		this->Q = Eigen::Matrix9d::zero();
	this->R(NUM_IMPUT,NUM_IMPUT);		this->R = Eigen::Matrix4d::zero();

	this->A_model(NUM_STATE,NUM_STATE);	this->A_model = Eigen::Matrix9d::zero();
	this->B_model(NUM_STATE,NUM_IMPUT);	this->B_model = Eigen::Matrix<double,NUM_STATE,NUM_IMPUT>::zero();
 
	//モデルパラメータ
	///////////////////////////////////////////////////////////////////
	//A_model
	this->A_model(0,3) = 1.0;	this->A_model(0,6) = 0.0;
	this->A_model(1,4) = 1.0;	this->A_model(1,7) = 0.0;
	this->A_model(2,5) = 1.0;	this->A_model(2,8) = 0.0;
	this->A_model(3,3) = 0.0;	this->A_model(3,6) = 1.0;
	this->A_model(4,4) = 0.0;	this->A_model(4,7) = 1.0;
	this->A_model(5,5) = 0.0;	this->A_model(5,8) = 1.0;
	this->A_model(6,3) = -5.9488;	this->A_model(6,6) = -2.8293;
	this->A_model(7,4) = -7.3046;	this->A_model(7,7) = -3.2973;
	this->A_model(8,5) = -8.6505;	this->A_model(8,8) = -5.8235;

	//B_model
	this->B_model(6,0) = 0.4819;
	this->B_model(7,1) = 0.5113;
	this->B_model(8,3) = 0.0013;


	//MPCパラメータ
	///////////////////////////////////////////////////////////////////
	//S
	this->S(0,0) = 60.0; //x
	this->S(1,1) = 60.0; //y
	this->S(2,2) = 200.0;//z
	this->S(3,3) = 500.0;//vx
	this->S(4,4) = 500.0;//vy
	this->S(5,5) = 10.0; //vz	//160713
	this->S(6,6) = 1.0;//ax
	this->S(7,7) = 1.0;//ay
	this->S(8,8) = 1.0;//az
	//Q
	this->Q(0,0) = 20.0; //x	0,0,5.0
	this->Q(1,1) = 20.0; //y	1,1,5.0
	this->Q(2,2) = 5.0;  //z
	this->Q(3,3) = 2.0;  //vx
	this->Q(4,4) = 2.0;  //vy
	this->Q(5,5) = 2.0;  //vz
	this->Q(6,6) = 2.0;  //ax
	this->Q(7,7) = 2.0;  //ay
	this->Q(8,8) = 2.0;  //az
	//R
	for(i = 0; i < NUM_IMPUT; i++)	this->R(i,i) = 200.0;
	
	this->dt = 0.1;	//サンプリングタイム
	this->obj_a[0] = 0.0;	this->obj_a[1] = -0.2;	this->obj_a[2] = 1.3;	//障害物位置（絶対位置）
	this->rx = 0.0;	//状態拘束重み 3000
	this->ru = 10000.0;	//入力拘束重み 10000
	this->Rr = 0.4;	//半径
	this->ph_max = 10.0*3.14/180;	//最大傾斜
	///////////////////////////////////////////////////////////////////
}

///////////////////////////////////////////////////////////////////////////
//制御演算初期化
void CGdnCont::ResetCont(SensorData c_SensorData)
{
	this->SW = 0;

	this->U = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	this->dU = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	this->X = Eigen::Matrix<double,NUM_STATE,1>::zero();
	this->dX = Eigen::Matrix<double,NUM_STATE,1>::zero();

	//目標値生成
	this->m_RefDate.X = c_SensorData.PosX;
	this->m_RefDate.Y = c_SensorData.PosY;
	this->m_RefData.Z = c_SensorData.PosZ;
						//160713//160719
	this->m_RefData.Fx = 0,0;		//変わる
	this->m_RefData.Fy = 0,0;
	this->m_RefData.Fz = 0,0;
	this->m_RefData.thrust = 0.264*9.81;

	//障害物位置生成（相対位置）
	this->obj[0] = this->obj_a[0] - this->m_RefData.X;
	this->obj[1] = this->obj_a[1] - this->m_RefData.Y;
	this->obj[2] = this->obj_a[2] - this->m_RefData.Z;
	

}


//////////////////////////////////////////////////////////////////////////////
//誘導制御演算(MPC)
void CGdnCont::GdnCont(RefNext c_RefNext, SensorData c_SensorData)
{
	//目標値生成	160713
	if(c_RefNext.SW == 1){
		this->m_RefData.X = c_RefNext.X;
		this->m_RefData.Y = c_RefNext.Y;
		this->m_RefData.Z = c_RefNext.Z;
		//障害物位置生成（相対位置）
		this->obj[0] = this->obj_a[0] - this->m_RefData.X;
		this->obj[1] = this->obj_a[1] - this->m_RefData.Y;
		this->obj[2] = this->obj_a[2] - this->m_RefData.Z;
	}
	
	//時間計測
	timeBeginPeriod(1);
	int bef = timeGetTime();

	//状態の更新
	this->dX = this->X * (-1.0);
	this->X(0,0) = c_SensorData.PosX - this->m_RefData.X:
	this->X(1,0) = c_SensorData.PosY - this->m_RefData.Y;
	this->X(2,0) = -c_SensorData.PosZ - this->m_RefData.Z;
	this->X(3,0) = c_SensorData.Vx;
	this->X(4,0) = c_SensorData.Vy;
	this->X(5,0) = c_SensorData.Vz;
	this->dX += this->X;
	this->dX = this->dX / this->dt;

	//初期入力の決定
	if(this->SW == 0){
		this->SW = 1;
		this->dX = Eigen::Matrix<double,NUM_STATE,1>::Zero();
		this->U = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	}

	// FDGMRES
	this->FDGMRS();
	this->U += this->dU * this->dt;

	//制御入力生成（外力ベクトルto姿勢と推力）
	//this->m_RefData.Fx = this->U(0,0);
	//this->m_RefData.Fy = this->U(1,0);
	//this->m_RefData.Fz = this->U(2,0)-0.264*9.81;
	//if(this->U(2,0) >= 0.264*9.81){
		this->m_RefData.Fz = 0.0001;		//目標姿勢生成にFzが0はだめ
	}
	this->m_RefData.yaw = this->U(3,0);
	this->F2Att();

	//時間計測
	this->mpctime = timeGetTime - bef;
	this->timeEndperiod(1);

}

////////////////////////////////////////////////////////////////////////////////////
//FDGMRES
void GdnCont::FDGMRES(void)
{
	//FDGMRESパラメータ
	/////////////////////////////////////////////
	int		kmax = 1;	//イタレーション回数
	double	h = 0.1;	//微小進み
	double	zeta = 10.0;	//ゼータ
	/////////////////////////////////////////////

	int i,j;
	int k = 0;
	double rho = 0.0;
	double bufd;
	double w1,w2;

	//行列の生成
	Eigen::Matrixd<double, const double& > buf,buf2,r,v,hh,c,s,g;
	buf(NUM_IMPUT*N,1);		buf = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	buf2(NUM_IMPUT*N,1);		buf2 = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	r(NUM_IMPUT*N,1);		r = Eigen::Matrix<double,NUM_IMPUT*N,1>::zero();
	v(NUM_IMPUT*N,kmax);		v = Eigen::Matrix<double,NUM_IMPUT*N,kmax>::zero();
	hh(kmax+1,kmax+1);	hh = Eigen::Matrix<double,kmax+1,kmax+1>::zero();
	c(kmax+1,1);		c = Eigen::Matrix<double,kmax+1,1>::zero();
	s(kmax+1,1);		s = Eigen::Matrix<double,kmax+1,1>::zero();
	g(kmax+1,1);		g = Eigen::Matrix<double,kmax+1,1>::zero();


	buf = this->CalcF(this->U, this->X);
	buf2 = this->CalcF(this->U, this->X + this->dX * h);
	r = buf*(-1.0)*zeta - (buf2 - buf)/h;

	rho = 0.0;
	for(i = 0; i < NUM_IMPUT*N; i++) rho += pow(r(i,0),2.0);
	rho = sqrt(rho);

	g(0,0) = rho;
	//v(0,0) = r/rho;

	//iteration
	while(k<kmax){
		//(a)
		k += 1;
		//(b)
		v = SetAtGrow(0,k,v,this->CalcF(this->U+v.Extract(0,NUM_IMPUT*N,k-1,1)*h) = this->X+this->dX*h - this->CalcF(this->U, this->X+this->dX*h))/h);
		for(j = 0; j < k; j++){
			hh(j,k-1) = this->Trans(Extract(0,NUM_IMPUT*N,j,1,v))*Extract(0,NUM_IMPUT*N,k,1,v);
			v(0,k) = SetAtGrow(0,k,v,Extract(0,NUM_IMPUT*N,k,1,v)-Extract(0,NUM_IMPUT*N,j,1,v)*hh(j,k-1));
		}
		//(c)
		bufd = 0,0;
		for(i = 0; i < NUM_IMPUT*N; i++) bufd += pow(v(i,k),2.0);
		bufd = sqrt(bufb);
		hh(k,k-1) = bufd;


		//(d)
		if(hh(k,k-1) != 0.0) v = SetAtGrow(0,k,v,Extract(0,NUM_IMPUT*N,k,1,v)/hh(k,k-1);

		//(e)
		if(k>1){
			for(i = 0; i < k-1; i++){
				w1 = c(i,0)*hh(i,k-1) - s(i,0)*hh(i+1,k-1);
				w2 = s(i,0)*hh(i,k-1) + c(i,0)*hh(i+1,k-1);
				hh(i,k) = w1;
				hh(i+1,k+1) = w2;
			}
		}
		bufd = 0.0;
		for(i = k-1; i <=k; i++) bufd += pow(hh(i,k-1),2.0);
		bufd = sqrt(bufd);
		if(bufd != 0.0){
			c(k-1,0) = hh(k-1,k-1)/bufd;
			s(k-1,0) = -hh(k,k-1)/bufd;
			hh(k-1,k-1) = c(k-1,0)*hh(k-1,k-1)-s(k-1,0)*g(k-1,0);
			hh(k,k-1) = 0.0;

			w1 = c(k-1,0)*hh(k,k-1) - s(k-1,0)*g(k,0);
			w2 = s(k-1,0)*g(k-1,0) + c(k-1,0)*g(k,0);
			g(k-1,0) = w1;
			g(k,0) = w2;
		}
		//(f)
		//rho = g(k,0);
		//if(rho < 0) rho = -1.0 * rho;
	}

	this->dU = Extract(0,NUM_IMPUT*N,0,k,v)*(Extract(0,k,0,k,hh)).Inverse())*Extract(0,k,0,1,g);

}


/////////////////////////////////////////////////////////////////////////
//Fの計算
Eigen::MatrixXd<double, const double&> CGdnCont::CalcF(Eigen::MatrixXd<double, const double&> ustar, Eigen::MatrixXd(<double, const double&> xinit)
{
	int i,j;
	double bufd;
	Eigen::MatrixXd<double, const double&> xstar,f,lambda,dfdx,buf,buf2,dfdu,F,buf3,buf4;
	xstar(NUM_STATE,N+1);	xstar = Eigen::Matrix<double,NUM_STATE,N+1>::zero();
	f(NUM_STATE,1)		f = Eigen::Matrix<double,NUM_STATE,1>::zero();
	lamda(NUM_STATE,N+1)	lamda = Eigen::Matrix<double,NUM_STATE,N+1>::zero();
	dfdx(NUM_STATE,NUM_STATE)	dfdx = Eigen::Matrix<double,NUM_STATE,NUM_STATE>::zero();
	buf(NUM_STATE,1)	buf = Eigen::Matrix<double,NUM_STATE,1>::zero();
	buf2(NUM_STATE,1)	buf2 = Eigen::Matrix<double,NUM_STATE,1>::zero();
	dfdu(NUM_STATE,NUM_IMPUT)	dfdu = Eigen::Matrix<double,NUM_STATE,NUM_IMPUT>::zero();
	F(NUM_IMPUT*N,1)	F = Eigen::Matrix<double,NUM_IMPUT,N+1>::zero();
	buf3(NUM_IMPUT,1)	buf3 = Eigen::Matrix<double,NUM_IMPUT,1>::zero();
	buf4(NUM_IMPUT,1)	buf4 = Eigen::Matrix<double,NUM_IMPUT,1>::zero();


	

	//状態系列の生成		160713 
	for(i = 0; i < NUM_STATE; i++){
		xstar(i,0) = xinit(i,0);
	}
	for(i = 0; i < N; i++){
		for(j = 0; j < 3; j++) f(j,0) = xstar(j+3,j);
		f(3,0) = -kxy*(la+lb*sin(ustar(NUM_IMPUT*i+3,0)))*xstar(3,i) + ustar(NUM_IMPUT*i,1) / m;
		f(4,0) = -kxy*(la+lb*cos(ustar(NUM_IMPUT*i+3,0)))*xstar(NUM_IMPUT,i) + ustar(NUM_IMPUT*i+1,0) / m;
		f(5,0) = -kz*xstar(5,i) + ustar(NUM_IMPUT*i+2,0) / m; // + m*g		//モデルを変更

		f = A_model * xstar(i,0) + B_model * ustar(i,0); //+g		//変更後
		

		for(j = 0; j < NUM_STATE; j++) xstar(j,i+1) = xstar(j,i)+f(j,0)*this->dt;
		}

	//ラグランジュ乗数の生成
	buf2 = this->S*Extract(0,NUM_STATE,N,1,xstar)*2.0;
	for(i = 0; i < NUM_STATE; i++) lamda(i,N) = buf2(i,0);
	for(i = N-1; i < NUM_STATE; i--){
		//df/dx	160713 モデル変更
		for(j = 0; j < 3; j++) dfdx(j,j+3) = 1.0;
		dfdx(3,3) = -kxy*(la+lb*sin(ustar(NUM_IMPUT*i+3,0))/m);
		dfdx(4,4) = -kxy*(la+lb*cos(ustar(NUM_IMPUT*i+3,0))/m);
		dfdx(5,5) = -kz/m;

		
		df/dx = A_model;		//変更後

		//dp/dx
		for(j = 0; j < 2; j++) buf(j,0) = xstar(j,i)-this->obj[j];	//jが0,1,2で球,0,1までで円筒		
		bufd = 0.0;
		for(j = 0; j < 2; j++) bufd += pow(buf(j,0),2.0);
		//-buf*2.0*this->rx/(0.0001-(pow(this->Rr,2.0)-bufd))//状態拘束log
		//-buf*4.0*this->max(0,pow(this->Rr,2.0)-bufd)//状態拘束max
		buf2 = this->Trans(Q)*Extract(0,NUM_STATE,i,1,xstar)*2.0 + this->Trans(dfdx)*Extract(0,NUM_STATE,i+1,1,lamda) - buf*4.0*this->rx*max(0,pow(this->Rr,2.0)-bufd);//状態拘束max

		for(j = 0; j < NUM_STATE; j++) lamda(j,i) = Extract(j,i+1,lamda) + buf2(j,0) * this->dt;
	}

	//Fの計算
	for(i = 0; i < N; i++){
		for(j = 0; j < 3; j++) dfdu(j+3,j) = 1.0/m;
		dfdu(3,3) = -kxy*lb*cos(ustar(NUM_IMPUT*i+3,0))/m*xstar(NUM_IMPUT,i);	//160713　モデル変更
		dfdu(4,3) = -kxy*lb*sin(ustar(NUM_IMPUT*i+3,0))/m*xstar(NUM_IMPUT,i);

		dfdu = B_model;		//変更後

		//入力拘束
		buf4(0,0) = ustar(NUM_IMPUT*i,0);
		buf4(1,0) = ustar(NUM_IMPUT*i+1,0);
		buf4 = buf4*4.0*this->ru*max(0,pow(ustar(NUM_IMPUT*i,0,2.0))+pow(ustar(NUM_IMPUT*i+1,0,2.0)-pow(m*g*sin(this->phi_max),2.0));

		buf3 = this->Trans(this->R)*Extract(NUM_IMPUT*i,NUM_IMPUT,0,1,ustar)*2.0 + this->Trans(dfdu)*Extract(0,NUM_STATE,i+1,1,lamda)*2.0 + buf4;
		for(j = 0; j < NUM_IMPUT; j++) F(NUM_IMPUT*i+j,0) = buf3(j,0);
	}
 	return F;
}


///////////////////////////////////////////////////////////////////
//転置の計算
Eigen::MatrixXd<double, const double&> CGdnCont::Trans
(Eigen::MatrixXd<double, const double&> a)
{
	int i,j;

	int Row = a.GetSizeRow();
	int Col = a.GetSizeCol();

	Eigen::MatrixXd<double, const double&> b;
	b(COl,Row);	b = Eigen::Matrix<double, Col, Row>::zero();

	for(i = 0; i < Col; i++){
		for(j = 0; j < Row; i++){
			b(i,j) = a(j,i);
		}
	}
	
	reutrn b;
}

























