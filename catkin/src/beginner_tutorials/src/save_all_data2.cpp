#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/Imu.h>
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/MagneticField.h>
#include <std_msgs/Float32.h>
#include <fstream>

std::ofstream ofs("Save_all_data2.txt"); //textメッセージ

long double imu_box[8];
long double cmd_vel_box[8];
long double joy_box[13];
long double mag_box[5];
long double pre_box;
long double vrpn_box[9];
long double imu_time     = 0.0, first_time_imu_sec    = 0.0, first_time_imu_nsec    = 0.0, count_imu    = 0.0;
long double cmd_vel_time = 0.0, first_time_cmdvel_sec = 0.0, first_time_cmdvel_nsec = 0.0, count_cmdvel = 0.0;
long double joy_time     = 0.0, first_time_joy_sec    = 0.0, first_time_joy_nsec    = 0.0, count_joy    = 0.0;
long double mag_time     = 0.0, first_time_mag_sec    = 0.0, first_time_mag_nsec    = 0.0, count_mag    = 0.0;
long double vrpn_time    = 0.0, first_time_vrpn_sec   = 0.0, first_time_vrpn_nsec   = 0.0, count_vrpn   = 0.0;

bool SaveStartFlag = false, CmdvelFirstTime = false, JoyFirstTime  = false;
bool MagFirstTime  = false, PreFirstTime    = false, VrpnFirstTime = false;

sensor_msgs::Imu msg1;
hector_quadrotor_teleop::adv_cmd_vel msg2;
sensor_msgs::Joy msg3;
sensor_msgs::MagneticField msg4;
std_msgs::Float32 msg5;
geometry_msgs::PoseStamped msg6;

void chatterCallback_imu(const sensor_msgs::Imu &msg_imu)	//imuデータ取得
{
	SaveStartFlag = true;
	msg1 = msg_imu;
  
	if(SaveStartFlag == true && CmdvelFirstTime == true && JoyFirstTime == true && MagFirstTime == true && PreFirstTime == true && VrpnFirstTime == true)
	count_imu++;

	if(count_imu == 1.0)
	{
		first_time_imu_sec  =  (long double)(msg1.header.stamp.sec);
		first_time_imu_nsec =  (long double)(msg1.header.stamp.nsec);
	}

//	imu : 時間sec nsec 角速度[x y z] 加速度[x y z]

	imu_box[0] = (long double)(msg1.header.stamp.sec); 
	imu_box[1] = (long double)(msg1.header.stamp.nsec);

	imu_time = (long double)(imu_box[0] - first_time_imu_sec + (imu_box[1] - first_time_imu_nsec) * 0.000000001);

	imu_box[2] = msg1.angular_velocity.x;
	imu_box[3] = msg1.angular_velocity.y;
	imu_box[4] = msg1.angular_velocity.z;
	imu_box[5] = msg1.linear_acceleration.x;
	imu_box[6] = msg1.linear_acceleration.y;
	imu_box[7] = msg1.linear_acceleration.z;
}

void chatterCallback_cmd_vel(const hector_quadrotor_teleop::adv_cmd_vel& msg_cmd_vel)	//cmd_velデータ
{
	CmdvelFirstTime = true;
	msg2 = msg_cmd_vel;

	if(SaveStartFlag == true && CmdvelFirstTime == true && JoyFirstTime == true && MagFirstTime == true && PreFirstTime == true, VrpnFirstTime == true)
	count_cmdvel++;

	if(count_cmdvel == 1.0)
	{
		first_time_cmdvel_sec  =  (long double)(msg2.header.stamp.sec);
		first_time_cmdvel_nsec =  (long double)(msg2.header.stamp.nsec);
	}

//	cmd : 時間sec nsec 速度[x y z] 角度[ロール ピッチ ヨー]


	cmd_vel_box[0] = (long double)(msg2.header.stamp.sec);
	cmd_vel_box[1] = (long double)(msg2.header.stamp.nsec);
  
	cmd_vel_time = (long double)(cmd_vel_box[0] - first_time_cmdvel_sec + (cmd_vel_box[1] - first_time_cmdvel_nsec) * 0.000000001);

	cmd_vel_box[2] = msg2.linear.x;
	cmd_vel_box[3] = msg2.linear.y;
	cmd_vel_box[4] = msg2.linear.z;
	cmd_vel_box[5] = msg2.angular.x;
	cmd_vel_box[6] = msg2.angular.y;
	cmd_vel_box[7] = msg2.angular.z;
}

void chatterCallback_joy(const sensor_msgs::Joy& msg_joy)	//joyデータ取得
{
	JoyFirstTime = true;
	msg3 = msg_joy;

	if(SaveStartFlag == true && CmdvelFirstTime == true && JoyFirstTime == true && MagFirstTime == true && PreFirstTime == true,VrpnFirstTime == true)
	count_joy++;

	if(count_joy == 1.0)
	{
		first_time_joy_sec  = (long double)(msg3.header.stamp.sec);
		first_time_joy_nsec = (long double)(msg3.header.stamp.nsec);
	}

//	joy : 時間sec nsec 軸の操作量[6つ] ボタン[5つ]


	joy_box[0] = (long double)(msg3.header.stamp.sec);
	joy_box[1] = (long double)(msg3.header.stamp.nsec);

	joy_time = (long double)(joy_box[0] - first_time_joy_sec + (joy_box[1] - first_time_joy_nsec) * 0.000000001);

	joy_box[2]  = msg3.axes[0];
	joy_box[3]  = msg3.axes[1];
	joy_box[4]  = msg3.axes[2];
	joy_box[5]  = msg3.axes[3];
	joy_box[6]  = msg3.axes[4];
	joy_box[7]  = msg3.axes[5];
	joy_box[8]  = msg3.buttons[0];
	joy_box[9]  = msg3.buttons[1];
	joy_box[10] = msg3.buttons[2];
	joy_box[11] = msg3.buttons[3];
	joy_box[12] = msg3.buttons[4];
}

