/*#include <ros/ros.h>
#include <geometry_msgs/PoseStamped.h>
#include <sensor_msgs/Imu.h>

long double vrpn_box[9],vrpn_old_box[9],imu_box[8];
long double vrpn_time,imu_time;
long double pos_x = 0.0,pos_y = 0.0,pos_z = 0.0,vel_x = 0.0,vel_y = 0.0,vel_z = 0.0;
long double first_time_vrpn,first_time_imu;

geometry_msgs::PoseStamped msg;
sensor_msgs::Imu msg1;
bool StartFlag,VrpnFirstTime = true,ImuFirstTime;


void chatterCallback_vrpn(const geometry_msgs::PoseStamped& msg_vrpn)	//vrpnデータ取得
{
  StartFlag = true;
  msg = msg_vrpn;

  if(StartFlag == true){
	  if(VrpnFirstTime == true){
	    first_time_vrpn =  (long double)(msg.header.stamp.sec);
	    VrpnFirstTime = false;
	  }

	  vrpn_box[0] = (long double)(msg.header.stamp.sec);
	  vrpn_box[1] = (long double)(msg.header.stamp.nsec);
	  
	  vrpn_time = (long double)(vrpn_box[0] - first_time_vrpn + vrpn_box[1] * 0.000000001);
	
	  vrpn_box[2] = msg.pose.position.x;
	  vrpn_box[3] = msg.pose.position.y;
	  vrpn_box[4] = msg.pose.position.z;
	  vrpn_box[5] = msg.pose.orientation.x;
	  vrpn_box[6] = msg.pose.orientation.y;
	  vrpn_box[7] = msg.pose.orientation.z;
	  vrpn_box[8] = msg.pose.orientation.w;
  }
}

void chatterCallback_imu(const sensor_msgs::Imu &msg_imu)	//imuデータ取得
{
  StartFlag = true;
  msg1 = msg_imu;
  
  if (StartFlag == true){
	  if(ImuFirstTime == true){
	    first_time_imu =  (long double)(msg1.header.stamp.sec);
	    ImuFirstTime = false;
	  }

	  imu_box[0] = (long double)(msg1.header.stamp.sec); 
	  imu_box[1] = (long double)(msg1.header.stamp.nsec);
	
	  imu_time = (long double)(imu_box[0] - first_time_imu + imu_box[1] * 0.000000001);
	
	  imu_box[2] = msg1.angular_velocity.x;
	  imu_box[3] = msg1.angular_velocity.y;
	  imu_box[4] = msg1.angular_velocity.z;
	  imu_box[5] = msg1.linear_acceleration.x;
	  imu_box[6] = msg1.linear_acceleration.y;
	  imu_box[7] = msg1.linear_acceleration.z;
  }
}

void callback1(const ros::TimerEvent&)
{ 
  
	//vrpn: 時間sec nsec 位置[x y z] 姿勢[x y z w]
  if(StartFlag == true){
	  pos_x = vrpn_box[2];
	  pos_y = vrpn_box[3];
	  pos_z = vrpn_box[4];
	  vel_x = (vrpn_box[2] - vrpn_old_box[2])/0.01;
	  vel_y = (vrpn_box[3] - vrpn_old_box[3])/0.01;
	  vel_z = (vrpn_box[4] - vrpn_old_box[4])/0.01;
  }
  StartFlag = false;
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "estimate");
  ros::NodeHandle mocap;

  StartFlag = false;

  ros::Subscriber sub = mocap.subscribe("/vrpn_client_node/Heli1/pose", 1, chatterCallback_vrpn);
  ros::Subscriber sub1 = mocap.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  ros::Timer time1 = mocap.createTimer(ros::Duration(0.01), callback1);

  ros::spin();
  return 0;
}
*/


#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include "beginner_tutorials/msgCrazyflie_data.h"

long double imu_box[8],imu_old_box[8];
long double imu_time,imu_old_time;
long double vel_x = 0;
long double first_time_imu;

sensor_msgs::Imu msg1;
bool StartFlag,first_timeFlag = true;


void chatterCallback_imu(const sensor_msgs::Imu &msg_imu)	//imuデータ取得
{
  StartFlag = true;
  msg1 = msg_imu;
  
  if (StartFlag == true){
	if(first_timeFlag == true){
		first_time_imu =  (long double)(msg1.header.stamp.sec);
	}

	for(int i = 0;i <= 8;i++){
		imu_old_box[i] = imu_box[i];
  	}

	imu_box[0] = (long double)(msg1.header.stamp.sec); 
	imu_box[1] = (long double)(msg1.header.stamp.nsec);

	imu_time = (long double)(imu_box[0] - first_time_imu + imu_box[1] * 0.000000001);

	imu_box[2] = msg1.angular_velocity.x;
	imu_box[3] = msg1.angular_velocity.y;
	imu_box[4] = msg1.angular_velocity.z;
	imu_box[5] = msg1.linear_acceleration.x;
	imu_box[6] = msg1.linear_acceleration.y;
	imu_box[7] = msg1.linear_acceleration.z;
  }
}

void callback1(const ros::TimerEvent&)
{ 
  if(StartFlag == true){
  	vel_x = (imu_box[2] - imu_old_box[2])/0.01;

	std::cout << vel_x << ' ' << imu_box[2] << ' ' << imu_old_box[2] << std::endl;
  }
  StartFlag = false;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "estimate");
  ros::NodeHandle esti;

  StartFlag = false;
 
  ros::Subscriber sub1 = esti.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  ros::Publisher pub1 = esti.advertise<beginner_tutorials::msgCrazyflie_data>("crazyflie_data_msg",100);
  ros::Timer time1 = esti.createTimer(ros::Duration(0.01), callback1);

  beginner_tutorials::msgCrazyflie_data cf_msg;
  cf_msg.imu_msg = imu_box[2];
  
  pub1.publish(cf_msg);

  ros::spin();
  return 0;
}

