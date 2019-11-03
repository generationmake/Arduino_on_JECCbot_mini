#include "DriveUtils.h"

void initMotors()
{
  pinMode(DIRECTION_LEFT, OUTPUT);
  pinMode(DIRECTION_RIGHT, OUTPUT);
  //pinMode(BREAK_LEFT, OUTPUT);
  //pinMode(BREAK_RIGHT, OUTPUT);
  analogWrite(PWM_LEFT, 0);
  analogWrite(PWM_RIGHT, 0);
  //digitalWrite(BREAK_LEFT, HIGH);
  //digitalWrite(BREAK_RIGHT, HIGH);
}


void setMotorLeft(int velocity)
{
  velocity=(int)(velocity*2.55);
  if(velocity>0)
  {
    if(velocity>VELOCITY_MAX)
      velocity=VELOCITY_MAX;
    analogWrite(PWM_LEFT, velocity);
    digitalWrite(DIRECTION_LEFT, LOW);
  }
  else
  {
    velocity=velocity*(-1);
    if(velocity>VELOCITY_MAX)
      velocity=VELOCITY_MAX;
    analogWrite(PWM_LEFT, velocity);
    digitalWrite(DIRECTION_LEFT, HIGH);
  }
  //digitalWrite(BREAK_LEFT, LOW);  
}

void setMotorRight(int velocity)
{
  velocity=(int)(velocity*2.55);
  if(velocity>0)
  {
    if(velocity>VELOCITY_MAX)
      velocity=VELOCITY_MAX;
    analogWrite(PWM_RIGHT, velocity);
    digitalWrite(DIRECTION_RIGHT, LOW);
  }
  else
  {
    velocity=velocity*(-1);
    if(velocity>VELOCITY_MAX)
      velocity=VELOCITY_MAX;
    analogWrite(PWM_RIGHT, velocity);
    digitalWrite(DIRECTION_RIGHT, HIGH);
  }
  //digitalWrite(BREAK_RIGHT, LOW);  
}

void setMotors(int velocityLeft, int velocityRight)
{
  setMotorLeft(velocityLeft);
  setMotorRight(velocityRight);
}

void breakMotorLeft()
{
  analogWrite(PWM_LEFT, 0);
  //digitalWrite(BREAK_LEFT, HIGH);  
}

void breakMotorRight()
{
  analogWrite(PWM_LEFT, 0);
  //digitalWrite(BREAK_LEFT, HIGH);
}

void breakMotors(int timeMs)
{
  breakMotorLeft();
  breakMotorRight();
  delay(timeMs);
}
