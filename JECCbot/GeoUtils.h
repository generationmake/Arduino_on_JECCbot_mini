/***Library for basic geo math
 * Author: Jonas Wuehr
 * Date: 30.10.2019
 * Purpose: JECCbot mini
 */

#ifndef GEOUTILS_H
#define GEOUTILS_H

#include <math.h>

/***struct for storing coordinate data***/
typedef struct Coordinate
{
  float latitude, longitude;
}Coordinate;

/***calculates distance between two coordinates in meters***/
float calculateDistance(Coordinate c1, Coordinate c2);

/***calculates heading between two coordinates in degrees***/
float calculateHeading(Coordinate c1, Coordinate c2);

#endif
