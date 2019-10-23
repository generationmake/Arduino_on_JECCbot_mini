#include <Wire.h>
#include "driveUtils.h"
#include "bno055.h"
#include "displayShield.h"

void setup() {
  //initMotors();
  //setMotors(0, 0); 
  initDisplay();
  Serial.begin(9600);
  initBNO();
}

void loop() {
  updateBNO();
  writeStringDisplay(toStringBNO());
}
