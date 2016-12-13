#ifndef STATE_MODEL_STRUCT_H
#define STATE_MODEL_STRUCT_H

/*
typedef struct {
  double xpos,ypos,zpos;
  double xvel,yvel,zvel;
  double x,y,z,w;
  double phi,the,psi,thr;
  double yaw;
} MPCData;

#endif
*/

typedef struct {
  double xPos,yPos,zPos;
  double xVel,yVel,zVel;
  double yaw;
  double x,y,z,w;
  double rollFromJoystick,pitchFromJoystick,yawRateFromJoystick,thrustFromJoystick;
} MPCData;

#endif
