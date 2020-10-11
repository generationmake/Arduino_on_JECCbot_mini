/***Library for controlling the Arduino twi display shield
 * using a local copy of https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library
 * Author: Jonas Wuehr
 * Date: 12.12.2019
 * Purpose: JECCbot mini
 */
 
#ifndef DISPLAY_SHIELD_TWI_H
#define DISPLAY_SHIELD_TWI_H

#include <Arduino.h>

#include "LiquidCrystal_I2C.h"
#include "DisplayKeyMapping.h"

#define DISPLAY_KEY_TWI A2

#define DISPLAY_SHIELD_ADDRESS_TWI 63
#define DISPLAY_SEND_PERIOD_TWI 900

#define DISPLAY_KEYVAL_SELECT_TWI 800
#define DISPLAY_KEYVAL_LEFT_TWI 600
#define DISPLAY_KEYVAL_DOWN_TWI 400
#define DISPLAY_KEYVAL_UP_TWI 220
#define DISPLAY_KEYVAL_RIGHT_TWI 100

/***Initializes display shield with defined parameters***/
void initDisplay_twi();

/***Writes String with suitable size (16 characters, linefeed, 16 characters) to display***/
void writeStringDisplay_twi(String s);

/***Wait until a specific key is pressed (keynumber see defines)***/
int getCurrentKeyDisplay_twi();

/***Returns number of currently active key (see defines)***/
void waitForKeyDisplay_twi(int key);

#endif
