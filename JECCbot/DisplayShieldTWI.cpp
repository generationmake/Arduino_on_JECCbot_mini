#include "DisplayShieldTWI.h"

LiquidCrystal_I2C lcd(DISPLAY_SHIELD_ADDRESS_TWI, 16, 2);

void initDisplay_twi()
{
  lcd.begin();
  lcd.backlight();
  lcd.noCursor();
}

void writeStringDisplay_twi(String s)
{
  static unsigned long displayTime, lastDisplayTime;
  static bool sendDisplay;
  displayTime=millis();
  
  if(sendDisplay)
  {    
    char *cString= new char[s.length()];
    strcpy(cString, s.c_str());
    lcd.clear();
    lcd.home();

    lcd.print(s);
  }

  if((lastDisplayTime+DISPLAY_SEND_PERIOD_TWI)>displayTime)
  {
    sendDisplay=true;
    lastDisplayTime=displayTime;
  }
  else
  {
    sendDisplay=false;
  }
}

int getCurrentKeyDisplay_twi()
{
  int keyVal=analogRead(DISPLAY_KEY_TWI);
  int key;

  //Serial.println(keyVal);
  
  if(keyVal<DISPLAY_KEYVAL_RIGHT_TWI)
  {
    key=DISPLAY_KEY_RIGHT;
  }
  else if(keyVal<DISPLAY_KEYVAL_UP_TWI)
  {
    key=DISPLAY_KEY_UP;
  }
  else if(keyVal<DISPLAY_KEYVAL_DOWN_TWI)
  {
    key=DISPLAY_KEY_DOWN;
  }
  else if(keyVal<DISPLAY_KEYVAL_LEFT_TWI)
  {
    key=DISPLAY_KEY_LEFT;
  }
  else if(keyVal<DISPLAY_KEYVAL_SELECT_TWI)
  {
    key=DISPLAY_KEY_SELECT;
  }
  else
  {
    key=DISPLAY_KEY_NONE;
  }

  return key;  
}

void waitForKeyDisplay_twi(int key)
{
  while(key!=getCurrentKeyDisplay_twi())
    delay(10);
}
