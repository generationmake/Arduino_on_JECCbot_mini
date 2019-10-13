#include <Wire.h>
#include "driveUtils.h"
#include "bno055.h"

void setup() {
  //initMotors();
  //setMotors(0, 0); 
  Serial.begin(9600);

  initBNO();
}

void loop() {
  updateBNO();
  Serial.print(toStringBNO());
  delay(500);
}
