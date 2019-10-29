#include <Wire.h>
#include "BNO055.h"
#include "DisplayShield.h"
#include "MoveUtils.h"
#include "gps.h"

int destinyHeading=0;
bool drive=false;

void setup() {
  /*initMotors();
  setMotors(0, 0); 
  initDisplay();
  initBNO();*/
  Serial.begin(9600);
  initGPS();
}

void loop() {
  /*updateBNO();
  writeStringDisplay(toStringBNO());
  
  if(getCurrentKeyDisplay()==DISPLAY_KEY_SELECT)
    destinyHeading=bnoData.heading;
 
  if(getCurrentKeyDisplay()==DISPLAY_KEY_LEFT)
    drive=false;

  if(getCurrentKeyDisplay()==DISPLAY_KEY_RIGHT)
    drive=true;

  if(drive)
    moveBNO055(destinyHeading, 80);
  else
    setMotors(0, 0);*/
    //Serial.write("hallo\n");
}
