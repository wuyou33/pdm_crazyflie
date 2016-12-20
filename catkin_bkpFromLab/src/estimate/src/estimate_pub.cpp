/////////////////////完成版/////////////////////////
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseStamped.h>
#include "estimate/msgCrazyflie_data.h"

// 関数宣言
void Quaternion2Euler(double*, double*);

struct IMUData {
  double time;
  double p,q,r;
  double xacc,yacc,zacc;
} g_imu;

struct MocapData {
  double time;
  double xpos,ypos,zpos;
  double xvel,yvel,zvel;
  double x,y,z,w;
  double roll,pitch,yaw;
  
  double time_pre;
  double xpos_pre, ypos_pre, zpos_pre;

} g_vrpn;

struct MocapData_obs {
  double time_obs;
  double xpos_obs,ypos_obs,zpos_obs;
  double xvel_obs,yvel_obs,zvel_obs;
  double x_obs,y_obs,z_obs,w_obs;
  double roll_obs,pitch_obs,yaw_obs;
  
  double time_pre_obs;
  double xpos_pre_obs, ypos_pre_obs, zpos_pre_obs;

} g_vrpn_obs;

double first_time;
bool   VrpnFirstTime = true,VrpnFirstTime_obs = true;

ros::Subscriber sub_imu;
ros::Subscriber sub_vrpn;
ros::Subscriber sub_vrpn_obs;
ros::Publisher pub_est;
ros::Timer time_est;
estimate::msgCrazyflie_data cf_msg;

void chatterCallback_imu(const sensor_msgs::Imu &msg_imu)	//imuデータ取得
{
	g_imu.time  = (double)(msg_imu.header.stamp.sec)  + (double)(msg_imu.header.stamp.nsec) * 0.000000001 - first_time;
	g_imu.p     = (double)(msg_imu.angular_velocity.x);
	g_imu.q     = (double)(msg_imu.angular_velocity.y);
	g_imu.r     = (double)(msg_imu.angular_velocity.z);
	g_imu.xacc  = (double)(msg_imu.linear_acceleration.x);
	g_imu.yacc  = (double)(msg_imu.linear_acceleration.y);
	g_imu.zacc  = (double)(msg_imu.linear_acceleration.z);
}

void chatterCallback_vrpn(const geometry_msgs::PoseStamped& msg_vrpn)  //vrpnデータ取得
{
   	double dt;
        double quat[4], euler[3];

	if(true == VrpnFirstTime){
		VrpnFirstTime = false;
		first_time =  (double)(msg_vrpn.header.stamp.sec) + (double)(msg_vrpn.header.stamp.nsec) * 0.000000001;
   	}
   
   	g_vrpn.time  = (double)(msg_vrpn.header.stamp.sec) + (double)(msg_vrpn.header.stamp.nsec) * 0.000000001 - first_time;	

	g_vrpn.xpos  = (double)(msg_vrpn.pose.position.x);
	g_vrpn.ypos  = (double)(msg_vrpn.pose.position.y);
	g_vrpn.zpos  = (double)(msg_vrpn.pose.position.z);

	g_vrpn.x     = (double)(msg_vrpn.pose.orientation.x);
	g_vrpn.y     = (double)(msg_vrpn.pose.orientation.y);
	g_vrpn.z     = (double)(msg_vrpn.pose.orientation.z);
	g_vrpn.w     = (double)(msg_vrpn.pose.orientation.w);

        // オイラー角へ変換
        quat[0] = g_vrpn.w; quat[1] = g_vrpn.x;  quat[2] = g_vrpn.y;  quat[3] = g_vrpn.z;
        Quaternion2Euler(quat,euler);
	g_vrpn.roll = euler[0]; g_vrpn.pitch = euler[1]; g_vrpn.yaw = euler[2];

	dt = g_vrpn.time - g_vrpn.time_pre;
        if(dt < 0.008) dt = 0.008;

	g_vrpn.xvel  = (g_vrpn.xpos - g_vrpn.xpos_pre)/dt;
	g_vrpn.yvel  = (g_vrpn.ypos - g_vrpn.ypos_pre)/dt;
	g_vrpn.zvel  = (g_vrpn.zpos - g_vrpn.zpos_pre)/dt;

	g_vrpn.time_pre = g_vrpn.time;
	g_vrpn.xpos_pre = g_vrpn.xpos;
	g_vrpn.ypos_pre = g_vrpn.ypos;
	g_vrpn.zpos_pre = g_vrpn.zpos;
}

