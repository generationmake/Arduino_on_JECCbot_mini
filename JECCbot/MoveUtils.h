/***Library for moving the robot based on different sensors
 * Author: Jonas Wuehr
 * Date: 23.10.2019
 * Purpose: JECCbot mini
 */
#ifndef MOVEUTILS_H
#define MOVEUtilS_H

#include <Arduino.h>
#include "DriveUtils.h"
#include "BNO055.h"

#define MOVE_BNO055_P 1.0

/***Moves robot using BNO055 data to a heading between -180 and 180 with
 * the maximum velocity velMax
 */
void moveBNO055(int heading, int velMax);

#endif