void chatterCallback_mag(const sensor_msgs::MagneticField& msg_mag)	//magnetic_fieldデータ取得
{
	MagFirstTime = true;
	msg4 = msg_mag;

	if(SaveStartFlag == true && CmdvelFirstTime == true && JoyFirstTime == true && MagFirstTime == true && PreFirstTime == true,VrpnFirstTime == true)
	count_mag++;

	if(count_mag == 1.0)
	{
		first_time_mag_sec  =  (long double)(msg4.header.stamp.sec);
		first_time_mag_nsec =  (long double)(msg4.header.stamp.nsec);
	}

//	mag : 時間sec nsec 磁場[x y z]

	mag_box[0] = (long double)(msg4.header.stamp.sec);
	mag_box[1] = (long double)(msg4.header.stamp.nsec);
 
	mag_time = (long double)(mag_box[0] - first_time_mag_sec + (mag_box[1] - first_time_mag_nsec) * 0.000000001);

	mag_box[2] = msg4.magnetic_field.x;
	mag_box[3] = msg4.magnetic_field.y;
	mag_box[4] = msg4.magnetic_field.z;
}
 
void chatterCallback_pre(const std_msgs::Float32& msg_pre)	//pressureデータ
{
	PreFirstTime = true;
	msg5 = msg_pre;

//	pre : 大気圧

	pre_box = msg5.data;
}

void chatterCallback_vrpn(const geometry_msgs::PoseStamped& msg_vrpn)	//vrpnデータ取得
{
	VrpnFirstTime = true;
	msg6 = msg_vrpn;

	if(SaveStartFlag == true && CmdvelFirstTime == true && JoyFirstTime == true && MagFirstTime == true && PreFirstTime == true,VrpnFirstTime == true)
	count_vrpn++;

	if(count_vrpn == 1.0)
	{
		first_time_vrpn_sec  =  (long double)(msg6.header.stamp.sec);
		first_time_vrpn_nsec =  (long double)(msg6.header.stamp.nsec);
	}

//	vrpn: 時間sec nsec 位置[x y z] 姿勢[x y z w]

	vrpn_box[0] = (long double)(msg6.header.stamp.sec);
	vrpn_box[1] = (long double)(msg6.header.stamp.nsec);
  
	vrpn_time = (long double)(vrpn_box[0] - first_time_vrpn_sec + (vrpn_box[1] - first_time_vrpn_nsec) * 0.000000001);

	vrpn_box[2] = msg6.pose.position.x;
	vrpn_box[3] = msg6.pose.position.y;
	vrpn_box[4] = msg6.pose.position.z;
	vrpn_box[5] = msg6.pose.orientation.x;
	vrpn_box[6] = msg6.pose.orientation.y;
	vrpn_box[7] = msg6.pose.orientation.z;
	vrpn_box[8] = msg6.pose.orientation.w;
}

void callback1(const ros::TimerEvent&)
{ 
	if(SaveStartFlag == true && CmdvelFirstTime == true && JoyFirstTime == true && MagFirstTime == true && PreFirstTime == true,VrpnFirstTime == true)
	{
		ofs << imu_time << " " << imu_box[2] << " " << imu_box[3] << " " << imu_box[4] << " " << imu_box[5] << " " << imu_box[6] << " " << imu_box[7] << " " << cmd_vel_time << " " << cmd_vel_box[2] << " " << cmd_vel_box[3] << " " << cmd_vel_box[4] << " " << cmd_vel_box[5] << " " << cmd_vel_box[6] << " " << cmd_vel_box[7] << " " << joy_time << " " << joy_box[2] << " " << joy_box[3] << " " << joy_box[4] << " " << joy_box[5] << " " << joy_box[6] << " " << joy_box[7] << " " << mag_time << " " << mag_box[2] << " " << mag_box[3] << " " << mag_box[4] << " " << pre_box << " " << vrpn_time << " " << vrpn_box[2] << " " << vrpn_box[3] << " " << vrpn_box[4] << " " << vrpn_box[5] << " " << vrpn_box[6] << " " << vrpn_box[7] << " " << vrpn_box[8] << std::endl;

	}
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "all_data4");
  ros::NodeHandle all;
 
  ros::Subscriber sub1 = all.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  ros::Subscriber sub2 = all.subscribe("/crazyflie/cmd_vel", 1, chatterCallback_cmd_vel);
  ros::Subscriber sub3 = all.subscribe("joy", 1, chatterCallback_joy);
  ros::Subscriber sub4 = all.subscribe("/crazyflie/magnetic_field", 1, chatterCallback_mag);
  ros::Subscriber sub5 = all.subscribe("/crazyflie/pressure", 1, chatterCallback_pre);
  ros::Subscriber sub6 = all.subscribe("/vrpn_client_node/Heli1/pose", 1, chatterCallback_vrpn);
  ros::Timer time1 = all.createTimer(ros::Duration(0.01), callback1);

  ros::spin();
  return 0;
}
