#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <geometry_msgs/PoseStamped.h>
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include <sensor_msgs/Joy.h>
#include <fstream>

std::ofstream ofs("modeling_data.txt"); //textメッセージ

long double cmd_vel_box[8];
long double vrpn_box[9];
long double cmd_vel_time = 0.0, first_time_cmdvel_sec = 0.0, first_time_cmdvel_nsec = 0.0, count_cmdvel = 0.0;
long double vrpn_time    = 0.0, first_time_vrpn_sec   = 0.0, first_time_vrpn_nsec   = 0.0, count_vrpn   = 0.0;

bool CmdvelSaveFlag = false, VrpnSaveFlag = false, CmdvelFirstTime = false, VrpnFirstTime = false;

hector_quadrotor_teleop::adv_cmd_vel cmd_msg;
geometry_msgs::PoseStamped vrpn_msg;

void chatterCallback_cmd_vel(const hector_quadrotor_teleop::adv_cmd_vel& msg_cmd_vel)	//cmd_velデータ
{
	CmdvelSaveFlag = true;
	CmdvelFirstTime = true;
	cmd_msg = msg_cmd_vel;

	if(CmdvelFirstTime == true && VrpnFirstTime == true)
		count_cmdvel++;	

	if(count_cmdvel == 1.0)
	{
		first_time_cmdvel_sec  =  (long double)(cmd_msg.header.stamp.sec);
		first_time_cmdvel_nsec =  (long double)(cmd_msg.header.stamp.nsec);
	}

//	cmd : 時間sec nsec 速度[x y z] 角度[ロール ピッチ ヨー]

	cmd_vel_box[0] = (long double)(cmd_msg.header.stamp.sec);
	cmd_vel_box[1] = (long double)(cmd_msg.header.stamp.nsec);
  
	cmd_vel_time = (long double)(cmd_vel_box[0] - first_time_cmdvel_sec + (cmd_vel_box[1] - first_time_cmdvel_nsec) * 0.000000001);

	cmd_vel_box[2] = cmd_msg.linear.x;
	cmd_vel_box[3] = cmd_msg.linear.y;
	cmd_vel_box[4] = cmd_msg.linear.z;
	cmd_vel_box[5] = cmd_msg.angular.x;
	cmd_vel_box[6] = cmd_msg.angular.y;
	cmd_vel_box[7] = cmd_msg.angular.z;
}

void chatterCallback_vrpn(const geometry_msgs::PoseStamped& msg_vrpn)	//vrpnデータ取得
{
	VrpnSaveFlag = true;
	VrpnFirstTime = true;
	vrpn_msg = msg_vrpn;

	if(CmdvelFirstTime == true && VrpnFirstTime == true)
	count_vrpn++;

	if(count_vrpn == 1.0)
	{
		first_time_vrpn_sec  =  (long double)(vrpn_msg.header.stamp.sec);
		first_time_vrpn_nsec =  (long double)(vrpn_msg.header.stamp.nsec);
	}

//	vrpn: 時間sec nsec 位置[x y z] 姿勢[x y z w]

	vrpn_box[0] = (long double)(vrpn_msg.header.stamp.sec);
	vrpn_box[1] = (long double)(vrpn_msg.header.stamp.nsec);
  
	vrpn_time = (long double)(vrpn_box[0] - first_time_vrpn_sec + (vrpn_box[1] - first_time_vrpn_nsec) * 0.000000001);

	vrpn_box[2] = vrpn_msg.pose.position.x;
	vrpn_box[3] = vrpn_msg.pose.position.y;
	vrpn_box[4] = vrpn_msg.pose.position.z;
	vrpn_box[5] = vrpn_msg.pose.orientation.x;
	vrpn_box[6] = vrpn_msg.pose.orientation.y;
	vrpn_box[7] = vrpn_msg.pose.orientation.z;
	vrpn_box[8] = vrpn_msg.pose.orientation.w;
}

void callback1(const ros::TimerEvent&)
{ 
	if(CmdvelSaveFlag == true && VrpnSaveFlag == true)
	{
		ofs << cmd_vel_time << " " << cmd_vel_box[2] << " " << cmd_vel_box[3] << " " << cmd_vel_box[4] << " " << cmd_vel_box[5] << " " << cmd_vel_box[6] << " " << cmd_vel_box[7] << " " << vrpn_time << " " << vrpn_box[2] << " " << vrpn_box[3] << " " << vrpn_box[4] << " " << vrpn_box[5] << " " << vrpn_box[6] << " " << vrpn_box[7] << " " << vrpn_box[8] << std::endl;

	}
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "modeling_data");
  ros::NodeHandle all;
 
  ros::Subscriber sub1 = all.subscribe("/crazyflie/cmd_vel", 1, chatterCallback_cmd_vel);
  ros::Subscriber sub2 = all.subscribe("/vrpn_client_node/Heli1/pose", 1, chatterCallback_vrpn);
  ros::Timer time1 = all.createTimer(ros::Duration(0.01), callback1);

  ros::spin();
  return 0;
}
