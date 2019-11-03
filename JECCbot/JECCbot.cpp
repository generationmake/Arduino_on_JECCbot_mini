#include "JECCbot.h"

JECCbot::JECCbot()
{
  Serial.begin(9600);
  initBNO();
  initDisplay();
  initMotors();
  setMotorSpeeds(0, 0);
  initGPS();
}

BNOData JECCbot::getBNOData()
{
  updateBNO();
  return bnoData;
}

String JECCbot::toStringBNOData()
{
  return toStringBNO();
}

GPSData JECCbot::getGPSData()
{
  return gpsData;
}

String JECCbot::toStringLocation()
{
  return toStringGPSLocation();
}

String JECCbot::toStringTime()
{
  return toStringGPSLocation();
}

float JECCbot::getDistance(float latitude1, float longitude1, float latitude2, float longitude2)
{
  Coordinate c1;
  c1.latitude=latitude1;
  c1.longitude=longitude1;

  Coordinate c2;
  c2.latitude=latitude2;
  c2.longitude=longitude2;

  return calculateDistance(c1, c2);
}
float JECCbot::getBearing(float latitude1, float longitude1, float latitude2, float longitude2)
{
  Coordinate c1;
  c1.latitude=latitude1;
  c1.longitude=longitude1;

  Coordinate c2;
  c2.latitude=latitude2;
  c2.longitude=longitude2;

  return calculateBearing(c1, c2);
}

void JECCbot::setMotorSpeeds(int speedLeft, int speedRight)
{
  setMotors(speedLeft, speedRight);
}

void JECCbot::moveToHeading(int heading, int speedMax)
{
  moveBNO055(heading, speedMax);
}

void JECCbot::sendStringToDisplay(String s)
{
  writeStringDisplay(s);
}

void JECCbot::waitForKey(int key)
{
  waitForKeyDisplay(key);  
}

int JECCbot::getCurrentKey()
{
  return getCurrentKeyDisplay();
}
