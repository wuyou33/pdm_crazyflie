#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
//#include "GdnCont_main.h"
#include "GdnCont.h"
#include "estimate/msgCrazyflie_data.h"
#include "monitor_ishii/msgMPC.h"
#include "generate_reference/msgReference.h"
#include <fstream>

//////debug用変数定義
std::ofstream ofs("MPC_debug.txt"); //textメッセージ
double imu_box[7],lin[3];
double vrpn_time;
int SaveSignal;
bool SaveFlag;
/////////////////////


double SW = 0.0,pos[3],vel[3],ori_x = 0.0,ori_y = 0.0,ori_z = 0.0,ori_w = 0.0;
double next_ref_x = 0.0,next_ref_y = 0.0,next_ref_z = 0.0;
double ctrl_input_phi = 0.0, ctrl_input_theta = 0.0,ctrl_input_psi = 0.0,ctrl_input_thrust = 0.0;
bool ControlFlag = false;
int flag = 1,Signal = 0;

ros::Publisher mpc_pub;
ros::Subscriber joy_sub;
ros::Subscriber ref_sub;
ros::Subscriber esti_sub;
ros::Time calc_start_time,calc_end_time;
double calc_time = 0.0;

sensor_msgs::Joy msg1;
estimate::msgCrazyflie_data msg2;
generate_reference::msgReference msg3;
monitor_ishii::msgMPC mpc_msg;

// MPCによる誘導制御の実態
CGdnCont gdncontroller;

void joycallback(const sensor_msgs::Joy& joy_msg)
{
	
        msg1 = joy_msg;
  	SW   = msg1.buttons[3];
	SaveSignal = msg1.buttons[1];//20161006
  
	if(1.0 == SW)
	{
		ControlFlag = false;
		flag = 1;
	}

	else if(0.0 == SW)
	{
		ControlFlag = true;
		flag = 0;
	}
	if(1 == SaveSignal)
		SaveFlag = false;

	else if(0 == SaveSignal)
		SaveFlag = true;	
}

void refcallback(const generate_reference::msgReference &ref_msg)
{	
        msg3   = ref_msg;
  	Signal = (int)msg3.signal;
  
	if(1 == Signal)
	{
		next_ref_x = (double)msg3.next_ref_x;
		next_ref_y = (double)msg3.next_ref_y;
		next_ref_z = (double)msg3.next_ref_z;
	}

	else if(0 == Signal)
	{
		next_ref_x = 0.0;
		next_ref_y = 0.0;
		next_ref_z = 0.0;
	}
}

