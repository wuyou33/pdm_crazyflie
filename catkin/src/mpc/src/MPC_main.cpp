#include <ros/ros.h>
#include <sensor_msgs/Joy.h>

#include "GdnCont.h" //Guidance
#include "stateModelStructure.h"
#include "estimate/msgCrazyflie_data.h"
#include <hector_quadrotor_teleop/adv_cmd_vel.h>
#include "mpc/msgMPC_Input.h"
#include "mpc/msgMPC_Data.h"
#include "generate_reference/msgReference.h"

MPCData stateData;

double xRef = 0.0, yRef = 0.0, zRef = 0.0;
double rollDesired = 0.0, pitchDesired = 0.0,yawRateDesired = 0.0,thrustDesired = 0.0;
double offset_phi, offset_the, offset_thr;
int controlFlag = 0, refPosFlag = 0;

// Timing
ros::Time startTime, endTime;

// Publishers
ros::Publisher pubMpcInput;
ros::Publisher pubMpcData;

// Subscribers
ros::Subscriber subGetControlMode;
ros::Subscriber subGetRef;
ros::Subscriber subGetJoystickCommand;
ros::Subscriber subGetStateEstim;

// Messages
mpc::msgMPC_Input mpcInputMsg;
mpc::msgMPC_Data mpcDataMsg;

//MPC Controller
CGdnCont gdnController;

void getControlModeCallback(const sensor_msgs::Joy& joystickMessage)
{
	// Switch control mode between manual and MPC
	if (joystickMessage.buttons[3] == 1)       controlFlag = 0;
	else if (joystickMessage.buttons[3] == 0)  controlFlag = 1;
}

void getRefCallback(const generate_reference::msgReference &referenceDataMessage)
{	
	// Reset flag
	refPosFlag = 0;
	if (referenceDataMessage.signal == 1)
	{
		//Test Zref
		if (referenceDataMessage.next_ref_z <= 0.0)
			ROS_INFO("Cannot change zRef.");
			// Clamping?
		else
		{
			xRef = (double)(referenceDataMessage.next_ref_x);
			yRef = (double)(referenceDataMessage.next_ref_y);
			zRef = (double)(referenceDataMessage.next_ref_z);
			// Set flag
			refPosFlag = 1;
		}
	}
}

void getJoystickCommandCallback(const hector_quadrotor_teleop::adv_cmd_vel& msg_cmd_vel)
{
	// Thrust
	stateData.pitchFromJoystick = msg_cmd_vel.linear.z;
	// Roll
	stateData.rollFromJoystick = msg_cmd_vel.linear.y;
	// Pitch
	stateData.pitchFromJoystick = msg_cmd_vel.linear.x;
	// Yaw
	stateData.yawRateFromJoystick = msg_cmd_vel.angular.z;
}

void getStateEstimCallback(const estimate::msgCrazyflie_data& esti_msg)
{
	Eigen::Matrix<double,N_INPUT_MODEL*N,1> Us;

	Us = Eigen::Matrix<double,N_INPUT_MODEL*N,1>::Zero();

	// Update state from estimation
	stateData.x       = (double)(esti_msg.vrpn_orix_msg);
	stateData.y       = (double)(esti_msg.vrpn_oriy_msg);
	stateData.z       = (double)(esti_msg.vrpn_oriz_msg);
	stateData.w       = (double)(esti_msg.vrpn_oriw_msg);
	stateData.xPos    = (double)(esti_msg.vrpn_posx_msg);
	stateData.yPos    = (double)(esti_msg.vrpn_posy_msg);
	stateData.zPos    = (double)(esti_msg.vrpn_posz_msg);
	stateData.xVel    = (double)(esti_msg.vrpn_velx_msg);
	stateData.yVel    = (double)(esti_msg.vrpn_vely_msg);
	stateData.zVel    = (double)(esti_msg.vrpn_velz_msg);
	stateData.yaw     = (double)(esti_msg.vrpn_yaw_msg);

	// MPC Controller On
	if(controlFlag == 1)
	{
		startTime = ros::Time::now();
		// MPC Controller iteration
		Us = gdnController.GdnCont(stateData,refPosFlag,xRef,yRef,zRef);
		endTime = ros::Time::now();

		// Apply first input
		rollDesired    = Us(0,0);
		pitchDesired  = Us(1,0);
		yawRateDesired    = Us(2,0);
		thrustDesired = Us(3,0);

	}
	else //Manual mode ON
	{
		// Reset MPC Controller
	  	gdnController.ResetCont(stateData);

	  	// No reference to track
		xRef = stateData.xPos;
		yRef = stateData.yPos;
		zRef = stateData.zPos;

		// No input from MPC controller
		rollDesired = 0.0;
		pitchDesired = 0.0;
		yawRateDesired = 0.0;
		thrustDesired = 0.0;

		// Joystick input
		offset_phi = stateData.rollFromJoystick;
		offset_the = stateData.pitchFromJoystick;
		offset_thr = stateData.pitchFromJoystick;

	}

	// Apply yaw rotation for MPC input
	double c = cos(stateData.yaw);
	double s = sin(stateData.yaw);

	double pitchYawRotated = c*pitchDesired + s*rollDesired;
	double rollYawRotated = -1.0*s*pitchDesired + c*rollDesired;
	rollDesired   = rollYawRotated;
	pitchDesired = pitchYawRotated;

	// Sum input (MPC or Joystick)
	mpcInputMsg.rollPhi = rollDesired   + offset_phi;
	mpcInputMsg.thetaPitch = pitchDesired + offset_the;
	mpcInputMsg.psiYawRate = yawRateDesired;
	mpcInputMsg.thrust = thrustDesired + offset_thr;
	mpcInputMsg.controlFlag = controlFlag;
	
	// Send command
	pubMpcInput.publish(mpcInputMsg);

	// Publish position, reference and control flag (for logging)
	mpcDataMsg.xPos = esti_msg.vrpn_posx_msg;
	mpcDataMsg.yPos = esti_msg.vrpn_posy_msg;
	mpcDataMsg.zPos = esti_msg.vrpn_posz_msg;

	mpcDataMsg.controlFlag	= controlFlag;

	mpcDataMsg.xPosRef = xRef;
	mpcDataMsg.yPosRef = yRef;
	mpcDataMsg.zPosRef = zRef;

	pubMpcData.publish(mpcDataMsg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mpc_main");
	ros::NodeHandle nh;

	subGetControlMode = nh.subscribe("joy",1, getControlModeCallback);
	subGetRef = nh.subscribe("pos_msg",1, getRefCallback);
	subGetJoystickCommand = nh.subscribe("/crazyflie/cmd_vel",1, getJoystickCommandCallback);
	subGetStateEstim = nh.subscribe("crazyflie_data_msg",1, getStateEstimCallback);
	pubMpcInput = nh.advertise<mpc::msgMPC_Input>("mpcInputMsg",100);
	pubMpcData = nh.advertise<mpc::msgMPC_Data>("mpcDataMsg",100);

	ros::spin();

	return 0;
}
