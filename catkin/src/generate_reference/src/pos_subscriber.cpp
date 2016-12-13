#include "ros/ros.h"
#include "generate_reference/msgReference.h"

generate_reference::msgReference buf;

int count = 0;
void msgCallback(const generate_reference::msgReference &msg)
{
  buf = msg;
  if(0 == buf.signal)
	std::cout << "Not control " << count << std::endl;
  if(1 == buf.signal)
  {
	count = 1;
	std::cout << "OK" << std::endl;
  }
/*  ROS_INFO("recieve msg: %f", buf.next_ref_x);
  ROS_INFO("recieve msg: %f", buf.next_ref_y);
  ROS_INFO("recieve msg: %f", buf.next_ref_z);*/
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "pos_subscriber");
  ros::NodeHandle nh; 
  
  ros::Subscriber pos_sub = nh.subscribe("pos_msg",100, msgCallback); 

  ros::spin();
  return 0;
}