void esticallback(const estimate::msgCrazyflie_data& esti_msg)
{
	Eigen::Matrix<double,NUM_IMPUT*N,1> Us;
	Eigen::Matrix<double,NUM_STATE,1> X_observer;
	Eigen::Matrix<double,NUM_STATE,1> U_observer;
	Eigen::Matrix<double,NUM_IMPUT*N + NUM_STATE + NUM_STATE,1> U_temp;

	msg2     = esti_msg;
	ori_x    = (double)msg2.vrpn_orix_msg;
	ori_y    = (double)msg2.vrpn_oriy_msg;
	ori_z    = (double)msg2.vrpn_oriz_msg;
	ori_w    = (double)msg2.vrpn_oriw_msg;
	pos[0]   = (double)msg2.vrpn_posx_msg;
	pos[1]   = (double)msg2.vrpn_posy_msg;
	pos[2]   = (double)msg2.vrpn_posz_msg;
	vel[0]   = (double)msg2.vrpn_velx_msg;
	vel[1]   = (double)msg2.vrpn_vely_msg;
	vel[2]   = (double)msg2.vrpn_velz_msg;

	////mpc_debug用/////////////////////
	imu_box[0] = (double)msg2.imu_time_msg;	
	imu_box[1] = (double)msg2.imu_angx_msg;
	imu_box[2] = (double)msg2.imu_angy_msg;
	imu_box[3] = (double)msg2.imu_angz_msg;
	imu_box[4] = (double)msg2.imu_linx_msg;
	imu_box[5] = (double)msg2.imu_liny_msg;
	imu_box[6] = (double)msg2.imu_linz_msg;
	vrpn_time  = (double)msg2.vrpn_time_msg;
	lin[0]     = (double)msg2.vrpn_linx_msg;
	lin[1]     = (double)msg2.vrpn_liny_msg;
	lin[2]     = (double)msg2.vrpn_linz_msg;
	////////////////////////////////////

	mpc_msg.controlflag = flag;

	if(false == ControlFlag)
	{
          	// 制御器の初期化
	  	gdncontroller.ResetCont(pos,vel);

		ctrl_input_phi    = 0.0;
		ctrl_input_theta  = 0.0;
		ctrl_input_psi    = 0.0;
		ctrl_input_thrust = 0.0;
	}
	else
	{
		calc_start_time = ros::Time::now();

		U_temp     = gdncontroller.GdnCont(Us,pos,vel,Signal,next_ref_x,next_ref_y,next_ref_z);	//オブザーバデバッグ用に書き換えてある(UとXとU_obのデータを配信するため)
		Us          = U_temp.block(0,0,80,1);		//
		X_observer = U_temp.block(80,0,9,1);	//
		U_observer = U_temp.block(89,0,9,1);	//

		ctrl_input_phi    = Us(0,0) * (1.0 - 2.0*std::pow(ori_y,2.0) - 2.0*std::pow(ori_z,2.0)) + Us(1,0) * (2.0*ori_x*ori_y + 2.0*ori_w*ori_z) + Us(3,0) * (2.0*ori_x*ori_z - 2.0*ori_w*ori_y);		//ワールド座標系からローカル座標系に変換
		ctrl_input_theta  = Us(0,0) * (2.0*ori_x*ori_y - 2.0*ori_w*ori_z) + Us(1,0) * (1.0 - 2.0*std::pow(ori_x,2.0) - 2.0*std::pow(ori_z,2.0)) + Us(3,0) * (2.0*ori_y*ori_z + 2.0*ori_w*ori_x);
		ctrl_input_psi    = Us(2,0);
		ctrl_input_thrust = Us(0,0) * (2.0*ori_x*ori_z + 2.0*ori_w*ori_y) + Us(1,0) * (2.0*ori_y*ori_z - 2.0*ori_w*ori_x) + Us(3,0) * (1.0 - 2.0*std::pow(ori_x,2.0) - 2.0*std::pow(ori_y,2.0));

		calc_end_time = ros::Time::now();
		calc_time     = calc_end_time.sec + calc_end_time.nsec * 0.000000001 - (calc_start_time.sec + calc_start_time.nsec * 0.000000001);
		//std::cout << "mpc_time(s)" << calc_time << std::endl << std::endl;
	}

        mpc_msg.phi    = ctrl_input_phi;	//制御入力を送信する
	mpc_msg.theta  = ctrl_input_theta;
 	mpc_msg.psi    = ctrl_input_psi;
	mpc_msg.thrust = ctrl_input_thrust;

        mpc_pub.publish(mpc_msg);

////////debug用データ保存

	if(true == SaveFlag)
	{
			std::cout << SaveFlag << std::endl;
		for(int i = 0;i < 7;i++)
			ofs << imu_box[i] << " ";	//imu:time,ang,acc	1-7
		
		ofs << vrpn_time << " ";		//mocap:time	8

		for(int i = 0;i < 3;i++)
			ofs << pos[i] << " ";		//mocap:pos[x,y,z],vel[vx,vy,vz],lin[ax,ay,az],ori[x,y,z,w]	9-21

		for(int i = 0;i < 3;i++)
			ofs << vel[i] << " ";

		for(int i = 0;i < 3;i++)
			ofs << lin[i] << " ";

		ofs << ori_x << " " << ori_y << " " << ori_z << " " << ori_w << " ";

		ofs << flag << " ";			//control_switch	22

		for(int i = 0;i < 4;i++)
			ofs << Us(i,0) << " ";		//control_input[φ θ ψ T]'	23-26

		for(int i = 0;i < 80;i++)
			ofs << Us(i,0) << " ";		//feedback_input[φ θ ψ T * 20]'	27-106

		for(int i = 0;i < 9;i++)
			ofs << X_observer(i,0) << " ";	//observer_state[x,vx,ax,y,vy,ay,z,vz,az]	107-115
		ofs << std::endl;
	}
////////////////////////
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mpc_main_debug");
	ros::NodeHandle nh;

	SaveFlag = false;

	joy_sub  = nh.subscribe("joy",1, joycallback);
	ref_sub  = nh.subscribe("pos_msg",1, refcallback); 
	esti_sub = nh.subscribe("crazyflie_data_msg",1, esticallback);
	mpc_pub  = nh.advertise<monitor_ishii::msgMPC>("mpc_data_msg",100);

	ros::spin();

	return 0;
}


