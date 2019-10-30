/***Library for controlling the Arduino display shield
 * Author: Jonas Wuehr
 * Date: 22.10.2019
 * Purpose: JECCbot mini
 */
#ifndef DISPLAYSHIELD_H
#define DISPlAYSHIELD_H

#include <Arduino.h>

#define DISPLAY_KEY A2
#define DISPLAY_RS 8
#define DISPLAY_EN 9
#define DISPLAY_D4 4
#define DISPLAY_D5 5
#define DISPLAY_D6 6
#define DISPLAY_D7 7

#define DISPLAY_KEY_NONE 0
#define DISPLAY_KEY_SELECT 1
#define DISPLAY_KEY_LEFT 2
#define DISPLAY_KEY_DOWN 3
#define DISPLAY_KEY_UP 4
#define DISPLAY_KEY_RIGHT 5

#define DISPLAY_SEND_TIMEOUT 0.5

#define DISPLAY_SEND_PERIOD 1000

#define DISPLAY_KEYVAL_SELECT 800
#define DISPLAY_KEYVAL_LEFT 600
#define DISPLAY_KEYVAL_DOWN 400
#define DISPLAY_KEYVAL_UP 220
#define DISPLAY_KEYVAL_RIGHT 100

/***Initializes display shield with defined parameters***/
void initDisplay();

/***Writes String with suitable size (16 characters, linefeed, 16 characters) to display***/
void writeStringDisplay(String s);

/***Returns number of currently active key (see defines)***/
int getCurrentKeyDisplay();

/***Wait until a specific key is pressed (keynumber see defines)***/
void waitForKeyDisplay(int key);

#endif
