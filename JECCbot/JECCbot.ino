/***Simple JECCbot go straight with BNO055 example. Destiny heading can be set with select key.
 * Driving can be started with right key and stopped with left key.
 * Author: Jonas Wuehr
 * Date: 11.10.2019
 * Purpose: JECCbot mini
 */

#include "JECCbot.h"

JECCbot bot;

int destinyHeading;

bool drive;

void setup() {
  bot.initJECCbot();
  drive=false;
  destinyHeading=0;
}

void loop() {
  if(bot.getCurrentKey()==DISPLAY_KEY_SELECT)
    destinyHeading=bot.getBNOData().heading;

  if(bot.getCurrentKey()==DISPLAY_KEY_LEFT)
    drive=false;

  if(bot.getCurrentKey()==DISPLAY_KEY_RIGHT)
    drive=true;

  if(drive)
    bot.moveToHeading(destinyHeading, 100);
    //bot.setMotorSpeeds(70, 70);
  else
  {
    bot.sendStringToDisplay(bot.toStringBNOData());
    bot.setMotorSpeeds(0, 0);
  }
  //  bot.sendStringToDisplay(bot.toStringBNOData());
  //}
}
