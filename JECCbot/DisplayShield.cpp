#include "DisplayShield.h"

void triggerEDisplay()
{
  delay(DISPLAY_SEND_TIMEOUT);
  digitalWrite(DISPLAY_EN, HIGH);
  delay(DISPLAY_SEND_TIMEOUT);
  digitalWrite(DISPLAY_EN, LOW);
  delay(DISPLAY_SEND_TIMEOUT);
}
  
void sendByteDisplay(byte payload, int dataOrCommand)
{ 
  digitalWrite(DISPLAY_RS, dataOrCommand);
  digitalWrite(DISPLAY_D4, (payload & 0b00010000)>>4);
  digitalWrite(DISPLAY_D5, (payload & 0b00100000)>>5);
  digitalWrite(DISPLAY_D6, (payload & 0b01000000)>>6);
  digitalWrite(DISPLAY_D7, (payload & 0b10000000)>>7);

  triggerEDisplay();

  digitalWrite(DISPLAY_D4, (payload & 0b00000001)>>0);
  digitalWrite(DISPLAY_D5, (payload & 0b00000010)>>1);
  digitalWrite(DISPLAY_D6, (payload & 0b00000100)>>2);
  digitalWrite(DISPLAY_D7, (payload & 0b00001000)>>3);

  triggerEDisplay();
}

void clearDisplay()
{
  sendByteDisplay(0x01, 0);
  sendByteDisplay(0x02, 0);
}

void sendCharDisplay(char c)
{
  sendByteDisplay(c, 1);
}

void setCursorDisplay(int row, int column)
{
  if(row<0) row=0;
  else if(row>2) row=2;
  if(column<0) column=0;
  else if(column>15) column=15;

  if(row==0)
    sendByteDisplay((column|0x80), 0);
  else if(row==1)
    sendByteDisplay((column|0x80)+0x40, 0);
}

void initDisplay()
{
  pinMode(DISPLAY_D4, OUTPUT);
  pinMode(DISPLAY_D5, OUTPUT);
  pinMode(DISPLAY_D6, OUTPUT);
  pinMode(DISPLAY_D7, OUTPUT);
  pinMode(DISPLAY_RS, OUTPUT);
  pinMode(DISPLAY_EN, OUTPUT);
  
  sendByteDisplay(0x33, 0);
  sendByteDisplay(0x32, 0);
  sendByteDisplay(0x28, 0);
  sendByteDisplay(0x0C, 0);
  sendByteDisplay(0x06, 0);
  sendByteDisplay(0x01, 0);
}

void writeStringDisplay(String s)
{
  static unsigned long displayTime, lastDisplayTime;
  static bool sendDisplay;
  displayTime=millis();
  
  if(sendDisplay)
  {    
    char *cString= new char[s.length()];
    strcpy(cString, s.c_str());
    clearDisplay();
    delay(5);
    setCursorDisplay(0, 0);
    for(int i=0; i<s.length(); i++)
    {
      if(cString[i]=='\n')
      {
        setCursorDisplay(1, 0);
        i++;
      }
      if(i<s.length())
        sendCharDisplay(cString[i]);
    }
    delay(90);
  }

  if((lastDisplayTime+DISPLAY_SEND_PERIOD)>displayTime)
  {
    sendDisplay=true;
    lastDisplayTime=displayTime;
  }
  else
  {
    sendDisplay=false;
  }
}

int getCurrentKeyDisplay()
{
  int keyVal=analogRead(DISPLAY_KEY);
  int key;

  Serial.println(keyVal);
  
  if(keyVal<DISPLAY_KEYVAL_RIGHT)
  {
    key=DISPLAY_KEY_RIGHT;
  }
  else if(keyVal<DISPLAY_KEYVAL_UP)
  {
    key=DISPLAY_KEY_UP;
  }
  else if(keyVal<DISPLAY_KEYVAL_DOWN)
  {
    key=DISPLAY_KEY_DOWN;
  }
  else if(keyVal<DISPLAY_KEYVAL_LEFT)
  {
    key=DISPLAY_KEY_LEFT;
  }
  else if(keyVal<DISPLAY_KEYVAL_SELECT)
  {
    key=DISPLAY_KEY_SELECT;
  }
  else
  {
    key=DISPLAY_KEY_NONE;
  }

  return key;
}

void waitForKeyDisplay(int key)
{
  while(key!=getCurrentKeyDisplay())
    delay(10);
}
