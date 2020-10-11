#include "DisplayShield.h"

int displayType;

void initDisplay(int type)
{
  displayType = type;

  if(displayType == DISPLAYSHIELD_4BIT)
  {
    initDisplay_4(); 
  }
  else if(displayType == DISPLAYSHIELD_TWI)
  {
    initDisplay_twi();
  }
}

void writeStringDisplay(String s)
{
  if(displayType == DISPLAYSHIELD_4BIT)
  {
    writeStringDisplay_4(s); 
  }
  else if(displayType == DISPLAYSHIELD_TWI)
  {
    writeStringDisplay_twi(s);
  }
}

void waitForKeyDisplay(int key)
{
  if(displayType == DISPLAYSHIELD_4BIT)
  {
    waitForKeyDisplay_4(key);
  }
  else if(displayType == DISPLAYSHIELD_TWI)
  { 
    waitForKeyDisplay_twi(key);
  }
}

int getCurrentKeyDisplay()
{
  if(displayType == DISPLAYSHIELD_4BIT)
  {
    return getCurrentKeyDisplay_4(); 
  }  
  else if(displayType == DISPLAYSHIELD_TWI)
  {
    return getCurrentKeyDisplay_twi();
  }
}
