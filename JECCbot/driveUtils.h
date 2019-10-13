/***Library for controlling the two driving motors with Arduino motor driver shield
 * Author: Jonas Wuehr
 * Date: 11.10.2019
 * Purpose: JECCbot mini
 */
#include <Arduino.h>

#define DIRECTION_LEFT 12
#define PWM_LEFT 3
#define BREAK_LEFT 9

#define DIRECTION_RIGHT 13
#define PWM_RIGHT 11
#define BREAK_RIGHT 8

#define VELOCITY_MAX 100

/***Initializes motors with defined Pin numbers***/
void initMotors();

/***Set velocity of motors from -100 to +100***/
void setMotors(int velocityLeft, int velocityRight);

/***Break motors with breaking time in milliseconds***/
void breakMotors(int timeMs);
