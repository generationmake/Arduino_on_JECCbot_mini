#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include "geoUtils.h"

#define GPS_BAUD 9600

/***Struct for storing gps data**/
typedef struct GPSData
{
  int hours, minutes, seconds;
  Coordinate coordinate;
}GPSData;

extern GPSData gpsData;

/***Initializes gps on serial port 1***/
void initGPS();

/***Returns latitude longitude string***/
String toStringGPSLocation();

/***Returns time string***/
String toStringGPSTime();

#endif
