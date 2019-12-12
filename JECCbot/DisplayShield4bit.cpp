#include "DisplayShield4bit.h"

void triggerEDisplay_4()
{
  //delay(DISPLAY_SEND_TIMEOUT);
  digitalWrite(DISPLAY_EN_4, HIGH);
  delay(DISPLAY_SEND_TIMEOUT_4);
  digitalWrite(DISPLAY_EN_4, LOW);
  delay(DISPLAY_SEND_TIMEOUT_4);
}
  
void sendByteDisplay_4(byte payload, int dataOrCommand)
{ 
  digitalWrite(DISPLAY_RS_4, dataOrCommand);
  digitalWrite(DISPLAY_D4_4, (payload & 0b00010000)>>4);
  digitalWrite(DISPLAY_D5_4, (payload & 0b00100000)>>5);
  digitalWrite(DISPLAY_D6_4, (payload & 0b01000000)>>6);
  digitalWrite(DISPLAY_D7_4, (payload & 0b10000000)>>7);

  triggerEDisplay_4();

  digitalWrite(DISPLAY_D4_4, (payload & 0b00000001)>>0);
  digitalWrite(DISPLAY_D5_4, (payload & 0b00000010)>>1);
  digitalWrite(DISPLAY_D6_4, (payload & 0b00000100)>>2);
  digitalWrite(DISPLAY_D7_4, (payload & 0b00001000)>>3);

  triggerEDisplay_4();
}

void clearDisplay_4()
{
  sendByteDisplay_4(0x01, 0);
  sendByteDisplay_4(0x02, 0);
}

void sendCharDisplay_4(char c)
{
  sendByteDisplay_4(c, 1);
}

void setCursorDisplay_4(int row, int column)
{
  if(row<0) row=0;
  else if(row>2) row=2;
  if(column<0) column=0;
  else if(column>15) column=15;

  if(row==0)
    sendByteDisplay_4((column|0x80), 0);
  else if(row==1)
    sendByteDisplay_4((column|0x80)+0x40, 0);
}

void initDisplay_4()
{
  pinMode(DISPLAY_D4_4, OUTPUT);
  pinMode(DISPLAY_D5_4, OUTPUT);
  pinMode(DISPLAY_D6_4, OUTPUT);
  pinMode(DISPLAY_D7_4, OUTPUT);
  pinMode(DISPLAY_RS_4, OUTPUT);
  pinMode(DISPLAY_EN_4, OUTPUT);
  
  sendByteDisplay_4(0x33, 0);
  sendByteDisplay_4(0x32, 0);
  sendByteDisplay_4(0x28, 0);
  sendByteDisplay_4(0x0C, 0);
  sendByteDisplay_4(0x06, 0);
  sendByteDisplay_4(0x01, 0);
}

void writeStringDisplay_4(String s)
{
  static unsigned long displayTime, lastDisplayTime;
  static bool sendDisplay;
  displayTime=millis();
  
  if(sendDisplay)
  {    
    char *cString= new char[s.length()];
    strcpy(cString, s.c_str());
    clearDisplay_4();
    delay(5);
    setCursorDisplay_4(0, 0);
    for(int i=0; i<s.length(); i++)
    {
      if(cString[i]=='\n')
      {
        setCursorDisplay_4(1, 0);
        i++;
      }
      if(i<s.length())
        sendCharDisplay_4(cString[i]);
    }
    delay(90);
  }

  if((lastDisplayTime+DISPLAY_SEND_PERIOD_4)>displayTime)
  {
    sendDisplay=true;
    lastDisplayTime=displayTime;
  }
  else
  {
    sendDisplay=false;
  }
}

int getCurrentKeyDisplay_4()
{
  int keyVal=analogRead(DISPLAY_KEY_4);
  int key;

  Serial.println(keyVal);
  
  if(keyVal<DISPLAY_KEYVAL_RIGHT_4)
  {
    key=DISPLAY_KEY_RIGHT;
  }
  else if(keyVal<DISPLAY_KEYVAL_UP_4)
  {
    key=DISPLAY_KEY_UP;
  }
  else if(keyVal<DISPLAY_KEYVAL_DOWN_4)
  {
    key=DISPLAY_KEY_DOWN;
  }
  else if(keyVal<DISPLAY_KEYVAL_LEFT_4)
  {
    key=DISPLAY_KEY_LEFT;
  }
  else if(keyVal<DISPLAY_KEYVAL_SELECT_4)
  {
    key=DISPLAY_KEY_SELECT;
  }
  else
  {
    key=DISPLAY_KEY_NONE;
  }

  return key;
}

void waitForKeyDisplay_4(int key)
{
  while(key!=getCurrentKeyDisplay_4())
    delay(10);
}
