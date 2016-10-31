#include "ros/ros.h"
#include <iostream>

#include "geometry_msgs/Twist.h"
#include <crazyflie_cpp/Crazyflie.h>

Crazyflie *cfCopter;

void twistCallback(const geometry_msgs::Twist::ConstPtr& msg) {
	int thrustCommand = (msg->linear.z * 10000) + 40000;
	if (thrustCommand > 60000)
		thrustCommand = 60000;
	else if (thrustCommand < 10000)
		thrustCommand = 10000;
	std::cout << thrustCommand << std::endl;


	float rollCommand = -20.0f * msg->linear.y;
	float pitchCommand = 20.0f * msg->linear.x;
	float yawRateCommand = -180.0 * msg->angular.z;

	cfCopter->sendSetpoint(rollCommand, pitchCommand, yawRateCommand, thrustCommand);
}

int main(int argc, char** argv) {

	ros::init(argc, argv, "crazyflie");
	ros::NodeHandle n;

	cfCopter = new Crazyflie("radio://0/80/250K");
	cfCopter->requestLogToc();

	ros::Subscriber sub = n.subscribe("cmd_vel", 1000, twistCallback);

	ros::Rate loop_rate(100);

	ros::spin();
	std::cerr << "Bye\n" << std::endl;
	delete cfCopter;

	return 0;
}
