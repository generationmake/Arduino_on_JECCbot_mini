#include "Bno055.h"

BNOData bnoData;

void initBNO()
{
    Wire.begin();

    Wire.beginTransmission(BNO055_ADDRESS);
    Wire.write(BNO055_REGISTER_OPMODE);
    Wire.write(BNO055_VALUE_OPMODE);
    Wire.endTransmission(false);  
}

void updateBNO()
{
  //Check opmode
  Wire.beginTransmission(BNO055_ADDRESS);
  Wire.write(BNO055_REGISTER_OPMODE);
  Wire.endTransmission(false);
  Wire.requestFrom(BNO055_ADDRESS, 1, true);
  byte opmode=Wire.read();
  if(opmode!=BNO055_VALUE_OPMODE)
  {
    Wire.beginTransmission(BNO055_ADDRESS);
    Wire.write(BNO055_REGISTER_OPMODE);
    Wire.write(BNO055_VALUE_OPMODE);
    Wire.endTransmission(false);
  }

  //Read calibraion
  Wire.beginTransmission(BNO055_ADDRESS);
  Wire.write(BNO055_REGISTER_CALIBSTAT);
  Wire.endTransmission(false);
  Wire.requestFrom(BNO055_ADDRESS, 4, true);
  byte mag=Wire.read();
  byte acc=Wire.read();
  byte gyr=Wire.read();
  byte sys=Wire.read();

  bnoData.mag=(int)((float)mag/2.55);
  bnoData.acc=(int)((float)acc/2.55);
  bnoData.gyr=(int)((float)gyr/2.55);
  bnoData.sys=(int)((float)sys/2.55);

  bnoData.calibStat=(bnoData.mag+bnoData.acc+bnoData.gyr+bnoData.sys)/4;
  
  //Read heading
  Wire.beginTransmission(BNO055_ADDRESS);
  Wire.write(BNO055_REGISTER_HEADING);  
  Wire.endTransmission(false);
  Wire.requestFrom(BNO055_ADDRESS, 2, true);
  byte b1=Wire.read();
  byte b2=Wire.read();
  Wire.endTransmission(false);
  uint16_t rawHeading=(b2<<8)|b1;
  int heading=(int)((float)rawHeading/16.0);
  if(heading>180)
    heading=heading-360;
  bnoData.heading=heading;
}

String toStringBNO()
{
  String str="BNO HEADING "+String(bnoData.heading, DEC)+"\nS"+String(bnoData.sys, DEC)+"G"+
  String(bnoData.gyr, DEC)+"A"+String(bnoData.acc, DEC)+"M"+String(bnoData.mag, DEC);
  
  return str;
}
