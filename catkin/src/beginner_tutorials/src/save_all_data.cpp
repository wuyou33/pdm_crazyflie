///////////Durationを使っている(for文でない)/////////////////////

#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Imu.h>
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/MagneticField.h>
#include <std_msgs/Float32.h>
#include <fstream>

std::ofstream ofs("All_data_save2.txt"); //textメッセージ
sensor_msgs::Imu msg1;
hector_quadrotor_teleop::adv_cmd_vel msg2;
sensor_msgs::Joy msg3;
sensor_msgs::MagneticField msg4;
std_msgs::Float32 msg5;
bool SaveStartFlag;

void chatterCallback_imu(const sensor_msgs::Imu& msg_imu)	//imuデータ
{
  SaveStartFlag = true; 
  msg1 = msg_imu;
}

void chatterCallback_cmd_vel(const hector_quadrotor_teleop::adv_cmd_vel& msg_cmd_vel)	//cmd_velデータ
{
  msg2 = msg_cmd_vel;
  }
void chatterCallback_joy(const sensor_msgs::Joy& msg_joy)	//joyデータ
{ 
  msg3 = msg_joy;
}


void chatterCallback_mag(const sensor_msgs::MagneticField& msg_magneticfield)	//magnetic_fieldデータ
{
  msg4 = msg_magneticfield;
}

void chatterCallback_pre(const std_msgs::Float32& msg_pressure)	//pressureデータ
{
  msg5 = msg_pressure;
}

void callback1(const ros::TimerEvent&)
{
  if(SaveStartFlag == true){
   // std::cout << "OK" << std::endl;
    ofs << "imu : " << msg1.header.stamp.sec << " " << msg1.header.stamp.nsec << " " << msg1.angular_velocity.x << " " << msg1.angular_velocity.y << " " <<  msg1.angular_velocity.z << " " << msg1.linear_acceleration.x << " " << msg1.linear_acceleration.y << " " << msg1.linear_acceleration.z << std::endl;
    
    ofs << "cmd : " << msg2.header.stamp.sec << " " << msg2.header.stamp.nsec << " " << msg2.linear.x << " "<< msg2.linear.y << " "<< msg2.linear.z << " "<< msg2.angular.x << " "<< msg2.angular.y << " "<< msg2.angular.z << std::endl;
    
    ofs << "joy : " << msg3.header.stamp.sec << " " << msg3.header.stamp.nsec << " " << msg3.axes[0] << " " << msg3.axes[1] << " " << msg3.axes[2] << " " << msg3.axes[3] << " "  << msg3.axes[4] << " " << msg3.axes[5] << std::endl;	
    
    ofs << "mag : " << msg4.header.stamp.sec << " " << msg4.header.stamp.nsec << " " << msg4.magnetic_field.x << " " << msg4.magnetic_field.y << " " <<  msg4.magnetic_field.z << std::endl;
    
    ofs << "pre : " << msg5.data << std::endl << std::endl;
  }
  SaveStartFlag = false;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "all_data2");
  ros::NodeHandle all;
  SaveStartFlag = false;
  ros::Subscriber sub1 = all.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  ros::Subscriber sub2 = all.subscribe("/crazyflie/cmd_vel", 1, chatterCallback_cmd_vel);
  ros::Subscriber sub3 = all.subscribe("/crazyflie/joy", 1, chatterCallback_joy);
  ros::Subscriber sub4 = all.subscribe("/crazyflie/magnetic_field", 1, chatterCallback_mag);
  ros::Subscriber sub5 = all.subscribe("/crazyflie/pressure", 1, chatterCallback_pre);
  ros::Timer time1 = all.createTimer(ros::Duration(0.01), callback1);

  ros::spin();

  return 0;
}


/*#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/MagneticField.h>
#include <std_msgs/Float32.h>
#include <fstream>

std::ofstream ofs("Save_all_data.txt"); //textメッセージ
sensor_msgs::Imu msg1;
sensor_msgs::Joy msg2;
sensor_msgs::MagneticField msg3;
std_msgs::Float32 msg4;
bool SaveStartFlag;

void chatterCallback_imu(const sensor_msgs::Imu& msg_imu)	//imuデータ
{
	msg1 = msg_imu;
}

void chatterCallback_joy(const sensor_msgs::Joy& msg_joy)	//joyデータ
{
	msg2 = msg_joy;
}

void chatterCallback_mag(const sensor_msgs::MagneticField& msg_magneticfield)	//magnetic_fieldデータ
{
	SaveStartFlag = true;
	msg3 = msg_magneticfield;
}

void chatterCallback_pre(const std_msgs::Float32& msg_pressure)	//pressureデータ
{
	msg4 = msg_pressure;
}

void callback1(const ros::TimerEvent&)
{
	if(SaveStartFlag == true){
		ofs << "imu : " << msg1.header.stamp.sec << " " << msg1.header.stamp.nsec << " " << msg1.angular_velocity.x << " " << msg1.angular_velocity.y << " " <<  msg1.angular_velocity.z << " " << msg1.linear_acceleration.x << " " << msg1.linear_acceleration.y << " " << msg1.linear_acceleration.z << std::endl;
		ofs << "joy : " << msg2.header.stamp.sec << " " << msg2.header.stamp.nsec << " " << msg2.axes[0] << " " << msg2.axes[1] << " " << msg2.axes[2] << " " << msg2.axes[3] << " " << msg2.axes[4] << " " << msg2.axes[5] << " " << msg2.buttons[0] << " " << msg2.buttons[1] << " " << msg2.buttons[2] << " " << msg2.buttons[3] << " " << msg2.buttons[4] << std::endl;
		ofs << "mag : " << msg3.header.stamp.sec << " " << msg3.header.stamp.nsec << " " << msg3.magnetic_field.x << " " << msg3.magnetic_field.y << " " << msg3.magnetic_field.z << std::endl;
		ofs << "pre : " << msg4.data << std::endl << std::endl;
	}
	SaveStartFlag == false;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "save_all_data");

  ros::NodeHandle all;

  SaveStartFlag = false;

  ros::Subscriber sub1 = all.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  ros::Subscriber sub2 = all.subscribe("/crazyflie/joy", 1, chatterCallback_joy);
  ros::Subscriber sub3 = all.subscribe("/crazyflie/magnetic_field", 1, chatterCallback_mag);
  ros::Subscriber sub4 = all.subscribe("/crazyflie/pressure", 1, chatterCallback_pre);
  ros::Timer time1 = all.createTimer(ros::Duration(0.01), callback1);

  ros::spin();

  return 0;
}*/
