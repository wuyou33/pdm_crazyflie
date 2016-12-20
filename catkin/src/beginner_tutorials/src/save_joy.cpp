#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Joy.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
  std::ofstream ofs("TS_joy.txt"); //textメッセージ	
void chatterCallback(const sensor_msgs::Joy& msg)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用

  ofs << msg.header.stamp.sec << "," << msg.header.stamp.nsec << "," << msg.axes[0] << "," << msg.axes[1] << "," << msg.axes[2] << "," << msg.axes[3] << "," << msg.axes[4] << "," << msg.axes[5] << "," << msg.buttons[0] << "," << msg.buttons[1] << "," << msg.buttons[2] << "," << msg.buttons[3] << "," << msg.buttons[4] <<std::endl;	//テキストに追加
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_joy");

  ros::NodeHandle sjoy;

  ros::Subscriber sub = sjoy.subscribe("/crazyflie/joy", 1, chatterCallback);
  
  ros::spin();

  return 0;
}

