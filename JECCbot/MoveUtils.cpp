#include "MoveUtils.h"

void moveBNO055(int heading, int velMax)
{
  static int offset, offsetOld;

  updateBNO();

  offsetOld=offset;
  offset=heading-bnoData.heading;
  
  if(offset>180)
  {
    offset=offset-360;
  }
  else if(offset<-180)
  {
    offset=360+offset;
  }

  int offsetVel=(int)(offset*MOVE_BNO055_P+(offset-offsetOld)*MOVE_BNO055_D);
  
  int left=velMax+offsetVel;
  int right=velMax-offsetVel;

  if(left<0)
    left=0;
  else if(left>velMax)
    left=velMax;

  if(right<0)
    right=0;
  else if(right>velMax)
    right=velMax;
    
  setMotors(left, right);
}
