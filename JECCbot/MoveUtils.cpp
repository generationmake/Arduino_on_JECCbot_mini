#include "MoveUtils.h"

void moveBNO055(int heading, int velMax)
{
  int offset=heading-bnoData.heading;
  
  if(offset>180)
  {
    offset=offset-360;
  }
  else if(offset<-180)
  {
    offset=360+offset;
  }
  
  int left=velMax+(int)((float)offset*MOVE_BNO055_P);
  int right=velMax-(int)((float)offset*MOVE_BNO055_P);

  setMotors(left, right);
}
