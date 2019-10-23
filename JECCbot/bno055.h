/***Library for using Bosch BNO055 as compass for moving robots
 * Author: Jonas Wuehr
 * Date: 12.10.2019
 * Purpose: JECCbot mini
 */
 
#ifndef BNO055_H
#define BNO055_H

#include <Arduino.h>
#include <Wire.h>

#define BNO055_ADDRESS 0x28
#define BNO055_REGISTER_OPMODE 0x3d
#define BNO055_VALUE_OPMODE 0x0c
#define BNO055_REGISTER_CALIBSTAT 0x35
#define BNO055_REGISTER_HEADING 0x1a

/***Struct for storing BNO055 data***/
typedef struct BNOData{
  int calibStat; //0-100%
  int sys; //0-100%
  int gyr; //0-100%
  int acc; //0-100%
  int mag; //0-100%
  int heading; //-180 to 180 degrees
}BNOData;

extern BNOData bnoData;

/***Initializes BNO with correct opmode***/
void initBNO();

/***Updates BNO Data struct***/
void updateBNO();

/***Returns BNO Data as String***/
String toStringBNO();

#endif
