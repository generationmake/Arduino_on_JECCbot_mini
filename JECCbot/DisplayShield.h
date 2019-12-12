/***Library for controlling the Arduino display shield
 * Author: Jonas Wuehr
 * Date: 22.10.2019
 * Purpose: JECCbot mini
 */
#ifndef DISPLAYSHIELD_H
#define DISPlAYSHIELD_H

#include "DisplayKeyMapping.h"
#include "DisplayShield4bit.h"

void initDisplay();

void writeStringDisplay(String s);

void waitForKeyDisplay(int key);

int getCurrentKeyDisplay();

#endif
