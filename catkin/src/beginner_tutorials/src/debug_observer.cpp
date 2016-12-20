#include <ros/ros.h>
#include <std_msgs/Header.h>
#include "estimate/msgCrazyflie_data.h"
#include "mpc/msgMPC.h"
#include <fstream>

std::ofstream ofs("Observer_debug.txt"); //textメッセージ

double esti_box[21],mpc_box[4],X_ob_box[10],U_ob_box[10];
int Switch = 1;
estimate::msgCrazyflie_data esti_data;
mpc::msgMPC mpc_msg;
bool EstimateFlag,MPCFlag;

void chatterCallback_estimate(const estimate::msgCrazyflie_data& msg_esti)	//estimateデータ取得
{
  EstimateFlag = true;
  esti_data = msg_esti;

  //if(true == EstimateFlag && true == MPCFlag)
  {
//IMU data
    esti_box[0] = esti_data.imu_time_msg;
    esti_box[1] = esti_data.imu_angx_msg;
    esti_box[2] = esti_data.imu_angy_msg;
    esti_box[3] = esti_data.imu_angz_msg;
    esti_box[4] = esti_data.imu_linx_msg;
    esti_box[5] = esti_data.imu_liny_msg;
    esti_box[6] = esti_data.imu_linz_msg;
//Motion_Capture data
    esti_box[7] = esti_data.vrpn_time_msg;
    esti_box[8] = esti_data.vrpn_posx_msg;
    esti_box[9] = esti_data.vrpn_posy_msg;
    esti_box[10] = esti_data.vrpn_posz_msg;
    esti_box[11] = esti_data.vrpn_velx_msg;
    esti_box[12] = esti_data.vrpn_vely_msg;
    esti_box[13] = esti_data.vrpn_velz_msg;
    esti_box[14] = esti_data.vrpn_linx_msg;
    esti_box[15] = esti_data.vrpn_liny_msg;
    esti_box[16] = esti_data.vrpn_linz_msg;
    esti_box[17] = esti_data.vrpn_orix_msg;
    esti_box[18] = esti_data.vrpn_oriy_msg;
    esti_box[19] = esti_data.vrpn_oriz_msg;
    esti_box[20] = esti_data.vrpn_oriw_msg;
  }
}

void chatterCallback_mpc_main(const mpc::msgMPC& msg_mpc)	//estimateデータ取得
{
  MPCFlag = true;
  mpc_msg = msg_mpc;

  //if(true == EstimateFlag && true == MPCFlag)
  {
    Switch = mpc_msg.controlflag;
    mpc_box[0] = mpc_msg.phi;
    mpc_box[1] = mpc_msg.theta;
    mpc_box[2] = mpc_msg.psi;
    mpc_box[3] = mpc_msg.thrust;

    X_ob_box[0] = mpc_msg.Xe_ob_x;
    X_ob_box[1] = mpc_msg.Xe_ob_vx;
    X_ob_box[2] = mpc_msg.Xe_ob_ax;
    X_ob_box[3] = mpc_msg.Xe_ob_y;
    X_ob_box[4] = mpc_msg.Xe_ob_vy;
    X_ob_box[5] = mpc_msg.Xe_ob_ay;
    X_ob_box[6] = mpc_msg.Xe_ob_z;
    X_ob_box[7] = mpc_msg.Xe_ob_vz;
    X_ob_box[8] = mpc_msg.Xe_ob_az;

    U_ob_box[0] = mpc_msg.U_ob_x;
    U_ob_box[1] = mpc_msg.U_ob_vx;
    U_ob_box[2] = mpc_msg.U_ob_phi;
    U_ob_box[3] = mpc_msg.U_ob_y;
    U_ob_box[4] = mpc_msg.U_ob_vy;
    U_ob_box[5] = mpc_msg.U_ob_theta;
    U_ob_box[6] = mpc_msg.U_ob_z;
    U_ob_box[7] = mpc_msg.U_ob_vz;
    U_ob_box[8] = mpc_msg.U_ob_thrust;

  }
}

void callback1(const ros::TimerEvent&)
{ 
  if(true == EstimateFlag && true == MPCFlag){
	/*esti: IMU(時間 角速度[x y z] 加速度[x y z]) Mocap(時間 位置[x y z] 速度[x y z] 加速度[x y z] 姿勢[x y z w])
	  mpc : switch 制御入力[x y z T]
	*/

    ofs << esti_box[0] << " " <<  esti_box[1] << " " <<  esti_box[2] << " " <<  esti_box[3] << " " <<  esti_box[4] << " " <<  esti_box[5] << " " <<  esti_box[6] << " " <<  esti_box[7] << " " <<  esti_box[8] << " " <<  esti_box[9] << " " <<  esti_box[10] << " " <<  esti_box[11] << " " <<  esti_box[12] << " " <<  esti_box[13] << " " <<  esti_box[14] << " " <<  esti_box[15] << " " <<  esti_box[16] << " " <<  esti_box[17] << " " <<  esti_box[18] << " " <<  esti_box[19] << " " <<  esti_box[20] << " "  << Switch << " " << mpc_box[0] << " " << mpc_box[1] << " " << mpc_box[2] << " " << mpc_box[3];
    for(int i = 0;i < 9;i++)
	ofs << " " << X_ob_box[i];
    for(int j = 0;j < 9;j++)
	ofs << " " << U_ob_box[j];

	ofs << " " << std::endl;
  }
}

int main(int argc, char **argv)
{
ros::init(argc, argv, "mpc_debug");
  ros::NodeHandle debug;

  EstimateFlag = false;
  MPCFlag = false;
  ros::Subscriber esti_sub = debug.subscribe("crazyflie_data_msg", 1, chatterCallback_estimate);
  ros::Subscriber mpc_sub = debug.subscribe("mpc_data_msg", 1, chatterCallback_mpc_main);
  ros::Timer time1 = debug.createTimer(ros::Duration(0.01), callback1);

  ros::spin();
  return 0;
}
