#include "ros/ros.h"
#include "generate_reference/msgReference.h"

float posx = 0.0;
float posy = 0.0;
float posz = 1.0;
int SW = 0;
int wait_count = 0;

int main(int argc, char **argv)
{
  ros::init(argc, argv, "generate_reference");
  ros::NodeHandle nh;

  ros::Publisher pos_pub = nh.advertise<generate_reference::msgReference>("pos_msg", 100);

  nh.setParam("next_posx", posx);
  nh.setParam("next_posy", posy);
  nh.setParam("next_posz", posz);
  nh.setParam("signal",SW);

  while(ros::ok())
  {
    generate_reference::msgReference msg;
    
    if(0 == SW){
      msg.signal     = SW;
      msg.next_ref_x = posx;
      msg.next_ref_y = posy;
      msg.next_ref_z = posz;
      
      nh.getParam("signal", SW);
    }
   
    else{
      wait_count++;
      msg.signal     = SW;
      msg.next_ref_x = posx;
      msg.next_ref_y = posy;
      msg.next_ref_z = posz;

      nh.getParam("next_posx", posx);
      nh.getParam("next_posy", posy);
      nh.getParam("next_posz", posz);
      nh.setParam("signal", 0);
      if(wait_count > 100)
      {
	SW = 0;
	posx = 0.0;
	posy = 0.0;
	posz = 0.0;
	nh.setParam("next_posx", posx);
	nh.setParam("next_posy", posy);
	nh.setParam("next_posz", posz);
	nh.setParam("signal",SW);

	wait_count = 0;
      }
    }
    
    pos_pub.publish(msg);
  }
  ros::spin();
  return 0;
}
