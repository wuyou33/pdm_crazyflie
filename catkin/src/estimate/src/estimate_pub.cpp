/////////////////////完成版/////////////////////////
#include <ros/ros.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/PoseStamped.h>
#include "estimate/msgCrazyflie_data.h"

// 関数宣言
void Quaternion2Euler(double*, double*);

struct MocapData {
  double time;
  double xpos,ypos,zpos;
  double xvel,yvel,zvel;
  double x,y,z,w;
  double roll,pitch,yaw;
  
  double time_pre;
  double xpos_pre, ypos_pre, zpos_pre;

} g_vrpn1, g_vrpn2, g_vrpn3, g_vrpn4;

/*
struct IMUData {
  double time;
  double p,q,r;
  double xacc,yacc,zacc;
} g_imu;

struct MocapData_obs {
  double time_obs;
  double xpos_obs,ypos_obs,zpos_obs;
  double xvel_obs,yvel_obs,zvel_obs;
  double x_obs,y_obs,z_obs,w_obs;
  double roll_obs,pitch_obs,yaw_obs;
  
  double time_pre_obs;
  double xpos_pre_obs, ypos_pre_obs, zpos_pre_obs;

} g_vrpn_obs;
*/

double first_time;
bool   VrpnFirstTime = true,VrpnFirstTime_obs = true;

ros::Subscriber subVrpnCf1, subVrpnCf2, subVrpnCf3, subVrpnCf4;
//ros::Subscriber subImu;
//ros::Subscriber subVrpn_obs;
ros::Publisher pubMeasurements;
ros::Timer timerMeasurements;
estimate::msgCrazyflie_data cf_msg;

void cfMeasurementCallback(const geometry_msgs::PoseStamped& msg_vrpn)  //vrpnデータ取得
{
   	double dt;
        double quat[4], euler[3];

	if(true == VrpnFirstTime){
		VrpnFirstTime = false;
		first_time =  (double)(msg_vrpn.header.stamp.sec) + (double)(msg_vrpn.header.stamp.nsec) * 0.000000001;
   	}
   
   	g_vrpn1.time  = (double)(msg_vrpn.header.stamp.sec) + (double)(msg_vrpn.header.stamp.nsec) * 0.000000001 - first_time;	

	g_vrpn1.xpos  = (double)(msg_vrpn.pose.position.x);
	g_vrpn1.ypos  = (double)(msg_vrpn.pose.position.y);
	g_vrpn1.zpos  = (double)(msg_vrpn.pose.position.z);

	g_vrpn1.x     = (double)(msg_vrpn.pose.orientation.x);
	g_vrpn1.y     = (double)(msg_vrpn.pose.orientation.y);
	g_vrpn1.z     = (double)(msg_vrpn.pose.orientation.z);
	g_vrpn1.w     = (double)(msg_vrpn.pose.orientation.w);

    // オイラー角へ変換
    quat[0] = g_vrpn1.w; quat[1] = g_vrpn1.x;  quat[2] = g_vrpn1.y;  quat[3] = g_vrpn1.z;
    Quaternion2Euler(quat,euler);
	g_vrpn1.roll = euler[0]; g_vrpn1.pitch = euler[1]; g_vrpn1.yaw = euler[2];

	dt = g_vrpn1.time - g_vrpn1.time_pre;
        if(dt < 0.008) dt = 0.008;

	g_vrpn1.xvel  = (g_vrpn1.xpos - g_vrpn1.xpos_pre)/dt;
	g_vrpn1.yvel  = (g_vrpn1.ypos - g_vrpn1.ypos_pre)/dt;
	g_vrpn1.zvel  = (g_vrpn1.zpos - g_vrpn1.zpos_pre)/dt;

	g_vrpn1.time_pre = g_vrpn1.time;
	g_vrpn1.xpos_pre = g_vrpn1.xpos;
	g_vrpn1.ypos_pre = g_vrpn1.ypos;
	g_vrpn1.zpos_pre = g_vrpn1.zpos;
}

void cfMeasurementCallbackTmp(const geometry_msgs::PoseStamped& msg_vrpn)  //vrpnデータ取得
{
	ROS_INFO("2, 3 or 4 data");
}

/*

void imuCallback(const sensor_msgs::Imu &msg_imu)	//imuデータ取得
{
	g_imu.time  = (double)(msg_imu.header.stamp.sec)  + (double)(msg_imu.header.stamp.nsec) * 0.000000001 - first_time;
	g_imu.p     = (double)(msg_imu.angular_velocity.x);
	g_imu.q     = (double)(msg_imu.angular_velocity.y);
	g_imu.r     = (double)(msg_imu.angular_velocity.z);
	g_imu.xacc  = (double)(msg_imu.linear_acceleration.x);
	g_imu.yacc  = (double)(msg_imu.linear_acceleration.y);
	g_imu.zacc  = (double)(msg_imu.linear_acceleration.z);
}
*/

/*
void obsMeasurementCallback(const geometry_msgs::PoseStamped& msg_vrpn_obs)  //vrpnデータ取得
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
*/

