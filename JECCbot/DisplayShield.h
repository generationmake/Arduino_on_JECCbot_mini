/***Library for controlling the Arduino display shield
 * Author: Jonas Wuehr
 * Date: 12.12.2019
 * Purpose: JECCbot mini
 */
#ifndef DISPLAYSHIELD_H
#define DISPlAYSHIELD_H

#include "DisplayShield4bit.h"
#include "DisplayShieldTWI.h"
#include "DisplayKeyMapping.h"

#define DISPLAYSHIELD_4BIT 0
#define DISPLAYSHIELD_TWI 1

/***Initializes display shield with defined display shield type***/
void initDisplay(int type);

/***Writes String with suitable size (16 characters, linefeed, 16 characters) to display***/
void writeStringDisplay(String s);

/***Returns number of currently active key (see defines)***/
void waitForKeyDisplay(int key);

/***Wait until a specific key is pressed (keynumber see defines)***/
int getCurrentKeyDisplay();

#endif
