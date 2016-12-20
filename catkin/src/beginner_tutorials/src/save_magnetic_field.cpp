#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/MagneticField.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
  std::ofstream ofs("TS_magnetic_field.txt"); //textメッセージ	
void chatterCallback(const sensor_msgs::MagneticField& msg)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用

  ofs << msg.header.stamp.sec << "," << msg.header.stamp.nsec << "," << msg.magnetic_field.x << "," << msg.magnetic_field.y << "," << msg.magnetic_field.z <<std::endl;	//テキストに追加
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_MagneticField");

  ros::NodeHandle mf;

  ros::Subscriber sub = mf.subscribe("/crazyflie/magnetic_field", 1, chatterCallback);
  
  ros::spin();

  return 0;
}

