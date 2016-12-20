#pragma once
#include <Eigen/Core>
#include <Eigen/Geometry>

//MPCステップ関数
#define N 20
#define NUM_STATE 9
#define NUM_IMPUT 4

class CGdnCont
{
public:
	CGdnCont(void);
	// CGdnCont(void);

	//制御演算
	Eigen::MatrixXd ResetCont(double pos[3]);
	Eigen::MatrixXd GdnCont(Eigen::Matrix<double,NUM_IMPUT*N,1> U,double pos[3],double vel[3],double lin[3]);

protected:
	
	int SW;
	double dt,obj_a[3],obj[3],ref_X,ref_Y,ref_Z,rx,ru,phi_max,Rr;
	Eigen::Matrix<double,NUM_IMPUT*N,1> U;
	Eigen::Matrix<double,NUM_IMPUT*N,1> dU;
	Eigen::Matrix<double,NUM_STATE,1> X;
	Eigen::Matrix<double,NUM_STATE,1> dX;

	Eigen::MatrixXd FDGMRES(Eigen::Matrix<double,NUM_IMPUT*N,1> U,Eigen::Matrix<double,NUM_STATE,1> X,Eigen::Matrix<double,NUM_STATE,1> dX,double obj[3]);
	Eigen::MatrixXd CalcF(Eigen::Matrix<double,NUM_IMPUT*N,1> U,Eigen::Matrix<double,NUM_STATE,1> X,double obj[3]);

	Eigen::Matrix<double,NUM_STATE,NUM_STATE> S;
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> Q;
	Eigen::Matrix<double,NUM_IMPUT,NUM_IMPUT> R;
	Eigen::Matrix<double,NUM_STATE,NUM_STATE> A_model;
	Eigen::Matrix<double,NUM_STATE,NUM_IMPUT> B_model;
};

