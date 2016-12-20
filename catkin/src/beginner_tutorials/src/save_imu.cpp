#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <sensor_msgs/Imu.h>
#include <fstream>

std::ofstream ofs("Imu_data.txt"); //textメッセージ
long double imu_box[8];
long double imu_time;
long double first_time_imu;
double count_imu = 0.0;
sensor_msgs::Imu msg1;
bool SaveStartFlag;

	
void chatterCallback_imu(const sensor_msgs::Imu &msg_imu)	//imuデータ取得
{
  SaveStartFlag = true;
  msg1 = msg_imu;
  
  if (SaveStartFlag == true)
    count_imu++;

  if(count_imu == 1.0)
    first_time_imu =  (long double)(msg1.header.stamp.sec);

  imu_box[0] = (long double)(msg1.header.stamp.sec); 
  imu_box[1] = (long double)(msg1.header.stamp.nsec);

  imu_time = (long double)(imu_box[0] - first_time_imu + imu_box[1] * 0.000000001);

  imu_box[2] = msg1.angular_velocity.x;
  imu_box[3] = msg1.angular_velocity.y;
  imu_box[4] = msg1.angular_velocity.z;
  imu_box[5] = msg1.linear_acceleration.x;
  imu_box[6] = msg1.linear_acceleration.y;
  imu_box[7] = msg1.linear_acceleration.z;

}

void callback1(const ros::TimerEvent&)
{ 
  if(count_imu >= 1.0){
	  //imu : 時間sec nsec 角速度[x y z] 加速度[x y z]

    ofs << imu_time << " " << imu_box[2] << " " << imu_box[3] << " " << imu_box[4] << " " << imu_box[5] << " " << imu_box[6] << " " << imu_box[7] << std::endl;
  }
  SaveStartFlag = false;
}


int main(int argc, char **argv)
{
ros::init(argc, argv, "save_imu");
  ros::NodeHandle imu;

  SaveStartFlag = false;
 
  ros::Subscriber sub1 = imu.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  ros::Timer time1 = imu.createTimer(ros::Duration(0.01), callback1);

  ros::spin();
  return 0;
}

