#include <ros/ros.h>
#include <std_msgs/Header.h>
#include <geometry_msgs/PoseStamped.h>
#include <fstream>

std::ofstream ofs("motion_capture.txt"); //textメッセージ

long double vrpn_box[9];
long double vrpn_time = 0.0;
long double first_time_vrpn_sec = 0.0,first_time_vrpn_nsec = 0.0;
double count_vrpn = 0.0;
bool SaveStartFlag;

geometry_msgs::PoseStamped msg;

void chatterCallback_vrpn(const geometry_msgs::PoseStamped& msg_vrpn)	//vrpnデータ取得
{
	SaveStartFlag = true;
	msg = msg_vrpn;

	if(true == SaveStartFlag)
	count_vrpn++;

	if(1.0 == count_vrpn)
	{
		first_time_vrpn_sec  =  (long double)(msg.header.stamp.sec);
		first_time_vrpn_nsec =  (long double)(msg.header.stamp.nsec);
	}

//	vrpn: 時間sec nsec 位置[x y z] 姿勢[x y z w]

	vrpn_box[0] = (long double)(msg.header.stamp.sec);
	vrpn_box[1] = (long double)(msg.header.stamp.nsec);
  
	vrpn_time = (long double)(vrpn_box[0] - first_time_vrpn_sec + (vrpn_box[1] - first_time_vrpn_nsec) * 0.000000001);

	vrpn_box[2] = msg.pose.position.x;
	vrpn_box[3] = msg.pose.position.y;
	vrpn_box[4] = msg.pose.position.z;
	vrpn_box[5] = msg.pose.orientation.x;
	vrpn_box[6] = msg.pose.orientation.y;
	vrpn_box[7] = msg.pose.orientation.z;
	vrpn_box[8] = msg.pose.orientation.w;
}

void callback1(const ros::TimerEvent&)
{ 
	if(1.0 <= count_vrpn)
	{
		ofs << vrpn_time << " " << vrpn_box[2] << " " << vrpn_box[3] << " " << vrpn_box[4] << " " << vrpn_box[5] << " " << vrpn_box[6] << " " << vrpn_box[7] << " " << vrpn_box[8] << std::endl;

	}
	SaveStartFlag = false;
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "motion_capture");
  ros::NodeHandle all;
  SaveStartFlag = false;

  ros::Subscriber sub = all.subscribe("/vrpn_client_node/Heli1/pose", 1, chatterCallback_vrpn);
  ros::Timer time1 = all.createTimer(ros::Duration(0.01), callback1);

  ros::spin();
  return 0;
}
