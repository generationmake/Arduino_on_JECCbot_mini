#ifndef DISPLAY_SHIELD_4BIT_H
#define DISPLAY_SHIELD_4BIT_H

#include <Arduino.h>

#define DISPLAY_KEY_4 A2
#define DISPLAY_RS_4 8
#define DISPLAY_EN_4 9
#define DISPLAY_D4_4 4
#define DISPLAY_D5_4 5
#define DISPLAY_D6_4 6
#define DISPLAY_D7_4 7

#define DISPLAY_KEY_NONE_4 0
#define DISPLAY_KEY_SELECT_4 1
#define DISPLAY_KEY_LEFT_4 2
#define DISPLAY_KEY_DOWN_4 3
#define DISPLAY_KEY_UP_4 4
#define DISPLAY_KEY_RIGHT_4 5

#define DISPLAY_SEND_TIMEOUT_4 0.5

#define DISPLAY_SEND_PERIOD_4 1000

#define DISPLAY_KEYVAL_SELECT_4 800
#define DISPLAY_KEYVAL_LEFT_4 600
#define DISPLAY_KEYVAL_DOWN_4 400
#define DISPLAY_KEYVAL_UP_4 220
#define DISPLAY_KEYVAL_RIGHT_4 100

/***Initializes display shield with defined parameters***/
void initDisplay_4();

/***Writes String with suitable size (16 characters, linefeed, 16 characters) to display***/
void writeStringDisplay_4(String s);

/***Returns number of currently active key (see defines)***/
int getCurrentKeyDisplay_4();

/***Wait until a specific key is pressed (keynumber see defines)***/
void waitForKeyDisplay_4(int key);

#endif

