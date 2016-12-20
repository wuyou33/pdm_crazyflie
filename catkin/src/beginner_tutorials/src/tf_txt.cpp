#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Imu.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
  std::ofstream ofs("TS.txt"); //textメッセージ	
void chatterCallback(const sensor_msgs::Imu& msg)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用

  ofs << msg.header.stamp.sec << "," << msg.orientation <<std::endl;	//テキストに追加
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_imu");

  ros::NodeHandle anh;

  ros::Subscriber sub = anh.subscribe("/crazyflie/imu", 1, chatterCallback);
  
  ros::spin();

  return 0;
}

