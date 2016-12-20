#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
//#include "GdnCont_main.h"

#include "GdnCont.h"
#include "GlobalDefs.h"
#include "estimate/msgCrazyflie_data.h"
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include "mpc/msgMPC.h"
#include "mpc/msgMPC_Data.h"
#include "generate_reference/msgReference.h"

MPCData data;

double SW = 0.0;
double ref_x = 0.0, ref_y = 0.0, ref_z = 0.0;
double calc_time = 0.0;
double ctrl_input_phi = 0.0, ctrl_input_theta = 0.0,ctrl_input_psi = 0.0,ctrl_input_thrust = 0.0;
double offset_phi, offset_the, offset_thr;
int ControlFlag = 0, RefPosFlag = 0;

ros::Publisher pub_mpc_input;
ros::Publisher pub_mpc_data;

ros::Subscriber sub_joy;
ros::Subscriber sub_ref;
ros::Subscriber sub_cmd;
ros::Subscriber sub_estdata;

ros::Time calc_start_time,calc_end_time;

mpc::msgMPC     mpc_input_msg;
mpc::msgMPC_Data mpc_data_msg;

// MPCによる誘導制御の実態
CGdnCont gdncontroller;

void joycallback(const sensor_msgs::Joy& joy_msg)
{
	if(1 == joy_msg.buttons[3])       ControlFlag = 0;
	else if (0 == joy_msg.buttons[3]) ControlFlag = 1;
}

void refcallback(const generate_reference::msgReference &ref_msg)
{	
		RefPosFlag = 0;
	if(1 == ref_msg.signal) {
		if(0.0 >= ref_msg.next_ref_z)
			ROS_INFO("Cannot change ref_z.");
		else{
			ref_x = (double)(ref_msg.next_ref_x);
			ref_y = (double)(ref_msg.next_ref_y);
			ref_z = (double)(ref_msg.next_ref_z);
			RefPosFlag = 1;
		}
	}
}

void cmdcallback(const hector_quadrotor_teleop::adv_cmd_vel& msg_cmd_vel)
{
	data.the    = msg_cmd_vel.linear.x;
	data.phi    = msg_cmd_vel.linear.y;
	data.thr    = msg_cmd_vel.linear.z;
	data.psi    = msg_cmd_vel.angular.z;
}