/*
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include "GdnCont_main.h"
#include "estimate/msgCrazyflie_data.h"
#include "monitor_ishii/msgMPC.h"

double SW,pos[3],vel[3],lin[3],yaw;
double ctrl_input_phi = 0.0, ctrl_input_theta = 0.0,ctrl_input_psi = 0.0,ctrl_input_thrust = 0.0;	//change to thrust = m*g
bool ControlFlag = false;
int flag;

ros::Publisher mpc_pub;
ros::Subscriber joy_sub;
ros::Subscriber esti_sub;
ros::Time calc_start_time,calc_end_time;
double calc_time = 0.0;

sensor_msgs::Joy msg1;
estimate::msgCrazyflie_data msg2;
monitor_ishii::msgMPC mpc_msg;

void joycallback(const sensor_msgs::Joy& joy_msg)
{

        //ROS_INFO("JOY CALLBACK");	
        msg1 = joy_msg;

  	SW = msg1.buttons[1];
  
	if(1 == SW)
	{
		ControlFlag = false;
		flag = 1;
	}

	else if(0 == SW)
	{
		ControlFlag = true;
		flag = 0;
	}
}

void esticallback(const estimate::msgCrazyflie_data& esti_msg)
{

	msg2 = esti_msg;

	pos[0] = (double)msg2.vrpn_posx_msg;
	pos[1] = (double)msg2.vrpn_posy_msg;
	pos[2] = (double)msg2.vrpn_posz_msg;
	vel[0] = (double)msg2.vrpn_velx_msg;
	vel[1] = (double)msg2.vrpn_vely_msg;
	vel[2] = (double)msg2.vrpn_velz_msg;
	lin[0] = (double)msg2.vrpn_linx_msg;
	lin[1] = (double)msg2.vrpn_liny_msg;
	lin[2] = (double)msg2.vrpn_linz_msg;

	mpc_msg.controlflag = flag;

	if(false == ControlFlag)
	{
		CGdnCont reset;
		//ROS_INFO("Reset CALLBACK");
		reset.ResetCont(pos);

		ctrl_input_phi = 0.0;
		ctrl_input_theta = 0.0;
		ctrl_input_psi = 0.0;
		ctrl_input_thrust = 0.0;

	}
	else
	{
		//ROS_INFO("MPC CALLBACK");
		Eigen::Matrix<double,NUM_IMPUT*N,1> U;

		CGdnCont MPC;
		calc_start_time = ros::Time::now();
		U = MPC.GdnCont(U,pos,vel,lin);
		ctrl_input_phi = U(0,0);
		ctrl_input_theta = U(1,0);
		ctrl_input_psi = U(2,0);
		ctrl_input_thrust = U(3,0);
		calc_end_time = ros::Time::now();
		
		calc_time = (double)(calc_end_time.sec + calc_end_time.nsec * 0.000000001 - (calc_start_time.sec + calc_start_time.nsec * 0.000000001));
	}
 
        mpc_msg.phi  = ctrl_input_phi;	//制御入力を送信する
	mpc_msg.theta = ctrl_input_theta;
 	mpc_msg.psi = ctrl_input_psi;
	mpc_msg.thrust = ctrl_input_thrust;

        mpc_pub.publish(mpc_msg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mpc_main");
	ros::NodeHandle nh;

	joy_sub = nh.subscribe("joy",1, joycallback);
	esti_sub = nh.subscribe("crazyflie_data_msg",1, esticallback);
	mpc_pub = nh.advertise<monitor_ishii::msgMPC>("mpc_data_msg",100);
	ros::spin();

	return 0;
}*/
