#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Temperature.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
  std::ofstream ofs("TS.txt"); //textメッセージ	
void chatterCallback(const sensor_msgs::Temperature& msg)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用

  ofs << msg.header.stamp.sec << "," << msg.temperature << "," << msg.variance <<std::endl;	//テキストに追加
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_temperature");

  ros::NodeHandle snt;

  ros::Subscriber sub = snt.subscribe("/crazyflie/temperature", 1, chatterCallback);
  
  ros::spin();

  return 0;
}

