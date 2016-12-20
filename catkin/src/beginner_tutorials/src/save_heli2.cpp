#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
  std::ofstream ofs("TS_imu.txt"); //textメッセージ	
void chatterCallback(const geometry_msgs::PoseStamped& msg)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用

  ofs << msg.header.stamp.sec << "," << msg.header.stamp.nsec << "," << msg.pose.position.x << "," << msg.pose.position.y << "," << msg.pose.position.z << "," << msg.pose.orientation.x << "," << msg.pose.orientation.y << "," << msg.pose.orientation.z <<std::endl;	//テキストに追加
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_Heli2");

  ros::NodeHandle h2p;

  ros::Subscriber sub = h2p.subscribe("/vrpn_client_node/Heli2/pose", 1, chatterCallback);
  
  ros::spin();

  return 0;
}

