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
		U = MPC.GdnCont(U,pos,vel,lin);
		ctrl_input_phi = U(0,0);
		ctrl_input_theta = U(1,0);
		ctrl_input_psi = U(2,0);
		ctrl_input_thrust = U(3,0);
		calc_end_time = ros::Time::now();
		
		calc_time = (double)(calc_end_time.sec + calc_end_time.nsec * 0.000000001 - (calc_start_time.sec + calc_start_time.nsec * 0.000000001));
	}
 
        mpc_msg.phi  = ctrl_input_phi;	//êßå‰ì¸óÕÇëóêMÇ∑ÇÈ
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
 
        mpc_msg.phi  = ctrl_input_phi;	//êßå‰ì¸óÕÇëóêMÇ∑ÇÈ
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
