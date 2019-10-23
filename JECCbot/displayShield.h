/***Library for controlling the Arduino display shield
 * Author: Jonas Wuehr
 * Date: 11.10.2019
 * Purpose: JECCbot mini
 */

#include <Arduino.h>

#define DISPLAY_KEY A2
#define DISPLAY_RS 8
#define DISPLAY_EN 9
#define DISPLAY_D4 4
#define DISPLAY_D5 5
#define DISPLAY_D6 6
#define DISPLAY_D7 7
#define DISPLAY_SEND_TIMEOUT 0.5

/***Initializes display shield with defined parameters***/
void initDisplay();

/***Writes String with suitable size (16 characters, linefeed, 16 characters) to display***/
void writeStringDisplay(String s);
