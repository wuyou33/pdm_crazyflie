#include "ros/ros.h"

void callback1(const ros::TimerEvent&)
{
	ROS_INFO("Callback 1 triggered");
}

void callback2(const ros::TimerEvent&)
{
	ROS_INFO("Callback 2 triggered");
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "talker");
	ros::NodeHandle n;

	ros::Timer time1 = n.createTimer(ros::Duration(0.1), callback1);
	ros::Timer time2 = n.createTimer(ros::Duration(1.0), callback2);

	ros::spin();

	return 0;
}
