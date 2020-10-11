/***
 * Example for decoding on a NMEA device on Serial1 with 9600 BAUD (RMC String). The baudrate can be defined in GPS.h.
 * Author: Jonas Wuehr
 * Date: 11.10.2020
 * Purpose: JECCbot mini GPS
*/

#include <JECCbot.h>

JECCbot bot;

void setup() {
  bot.initJECCbot(DISPLAYSHIELD_4BIT);

}

void loop() {
  Serial.println(bot.toStringLocation());
  Serial.println(bot.toStringTime());

}
