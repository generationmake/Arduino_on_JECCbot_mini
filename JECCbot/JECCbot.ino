#include <Wire.h>
#include "BNO055.h"
#include "DisplayShield.h"
#include "MoveUtils.h"

int destinyHeading=0;
bool drive=false;

void setup() {
  initMotors();
  setMotors(0, 0); 
  initDisplay();
  Serial.begin(9600);
  initBNO();
}

void loop() {
  updateBNO();
  writeStringDisplay(toStringBNO());
  
  if(getCurrentKeyDisplay()==DISPLAY_KEY_SELECT)
    destinyHeading=bnoData.heading;
 
  if(getCurrentKeyDisplay()==DISPLAY_KEY_LEFT)
    drive=false;

  if(getCurrentKeyDisplay()==DISPLAY_KEY_RIGHT)
    drive=true;

  if(drive)
    moveBNO055(destinyHeading, 100);
  else
    setMotors(0, 0);
}
