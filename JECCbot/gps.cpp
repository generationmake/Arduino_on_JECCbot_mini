#include "gps.h"

void initGPS()
{
  Serial1.begin(GPS_BAUD);
}

void decodeRMC(String rmcString)
{
  Serial.write("+++++++++++++++++++++++++++++++++\n");
  Serial.write(rmcString.c_str());

  String fields[13];
  int fieldIndex=0;
  String currentField="";
  
  for(int i=7; i<rmcString.length(); i++)
  {
    char currentChar=rmcString.charAt(i);
    if(currentChar!=',')
    {
      currentField+=currentChar;
    }
    else
    {
      fields[fieldIndex]=currentField;
      Serial.write(currentField.c_str());
      Serial.write("\n");
      currentField="";
      fieldIndex++; 
    }
  }
  Serial.write("+++++++++++++++++++++++++++++++++\n");  
}

void decodeGpsString(String gpsString)
{
  Serial.write("*********************************\n");
  Serial.write(gpsString.c_str());
  Serial.write("*********************************\n");
  if(gpsString.indexOf("$GPRMC")!=-1)
  {
    decodeRMC(gpsString);    
  }
  gpsString="";
}

void serialEvent1()
{
  String gpsString="";
  while(Serial1.available())
  {
    char rec=(char)Serial1.read();
    gpsString+=rec;
    if(rec=='\n')
    {
      decodeGpsString(gpsString);
      gpsString="";
    }
  }
}