void chatterCallback_vrpn_obs(const geometry_msgs::PoseStamped& msg_vrpn_obs)  //vrpnデータ取得
{
   	double dt;
        double quat_obs[4], euler_obs[3];

	if(true == VrpnFirstTime_obs){
		VrpnFirstTime_obs = false;
		first_time =  (double)(msg_vrpn_obs.header.stamp.sec) + (double)(msg_vrpn_obs.header.stamp.nsec) * 0.000000001;
   	}
   
   	g_vrpn_obs.time_obs  = (double)(msg_vrpn_obs.header.stamp.sec) + (double)(msg_vrpn_obs.header.stamp.nsec) * 0.000000001 - first_time;	

	g_vrpn_obs.xpos_obs  = (double)(msg_vrpn_obs.pose.position.x);
	g_vrpn_obs.ypos_obs  = (double)(msg_vrpn_obs.pose.position.y);
	g_vrpn_obs.zpos_obs  = (double)(msg_vrpn_obs.pose.position.z);

	g_vrpn_obs.x_obs     = (double)(msg_vrpn_obs.pose.orientation.x);
	g_vrpn_obs.y_obs     = (double)(msg_vrpn_obs.pose.orientation.y);
	g_vrpn_obs.z_obs     = (double)(msg_vrpn_obs.pose.orientation.z);
	g_vrpn_obs.w_obs     = (double)(msg_vrpn_obs.pose.orientation.w);

        // オイラー角へ変換
        quat_obs[0] = g_vrpn_obs.w_obs; quat_obs[1] = g_vrpn_obs.x_obs;  quat_obs[2] = g_vrpn_obs.y_obs;  quat_obs[3] = g_vrpn_obs.z_obs;
        Quaternion2Euler(quat_obs,euler_obs);
	g_vrpn_obs.roll_obs = euler_obs[0]; g_vrpn_obs.pitch_obs = euler_obs[1]; g_vrpn_obs.yaw_obs = euler_obs[2];

	dt = g_vrpn_obs.time_obs - g_vrpn_obs.time_pre_obs;
        if(dt < 0.008) dt = 0.008;

	g_vrpn_obs.xvel_obs  = (g_vrpn_obs.xpos_obs - g_vrpn_obs.xpos_pre_obs)/dt;
	g_vrpn_obs.yvel_obs  = (g_vrpn_obs.ypos_obs - g_vrpn_obs.ypos_pre_obs)/dt;
	g_vrpn_obs.zvel_obs  = (g_vrpn_obs.zpos_obs - g_vrpn_obs.zpos_pre_obs)/dt;

	g_vrpn_obs.time_pre_obs = g_vrpn_obs.time_obs;
	g_vrpn_obs.xpos_pre_obs = g_vrpn_obs.xpos_obs;
	g_vrpn_obs.ypos_pre_obs = g_vrpn_obs.ypos_obs;
	g_vrpn_obs.zpos_pre_obs = g_vrpn_obs.zpos_obs;
}

