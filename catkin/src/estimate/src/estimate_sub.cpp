#include <ros/ros.h>
#include "estimate/msgCrazyflie_data.h"

estimate::msgCrazyflie_data msg1;

void msgCallback(const estimate::msgCrazyflie_data& msg_imu)
{
  msg1 = msg_imu;
  std::cout << msg1.imu_time_msg << std::endl;
}

int main(int argc,char **argv)
{
  ros::init(argc,argv,"esti_sub");
  ros::NodeHandle esti;
  ros::Subscriber sub1 = esti.subscribe("crazyflie_data_msg",100,msgCallback);

  ros::spin();
return 0;
}
