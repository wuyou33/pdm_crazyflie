#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include <fstream>

/*void chatterCallback(const std_msgs::Header& msg)
{
  ROS_INFO("I heard: [%d]", msg.stamp.sec);
}*/
  std::ofstream ofs("TS_cmd_vel.txt"); //textメッセージ	
void chatterCallback(const hector_quadrotor_teleop::adv_cmd_vel& msg)	//LaserScanデータ
{
  //  ROS_INFO("%d",msg.header.stamp.sec);	//確認用

  ofs << msg.header.stamp.sec<< "," << msg.header.stamp.nsec << "," << msg.linear.x << ","<< msg.linear.y << ","<< msg.linear.z << ","<< msg.angular.x << ","<< msg.angular.y << ","<< msg.angular.z <<std::endl;	//テキストに追加
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "savetxt_cmd_vel");

  ros::NodeHandle smv;

  ros::Subscriber sub = smv.subscribe("/crazyflie/cmd_vel", 1, chatterCallback);
  
  ros::spin();

  return 0;
}