void esticallback(const estimate::msgCrazyflie_data& esti_msg)
{
	Eigen::Matrix<double,NUM_IMPUT*N,1> Us;

	Us         = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();

        // センサデータ抽出
	data.x       = (double)(esti_msg.vrpn_orix_msg);
	data.y       = (double)(esti_msg.vrpn_oriy_msg);
	data.z       = (double)(esti_msg.vrpn_oriz_msg);
	data.w       = (double)(esti_msg.vrpn_oriw_msg);
	data.xpos    = (double)(esti_msg.vrpn_posx_msg);
	data.ypos    = (double)(esti_msg.vrpn_posy_msg);
	data.zpos    = (double)(esti_msg.vrpn_posz_msg);
	data.xvel    = (double)(esti_msg.vrpn_velx_msg);
	data.yvel    = (double)(esti_msg.vrpn_vely_msg);
	data.zvel    = (double)(esti_msg.vrpn_velz_msg);
	data.yaw     = (double)(esti_msg.vrpn_yaw_msg);

	if(1 == ControlFlag)
	{
		calc_start_time = ros::Time::now();

		//デバッグ用に書き換えてある(UとXe_obとU_obとold_Xのデータを配信するため)
		Us     = gdncontroller.GdnCont(data,RefPosFlag,ref_x,ref_y,ref_z);

		//デバッグ用制御入力(デバッグ終了後に座標変換必要)
		ctrl_input_phi    = Us(0,0);
		ctrl_input_theta  = Us(1,0);
		ctrl_input_psi    = Us(2,0);
		ctrl_input_thrust = Us(3,0);

	}
	else{
          	// 制御器の初期化
	  	gdncontroller.ResetCont(data);

		ref_x = data.xpos;
		ref_y = data.ypos;
		ref_z = data.zpos;

		ctrl_input_phi    = 0.0;
		ctrl_input_theta  = 0.0;
		ctrl_input_psi    = 0.0;
		ctrl_input_thrust = 0.0;

		// 入力オフセット取得
		offset_phi = data.phi;
		offset_the = data.the;
		offset_thr = data.thr;

	}

        // 入力データの座標変換
        double c = cos(data.yaw);
        double s = sin(data.yaw);

        double the_tmp = c*ctrl_input_theta + s*ctrl_input_phi;
        double phi_tmp = -1.0*s*ctrl_input_theta + c*ctrl_input_phi;

	ctrl_input_phi   = phi_tmp;
	ctrl_input_theta = the_tmp;

        // 入力データのパブリッシュ
        mpc_input_msg.phi    = ctrl_input_phi   + offset_phi;	//制御入力を送信する
	mpc_input_msg.theta  = ctrl_input_theta + offset_the;
 	mpc_input_msg.psi    = ctrl_input_psi;
	mpc_input_msg.thrust = ctrl_input_thrust + offset_thr;

	mpc_input_msg.controlflag = ControlFlag;
	
	pub_mpc_input.publish(mpc_input_msg);

	// 制御データのパブリッシュ(モデリング、デバッグ、実験評価)
	mpc_data_msg.xpos	= esti_msg.vrpn_posx_msg; 
	mpc_data_msg.ypos	= esti_msg.vrpn_posy_msg; 
	mpc_data_msg.zpos	= esti_msg.vrpn_posz_msg; 

	mpc_data_msg.sw		= ControlFlag;

	mpc_data_msg.xpos_ref	= ref_x; 
	mpc_data_msg.ypos_ref	= ref_y; 
	mpc_data_msg.zpos_ref	= ref_z; 

        pub_mpc_data.publish(mpc_data_msg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mpc_main");
	ros::NodeHandle nh;

	sub_joy        = nh.subscribe("joy",1, joycallback);
	sub_ref        = nh.subscribe("pos_msg",1, refcallback); 
	sub_cmd        = nh.subscribe("/crazyflie/cmd_vel",1, cmdcallback); 
	sub_estdata    = nh.subscribe("crazyflie_data_msg",1, esticallback);
        pub_mpc_input  = nh.advertise<mpc::msgMPC>("mpc_input_msg",100);
	pub_mpc_data   = nh.advertise<mpc::msgMPC_Data>("mpc_data_msg",100);

	ros::spin();

	return 0;
}

/*
#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
//#include "GdnCont_main.h"

#include "GdnCont.h"
#include "GlobalDefs.h"
#include "estimate/msgCrazyflie_data.h"
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include "mpc/msgMPC.h"
#include "mpc/msgMPC_Data.h"
#include "generate_reference/msgReference.h"

MPCData data;

double SW = 0.0;
double ref_x = 0.0, ref_y = 0.0, ref_z = 0.0;
double calc_time = 0.0;
double ctrl_input_phi = 0.0, ctrl_input_theta = 0.0,ctrl_input_psi = 0.0,ctrl_input_thrust = 0.0;
double offset_phi, offset_the, offset_thr;
int ControlFlag = 0, RefPosFlag = 0;

ros::Publisher pub_mpc_input;
ros::Publisher pub_mpc_data;

ros::Subscriber sub_joy;
ros::Subscriber sub_ref;
ros::Subscriber sub_cmd;
ros::Subscriber sub_estdata;

ros::Time calc_start_time,calc_end_time;

mpc::msgMPC     mpc_input_msg;
mpc::msgMPC_Data mpc_data_msg;

// MPCによる誘導制御の実態
CGdnCont gdncontroller;

void joycallback(const sensor_msgs::Joy& joy_msg)
{
	if(1 == joy_msg.buttons[3])       ControlFlag = 0;
	else if (0 == joy_msg.buttons[3]) ControlFlag = 1;
}

void refcallback(const generate_reference::msgReference &ref_msg)
{	
		RefPosFlag = 0;
	if(1 == ref_msg.signal) {
		ref_x = (double)(ref_msg.next_ref_x);
		ref_y = (double)(ref_msg.next_ref_y);
		ref_z = (double)(ref_msg.next_ref_z);
		RefPosFlag = 1;
	}
}

void cmdcallback(const hector_quadrotor_teleop::adv_cmd_vel& msg_cmd_vel)
{
	data.the    = msg_cmd_vel.linear.x;
	data.phi    = msg_cmd_vel.linear.y;
	data.thr    = msg_cmd_vel.linear.z;
	data.psi    = msg_cmd_vel.angular.z;
}

void esticallback(const estimate::msgCrazyflie_data& esti_msg)
{
	Eigen::Matrix<double,NUM_IMPUT*N,1> Us;
	Eigen::Matrix<double,NUM_STATE,1> X_observer;
	Eigen::Matrix<double,NUM_STATE,1> U_observer;
	Eigen::Matrix<double,NUM_STATE,1> old_X;
	Eigen::Matrix<double,NUM_IMPUT*N + NUM_STATE + NUM_STATE + NUM_STATE,1> U_temp;

	Us         = Eigen::Matrix<double,NUM_IMPUT*N,1>::Zero();
	X_observer = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	U_observer = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	old_X      = Eigen::Matrix<double,NUM_STATE,1>::Zero();
	U_temp     = Eigen::Matrix<double,NUM_IMPUT*N + NUM_STATE + NUM_STATE + NUM_STATE,1>::Zero();

        // センサデータ抽出
	data.x       = (double)(esti_msg.vrpn_orix_msg);
	data.y       = (double)(esti_msg.vrpn_oriy_msg);
	data.z       = (double)(esti_msg.vrpn_oriz_msg);
	data.w       = (double)(esti_msg.vrpn_oriw_msg);
	data.xpos    = (double)(esti_msg.vrpn_posx_msg);
	data.ypos    = (double)(esti_msg.vrpn_posy_msg);
	data.zpos    = (double)(esti_msg.vrpn_posz_msg);
	data.xvel    = (double)(esti_msg.vrpn_velx_msg);
	data.yvel    = (double)(esti_msg.vrpn_vely_msg);
	data.zvel    = (double)(esti_msg.vrpn_velz_msg);
	data.yaw     = (double)(esti_msg.vrpn_yaw_msg);

	if(1 == ControlFlag)
	{
		calc_start_time = ros::Time::now();

		//デバッグ用に書き換えてある(UとXe_obとU_obとold_Xのデータを配信するため)
		U_temp     = gdncontroller.GdnCont(data,RefPosFlag,ref_x,ref_y,ref_z);
		Us         = U_temp.block(0,0,80,1);		//
		X_observer = U_temp.block(80,0,9,1);	//
		U_observer = U_temp.block(89,0,9,1);	//
		old_X      = U_temp.block(98,0,9,1);	//

		//デバッグ用制御入力(デバッグ終了後に座標変換必要)
		ctrl_input_phi    = Us(0,0);
		ctrl_input_theta  = Us(1,0);
		ctrl_input_psi    = Us(2,0);
		ctrl_input_thrust = Us(3,0);

	}
	else{
          	// 制御器の初期化
	  	gdncontroller.ResetCont(data);
		ctrl_input_phi    = 0.0;
		ctrl_input_theta  = 0.0;
		ctrl_input_psi    = 0.0;
		ctrl_input_thrust = 0.0;

		// 入力オフセット取得
		offset_phi = data.phi;
		offset_the = data.the;
		offset_thr = data.thr;

	}

        // 入力データの座標変換
        double c = cos(data.yaw);
        double s = sin(data.yaw);

        double the_tmp = c*ctrl_input_theta + s*ctrl_input_phi;
        double phi_tmp = -1.0*s*ctrl_input_theta + c*ctrl_input_phi;

	ctrl_input_phi   = phi_tmp;
	ctrl_input_theta = the_tmp;

        // 入力データのパブリッシュ
        mpc_input_msg.phi    = ctrl_input_phi   + offset_phi;	//制御入力を送信する
	mpc_input_msg.theta  = ctrl_input_theta + offset_the;
 	mpc_input_msg.psi    = ctrl_input_psi;
	mpc_input_msg.thrust = ctrl_input_thrust + offset_thr;

	mpc_input_msg.controlflag = ControlFlag;
	
	pub_mpc_input.publish(mpc_input_msg);

	// 制御データのパブリッシュ(モデリング、デバッグ用)
	//Debug1はpos3とctrl_input4
	//Debug2はpos3とctrl_input4とXe_ob9
	//Debug3はpos3とctrl_input4とXe_ob9とUs80とX9
	mpc_data_msg.p		= esti_msg.imu_angx_msg;
	mpc_data_msg.q		= esti_msg.imu_angy_msg;
	mpc_data_msg.r		= esti_msg.imu_angz_msg;
	mpc_data_msg.xacc	= esti_msg.imu_linx_msg;
	mpc_data_msg.yacc	= esti_msg.imu_liny_msg;
	mpc_data_msg.zacc	= esti_msg.imu_linz_msg;
	mpc_data_msg.ori_x	= esti_msg.vrpn_orix_msg; 
	mpc_data_msg.ori_y	= esti_msg.vrpn_oriy_msg; 
	mpc_data_msg.ori_z	= esti_msg.vrpn_oriz_msg; 
	mpc_data_msg.ori_w	= esti_msg.vrpn_oriw_msg; 
	mpc_data_msg.xpos	= esti_msg.vrpn_posx_msg; 
	mpc_data_msg.ypos	= esti_msg.vrpn_posy_msg; 
	mpc_data_msg.zpos	= esti_msg.vrpn_posz_msg; 
	mpc_data_msg.xvel	= esti_msg.vrpn_velx_msg; 
	mpc_data_msg.yvel	= esti_msg.vrpn_vely_msg; 
	mpc_data_msg.zvel	= esti_msg.vrpn_velz_msg; 
	mpc_data_msg.roll	= esti_msg.vrpn_roll_msg; 
	mpc_data_msg.pitch	= esti_msg.vrpn_pitch_msg; 
	mpc_data_msg.yaw	= esti_msg.vrpn_yaw_msg; 
	mpc_data_msg.uroll	= data.phi;
	mpc_data_msg.upitch	= data.the;
	mpc_data_msg.uthr	= data.thr;
	mpc_data_msg.uyaw	= data.psi;

	mpc_data_msg.sw		= ControlFlag;

	mpc_data_msg.ctrl_input_phi    = ctrl_input_phi;
	mpc_data_msg.ctrl_input_theta  = ctrl_input_theta;
	mpc_data_msg.ctrl_input_psi    = ctrl_input_psi;
	mpc_data_msg.ctrl_input_thrust = ctrl_input_thrust;

	mpc_data_msg.Xe_ob_x  = X_observer(0,0);
	mpc_data_msg.Xe_ob_y  = X_observer(1,0);
	mpc_data_msg.Xe_ob_z  = X_observer(2,0);
	mpc_data_msg.Xe_ob_vx = X_observer(3,0);
	mpc_data_msg.Xe_ob_vy = X_observer(4,0);
	mpc_data_msg.Xe_ob_vz = X_observer(5,0);
	mpc_data_msg.Xe_ob_ax = X_observer(6,0);
	mpc_data_msg.Xe_ob_ay = X_observer(7,0);
	mpc_data_msg.Xe_ob_az = X_observer(8,0);

	mpc_data_msg.U0  = Us(0,0);
	mpc_data_msg.U1  = Us(1,0);
	mpc_data_msg.U2  = Us(2,0);
	mpc_data_msg.U3  = Us(3,0);
	mpc_data_msg.U4  = Us(4,0);
	mpc_data_msg.U5  = Us(5,0);
	mpc_data_msg.U6  = Us(6,0);
	mpc_data_msg.U7  = Us(7,0);
	mpc_data_msg.U8  = Us(8,0);
	mpc_data_msg.U9  = Us(9,0);

	mpc_data_msg.U10 = Us(10,0);
	mpc_data_msg.U11 = Us(11,0);
	mpc_data_msg.U12 = Us(12,0);
	mpc_data_msg.U13 = Us(13,0);
	mpc_data_msg.U14 = Us(14,0);
	mpc_data_msg.U15 = Us(15,0);
	mpc_data_msg.U16 = Us(16,0);
	mpc_data_msg.U17 = Us(17,0);
	mpc_data_msg.U18 = Us(18,0);
	mpc_data_msg.U19 = Us(19,0);

	mpc_data_msg.U20 = Us(20,0);
	mpc_data_msg.U21 = Us(21,0);
	mpc_data_msg.U22 = Us(22,0);
	mpc_data_msg.U23 = Us(23,0);
	mpc_data_msg.U24 = Us(24,0);
	mpc_data_msg.U25 = Us(25,0);
	mpc_data_msg.U26 = Us(26,0);
	mpc_data_msg.U27 = Us(27,0);
	mpc_data_msg.U28 = Us(28,0);
	mpc_data_msg.U29 = Us(29,0);

	mpc_data_msg.U30 = Us(30,0);
	mpc_data_msg.U31 = Us(31,0);
	mpc_data_msg.U32 = Us(32,0);
	mpc_data_msg.U33 = Us(33,0);
	mpc_data_msg.U34 = Us(34,0);
	mpc_data_msg.U35 = Us(35,0);
	mpc_data_msg.U36 = Us(36,0);
	mpc_data_msg.U37 = Us(37,0);
	mpc_data_msg.U38 = Us(38,0);
	mpc_data_msg.U39 = Us(39,0);

	mpc_data_msg.U40 = Us(40,0);
	mpc_data_msg.U41 = Us(41,0);
	mpc_data_msg.U42 = Us(42,0);
	mpc_data_msg.U43 = Us(43,0);
	mpc_data_msg.U44 = Us(44,0);
	mpc_data_msg.U45 = Us(45,0);
	mpc_data_msg.U46 = Us(46,0);
	mpc_data_msg.U47 = Us(47,0);
	mpc_data_msg.U48 = Us(48,0);
	mpc_data_msg.U49 = Us(49,0);

	mpc_data_msg.U50 = Us(50,0);
	mpc_data_msg.U51 = Us(51,0);
	mpc_data_msg.U52 = Us(52,0);
	mpc_data_msg.U53 = Us(53,0);
	mpc_data_msg.U54 = Us(54,0);
	mpc_data_msg.U55 = Us(55,0);
	mpc_data_msg.U56 = Us(56,0);
	mpc_data_msg.U57 = Us(57,0);
	mpc_data_msg.U58 = Us(58,0);
	mpc_data_msg.U59 = Us(59,0);

	mpc_data_msg.U60 = Us(60,0);
	mpc_data_msg.U61 = Us(61,0);
	mpc_data_msg.U62 = Us(62,0);
	mpc_data_msg.U63 = Us(63,0);
	mpc_data_msg.U64 = Us(64,0);
	mpc_data_msg.U65 = Us(65,0);
	mpc_data_msg.U66 = Us(66,0);
	mpc_data_msg.U67 = Us(67,0);
	mpc_data_msg.U68 = Us(68,0);
	mpc_data_msg.U69 = Us(69,0);

	mpc_data_msg.U70 = Us(70,0);
	mpc_data_msg.U71 = Us(71,0);
	mpc_data_msg.U72 = Us(72,0);
	mpc_data_msg.U73 = Us(73,0);
	mpc_data_msg.U74 = Us(74,0);
	mpc_data_msg.U75 = Us(75,0);
	mpc_data_msg.U76 = Us(76,0);
	mpc_data_msg.U77 = Us(77,0);
	mpc_data_msg.U78 = Us(78,0);
	mpc_data_msg.U79 = Us(79,0);

	mpc_data_msg.old_X_x  = old_X(0,0);
	mpc_data_msg.old_X_y  = old_X(1,0);
	mpc_data_msg.old_X_z  = old_X(2,0);
	mpc_data_msg.old_X_vx = old_X(3,0);
	mpc_data_msg.old_X_vy = old_X(4,0);
	mpc_data_msg.old_X_vz = old_X(5,0);
	mpc_data_msg.old_X_ax = old_X(6,0);
	mpc_data_msg.old_X_ay = old_X(7,0);
	mpc_data_msg.old_X_az = old_X(8,0);

        pub_mpc_data.publish(mpc_data_msg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mpc_main");
	ros::NodeHandle nh;

	sub_joy        = nh.subscribe("joy",1, joycallback);
	sub_ref        = nh.subscribe("pos_msg",1, refcallback); 
	sub_cmd        = nh.subscribe("/crazyflie/cmd_vel",1, cmdcallback); 
	sub_estdata    = nh.subscribe("crazyflie_data_msg",1, esticallback);
        pub_mpc_input  = nh.advertise<mpc::msgMPC>("mpc_input_msg",100);
	pub_mpc_data   = nh.advertise<mpc::msgMPC_Data>("mpc_data_msg",100);

	ros::spin();

	return 0;
}
*/
