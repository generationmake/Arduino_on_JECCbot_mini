#include "bno055.h"

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
  String str="***************************************\n";
  str+="BNO 055 data\n";
  str+="Calibration status: "+String(bnoData.calibStat, DEC)+"%\n";
  str+="\tSys: "+String(bnoData.sys, DEC)+"%\n";
  str+="\tGyr: "+String(bnoData.gyr, DEC)+"%\n";
  str+="\tACC: "+String(bnoData.acc, DEC)+"%\n";
  str+="\tMAG: "+String(bnoData.mag, DEC)+"%\n";
  str+="Heading: "+String(bnoData.heading, DEC)+"°\n";
  str+="***************************************\n\n";
  return str;
}
