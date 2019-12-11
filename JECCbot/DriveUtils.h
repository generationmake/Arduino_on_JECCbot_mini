/***Library for controlling the two driving motors with Arduino motor driver shield
 * TODO: Use current sense, ramped speedup/ slowdown
 * Author: Jonas Wuehr
 * Date: 11.10.2019
 * Purpose: JECCbot mini
 */

#ifndef DRIVEUTILS_H
#define DRIVEUTILS_H

#include <Arduino.h>

#define DIRECTION_RIGHT 12
#define PWM_RIGHT 3
#define BREAK_RIGHT 9

#define DIRECTION_LEFT 13
#define PWM_LEFT 11
#define BREAK_LEFT 8

#define VELOCITY_MAX 100

/***Initializes motors with defined Pin numbers***/
void initMotors();

/***Set velocity of motors from -100 to +100***/
void setMotors(int velocityLeft, int velocityRight);

/***Break motors with breaking time in milliseconds***/
void breakMotors(int timeMs);

#endif
