#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Imu.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
std::ofstream ofs("Timer_imu.txt"); //textメッセージ
sensor_msgs::Imu msg;
bool SaveStartFlag;
void chatterCallback(const sensor_msgs::Imu& msg_imu)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用
  SaveStartFlag = true;
  msg = msg_imu;
  //ofs << msg.header.stamp.sec << "," << msg.header.stamp.nsec << "," << msg.angular_velocity.x << "," << msg.angular_velocity.y << "," <<  msg.angular_velocity.z <<   "," << msg. linear_acceleration.x << "," << msg. linear_acceleration.y << "," << msg. linear_acceleration.z <<std::endl;	//テキストに追加
}

void callback1(const ros::TimerEvent&)
{
  if(SaveStartFlag==true){
    ROS_INFO("Callback 1 triggered");
    ofs << msg.header.stamp.sec << "," << msg.header.stamp.nsec << "," << msg.angular_velocity.x << "," << msg.angular_velocity.y << "," <<  msg.angular_velocity.z <<   "," << msg. linear_acceleration.x << "," << msg. linear_acceleration.y << "," << msg. linear_acceleration.z <<std::endl;
    SaveStartFlag = false;
  }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_imu");
  ros::NodeHandle imuu;
  SaveStartFlag = false;
  ros::Subscriber sub = imuu.subscribe("/crazyflie/imu", 1, chatterCallback);
  ros::Timer time1 = imuu.createTimer(ros::Duration(0.1), callback1);
  
  ros::spin();

  return 0;
}

