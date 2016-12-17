#ifndef MPC_H
#define MPC_H

#include <Eigen/Geometry>
#include "stateData.h"
#include "paramMpc.h"

////////////////////////////////////////////////////////
class mpcController
{
public:
	mpcController(void);

	//制御演算
	void ResetCont(StateData);
	Eigen::MatrixXd mpcControllerLoop(StateData,int signal,double next_xRef,double next_yRef,double next_zRef);

protected:
	
	int initFlag;

	double dt,xRef,yRef,zRef,rx,ru,alphaMax,Rr;
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> U;
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> dU;
	Eigen::Matrix<double,N_STATE_MODEL,1> UOb;
	Eigen::Matrix<double,N_STATE_MODEL,1> x;
	Eigen::Matrix<double,N_STATE_MODEL,1> xOb;
	Eigen::Matrix<double,N_STATE_MODEL,1> dx;

	Eigen::MatrixXd FDGMRES(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U,Eigen::Matrix<double,N_STATE_MODEL,1> x,Eigen::Matrix<double,N_STATE_MODEL,1> dx);
	Eigen::MatrixXd CalcF(Eigen::Matrix<double,N_INPUT_MODEL*N,1> U,Eigen::Matrix<double,N_STATE_MODEL,1> x);

	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> S;
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> Q;
	Eigen::Matrix<double,N_INPUT_MODEL,N_INPUT_MODEL> R;
	Eigen::Matrix<double,N_STATE_MODEL,N_STATE_MODEL> A_model;
	Eigen::Matrix<double,N_STATE_MODEL,N_INPUT_MODEL> B_model;
	Eigen::Matrix<double,N_STATE_OB,N_STATE_OB> A_ob;
	Eigen::Matrix<double,N_STATE_OB,N_INPUT_OB> B_ob;

};
#endif
