/***Library for encoding NMEA gps device
 * Author: Jonas Wuehr
 * Date: 22.10.2019
 * Purpose: JECCbot mini
 */

#ifndef GPS_H
#define GPS_H

#include <Arduino.h>
#include "GeoUtils.h"

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