void callback1(const ros::TimerEvent&)
{ 
	cf_msg.imu_time_msg   = g_imu.time;        
	cf_msg.imu_angx_msg   = g_imu.p;
	cf_msg.imu_angy_msg   = g_imu.q;
	cf_msg.imu_angz_msg   = g_imu.r;
	cf_msg.imu_linx_msg   = g_imu.xacc;
	cf_msg.imu_liny_msg   = g_imu.yacc;
	cf_msg.imu_linz_msg   = g_imu.zacc;

	cf_msg.vrpn_time_msg  = g_vrpn.time;
	cf_msg.vrpn_posx_msg  = g_vrpn.xpos;
	cf_msg.vrpn_posy_msg  = g_vrpn.ypos;
	cf_msg.vrpn_posz_msg  = g_vrpn.zpos;
	cf_msg.vrpn_velx_msg  = g_vrpn.xvel;
	cf_msg.vrpn_vely_msg  = g_vrpn.yvel;
	cf_msg.vrpn_velz_msg  = g_vrpn.zvel;
	cf_msg.vrpn_linx_msg  = 0.0;
	cf_msg.vrpn_liny_msg  = 0.0;
	cf_msg.vrpn_linz_msg  = 0.0;
	cf_msg.vrpn_orix_msg  = g_vrpn.x;
	cf_msg.vrpn_oriy_msg  = g_vrpn.y;
	cf_msg.vrpn_oriz_msg  = g_vrpn.z;
	cf_msg.vrpn_oriw_msg  = g_vrpn.w;
	cf_msg.vrpn_roll_msg  = g_vrpn.roll;
	cf_msg.vrpn_pitch_msg = g_vrpn.pitch;
	cf_msg.vrpn_yaw_msg   = g_vrpn.yaw;

	cf_msg.vrpn_time_msg_obs  = g_vrpn_obs.time_obs;
	cf_msg.vrpn_posx_msg_obs  = g_vrpn_obs.xpos_obs;
	cf_msg.vrpn_posy_msg_obs  = g_vrpn_obs.ypos_obs;
	cf_msg.vrpn_posz_msg_obs  = g_vrpn_obs.zpos_obs;
	cf_msg.vrpn_velx_msg_obs  = g_vrpn_obs.xvel_obs;
	cf_msg.vrpn_vely_msg_obs  = g_vrpn_obs.yvel_obs;
	cf_msg.vrpn_velz_msg_obs  = g_vrpn_obs.zvel_obs;
	cf_msg.vrpn_linx_msg_obs  = 0.0;
	cf_msg.vrpn_liny_msg_obs  = 0.0;
	cf_msg.vrpn_linz_msg_obs  = 0.0;
	cf_msg.vrpn_orix_msg_obs  = g_vrpn_obs.x_obs;
	cf_msg.vrpn_oriy_msg_obs  = g_vrpn_obs.y_obs;
	cf_msg.vrpn_oriz_msg_obs  = g_vrpn_obs.z_obs;
	cf_msg.vrpn_oriw_msg_obs  = g_vrpn_obs.w_obs;
	cf_msg.vrpn_roll_msg_obs  = g_vrpn_obs.roll_obs;
	cf_msg.vrpn_pitch_msg_obs = g_vrpn_obs.pitch_obs;
	cf_msg.vrpn_yaw_msg_obs   = g_vrpn_obs.yaw_obs;

	pub_est.publish(cf_msg);
}

void Quaternion2Euler(double* quat, double* euler)
{ // クォータニオンからオイラー角への変換

  double temp1 = -2.0*(quat[1]*quat[3] - quat[0]*quat[2]);
  double temp2 =  2.0*(quat[0]*quat[1] + quat[2]*quat[3]);
  double temp3 = 1.0 - 2.0*(quat[1]*quat[1] + quat[2]*quat[2]);
  double temp4 = 2.0*(quat[1]*quat[2] + quat[0]*quat[3]);
  double temp5 = 1.0 - 2.0*(quat[2]*quat[2] + quat[3]*quat[3]);

  euler[0] = atan2(temp2,temp3);
  euler[1] = asin(temp1);
  euler[2] = atan2(temp4,temp5);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "esti_pub");
  ros::NodeHandle esti;
 
  sub_imu       = esti.subscribe("/crazyflie/imu", 1, chatterCallback_imu);
  sub_vrpn      = esti.subscribe("/vrpn_client_node/Heli1/pose", 1, chatterCallback_vrpn);
  sub_vrpn_obs  = esti.subscribe("/vrpn_client_node/Obs1/pose", 1, chatterCallback_vrpn_obs);
  time_est      = esti.createTimer(ros::Duration(0.01), callback1);
  pub_est       = esti.advertise<estimate::msgCrazyflie_data>("crazyflie_data_msg",100);

  ros::spin();
  return 0;
}