void callbackTime(const ros::TimerEvent&)
{ 
	cf_msg.imu_time_msg   = 0.0;//g_imu.time;        
	cf_msg.imu_angx_msg   = 0.0;//g_imu.p;
	cf_msg.imu_angy_msg   = 0.0;//g_imu.q;
	cf_msg.imu_angz_msg   = 0.0;//g_imu.r;
	cf_msg.imu_linx_msg   = 0.0;//g_imu.xacc;
	cf_msg.imu_liny_msg   = 0.0;//g_imu.yacc;
	cf_msg.imu_linz_msg   = 0.0;//g_imu.zacc;

	cf_msg.vrpn_time_msg  = g_vrpn1.time;
	cf_msg.vrpn_posx_msg  = g_vrpn1.xpos;
	cf_msg.vrpn_posy_msg  = g_vrpn1.ypos;
	cf_msg.vrpn_posz_msg  = g_vrpn1.zpos;
	cf_msg.vrpn_velx_msg  = g_vrpn1.xvel;
	cf_msg.vrpn_vely_msg  = g_vrpn1.yvel;
	cf_msg.vrpn_velz_msg  = g_vrpn1.zvel;
	cf_msg.vrpn_linx_msg  = 0.0;
	cf_msg.vrpn_liny_msg  = 0.0;
	cf_msg.vrpn_linz_msg  = 0.0;
	cf_msg.vrpn_orix_msg  = g_vrpn1.x;
	cf_msg.vrpn_oriy_msg  = g_vrpn1.y;
	cf_msg.vrpn_oriz_msg  = g_vrpn1.z;
	cf_msg.vrpn_oriw_msg  = g_vrpn1.w;
	cf_msg.vrpn_roll_msg  = g_vrpn1.roll;
	cf_msg.vrpn_pitch_msg = g_vrpn1.pitch;
	cf_msg.vrpn_yaw_msg   = g_vrpn1.yaw;

	cf_msg.vrpn_time_msg_obs  = 0.0;//g_vrpn_obs.time_obs;
	cf_msg.vrpn_posx_msg_obs  = 0.0;//g_vrpn_obs.xpos_obs;
	cf_msg.vrpn_posy_msg_obs  = 0.0;//g_vrpn_obs.ypos_obs;
	cf_msg.vrpn_posz_msg_obs  = 0.0;//g_vrpn_obs.zpos_obs;
	cf_msg.vrpn_velx_msg_obs  = 0.0;//g_vrpn_obs.xvel_obs;
	cf_msg.vrpn_vely_msg_obs  = 0.0;//g_vrpn_obs.yvel_obs;
	cf_msg.vrpn_velz_msg_obs  = 0.0;//g_vrpn_obs.zvel_obs;
	cf_msg.vrpn_linx_msg_obs  = 0.0;
	cf_msg.vrpn_liny_msg_obs  = 0.0;
	cf_msg.vrpn_linz_msg_obs  = 0.0;
	cf_msg.vrpn_orix_msg_obs  = 0.0;//g_vrpn_obs.x_obs;
	cf_msg.vrpn_oriy_msg_obs  = 0.0;//g_vrpn_obs.y_obs;
	cf_msg.vrpn_oriz_msg_obs  = 0.0;//g_vrpn_obs.z_obs;
	cf_msg.vrpn_oriw_msg_obs  = 0.0;//g_vrpn_obs.w_obs;
	cf_msg.vrpn_roll_msg_obs  = 0.0;//g_vrpn_obs.roll_obs;
	cf_msg.vrpn_pitch_msg_obs = 0.0;//g_vrpn_obs.pitch_obs;
	cf_msg.vrpn_yaw_msg_obs   = 0.0;//g_vrpn_obs.yaw_obs;

	pubMeasurements.publish(cf_msg);
}

void Quaternion2Euler(double* quat, double* euler)
{ // Quaternion to Euler conversion

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

  double TsMotionCaptureData = 0.01; //[s] => 100 Hz
 
//  subImu       	= esti.subscribe("/crazyflie/imu", 1, imuCallback);
  subVrpnCf1    = esti.subscribe("/vrpn_client_node/cf1/pose", 1, cfMeasurementCallback);
  subVrpnCf2    = esti.subscribe("/vrpn_client_node/cf2/pose", 1, cfMeasurementCallbackTmp);
  subVrpnCf3    = esti.subscribe("/vrpn_client_node/cf3/pose", 1, cfMeasurementCallbackTmp);
  subVrpnCf4    = esti.subscribe("/vrpn_client_node/cf4/pose", 1, cfMeasurementCallbackTmp);
//  subVrpnObs    = esti.subscribe("/vrpn_client_node/Obs/pose", 1, obsMeasurementCallback);

  timerMeasurements     = esti.createTimer(ros::Duration(TsMotionCaptureData), callbackTime);
  pubMeasurements       = esti.advertise<estimate::msgCrazyflie_data>("crazyflieMeasurementData",100);

  ros::spin();
  return 0;
}
