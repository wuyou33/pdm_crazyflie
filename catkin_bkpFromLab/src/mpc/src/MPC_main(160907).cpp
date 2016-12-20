#include <ros/ros.h>
#include <sensor_msgs/Joy.h>
#include "GdnCont_main.h"
#include "estimate/msgCrazyflie_data.h"
#include "monitor_ishii/msgMPC.h"

double SW,pos[3],vel[3],lin[3];
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
	Eigen::Matrix<double,NUM_IMPUT*N,1> U;
	Eigen::Matrix<double,NUM_STATE,1> X_observer;
	Eigen::Matrix<double,NUM_STATE,1> U_observer;
	Eigen::Matrix<double,NUM_IMPUT*N + NUM_STATE + NUM_STATE,1> U_temp;
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
		U = reset.ResetCont(pos);

		ctrl_input_phi = 0.0;
		ctrl_input_theta = 0.0;
		ctrl_input_psi = 0.0;
		ctrl_input_thrust = 0.0;
	}
	else
	{
		//ROS_INFO("MPC CALLBACK");
		CGdnCont MPC;
		calc_start_time = ros::Time::now();

		U_temp = MPC.GdnCont(U,pos,vel,lin);	//オブザーバデバッグ用に書き換えてある(UとXとU_obのデータを配信するため)
		U = U_temp.block(0,0,80,1);		//
		X_observer = U_temp.block(80,0,9,1);	//
		U_observer = U_temp.block(89,0,9,1);	//

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

////////MPCデバッグ用
/*
	mpc_msg.U0 = U(0,0);
	mpc_msg.U1 = U(1,0);
	mpc_msg.U2 = U(2,0);
	mpc_msg.U3 = U(3,0);
	mpc_msg.U4 = U(4,0);
	mpc_msg.U5 = U(5,0);
	mpc_msg.U6 = U(6,0);
	mpc_msg.U7 = U(7,0);
	mpc_msg.U8 = U(8,0);
	mpc_msg.U9 = U(9,0);
	mpc_msg.U10 = U(10,0);
	mpc_msg.U11 = U(11,0);
	mpc_msg.U12 = U(12,0);
	mpc_msg.U13 = U(13,0);
	mpc_msg.U14 = U(14,0);
	mpc_msg.U15 = U(15,0);
	mpc_msg.U16 = U(16,0);
	mpc_msg.U17 = U(17,0);
	mpc_msg.U18 = U(18,0);
	mpc_msg.U19 = U(19,0);
	mpc_msg.U20 = U(20,0);
	mpc_msg.U21 = U(21,0);
	mpc_msg.U22 = U(22,0);
	mpc_msg.U23 = U(23,0);
	mpc_msg.U24 = U(24,0);
	mpc_msg.U25 = U(25,0);
	mpc_msg.U26 = U(26,0);
	mpc_msg.U27 = U(27,0);
	mpc_msg.U28 = U(28,0);
	mpc_msg.U29 = U(29,0);
	mpc_msg.U30 = U(30,0);
	mpc_msg.U31 = U(31,0);
	mpc_msg.U32 = U(32,0);
	mpc_msg.U33 = U(33,0);
	mpc_msg.U34 = U(34,0);
	mpc_msg.U35 = U(35,0);
	mpc_msg.U36 = U(36,0);
	mpc_msg.U37 = U(37,0);
	mpc_msg.U38 = U(38,0);
	mpc_msg.U39 = U(39,0);
	mpc_msg.U40 = U(40,0);
	mpc_msg.U41 = U(41,0);
	mpc_msg.U42 = U(42,0);
	mpc_msg.U43 = U(43,0);
	mpc_msg.U44 = U(44,0);
	mpc_msg.U45 = U(45,0);
	mpc_msg.U46 = U(46,0);
	mpc_msg.U47 = U(47,0);
	mpc_msg.U48 = U(48,0);
	mpc_msg.U49 = U(49,0);
	mpc_msg.U50 = U(50,0);
	mpc_msg.U51 = U(51,0);
	mpc_msg.U52 = U(52,0);
	mpc_msg.U53 = U(53,0);
	mpc_msg.U54 = U(54,0);
	mpc_msg.U55 = U(55,0);
	mpc_msg.U56 = U(56,0);
	mpc_msg.U57 = U(57,0);
	mpc_msg.U58 = U(58,0);
	mpc_msg.U59 = U(59,0);
	mpc_msg.U60 = U(60,0);
	mpc_msg.U61 = U(61,0);
	mpc_msg.U62 = U(62,0);
	mpc_msg.U63 = U(63,0);
	mpc_msg.U64 = U(64,0);
	mpc_msg.U65 = U(65,0);
	mpc_msg.U66 = U(66,0);
	mpc_msg.U67 = U(67,0);
	mpc_msg.U68 = U(68,0);
	mpc_msg.U69 = U(69,0);
	mpc_msg.U70 = U(70,0);
	mpc_msg.U71 = U(71,0);
	mpc_msg.U72 = U(72,0);
	mpc_msg.U73 = U(73,0);
	mpc_msg.U74 = U(74,0);
	mpc_msg.U75 = U(75,0);
	mpc_msg.U76 = U(76,0);
	mpc_msg.U77 = U(77,0);
	mpc_msg.U78 = U(78,0);
	mpc_msg.U79 = U(79,0);
*/
////////

////////同一次元オブザーバデバッグ用
	mpc_msg.Xe_ob_x = X_observer(0,0); 
	mpc_msg.Xe_ob_y = X_observer(1,0); 
	mpc_msg.Xe_ob_z = X_observer(2,0); 
	mpc_msg.Xe_ob_vx = X_observer(3,0); 
	mpc_msg.Xe_ob_vy = X_observer(4,0); 
	mpc_msg.Xe_ob_vz = X_observer(5,0); 
	mpc_msg.Xe_ob_ax = X_observer(6,0); 
	mpc_msg.Xe_ob_ay = X_observer(7,0); 
	mpc_msg.Xe_ob_az = X_observer(8,0); 

	mpc_msg.U_ob_x = U_observer(0,0);
	mpc_msg.U_ob_vx = U_observer(1,0);
	mpc_msg.U_ob_phi = U_observer(2,0);
	mpc_msg.U_ob_y = U_observer(3,0);
	mpc_msg.U_ob_vy = U_observer(4,0);
	mpc_msg.U_ob_theta = U_observer(5,0);
	mpc_msg.U_ob_z = U_observer(6,0);
	mpc_msg.U_ob_vz = U_observer(7,0);
	mpc_msg.U_ob_thrust = U_observer(8,0);
////////

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
