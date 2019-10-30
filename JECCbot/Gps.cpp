#include "Gps.h"

GPSData gpsData;

void initGPS()
{
  Serial1.begin(GPS_BAUD);
}

void decodeRMC(String rmcString)
{
  int fieldIndex=0;
  String currentField="";
  String fields[13];
  
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
      currentField="";
      fieldIndex++; 
    }
  }

  //decode time -> fieldIndex 1
  String hh, mm, ss;
  hh=fields[1].charAt(0);
  hh+=fields[1].charAt(1);
  mm=fields[1].charAt(2);
  mm+=fields[1].charAt(3);
  ss=fields[1].charAt(4);
  ss+=fields[1].charAt(5);
  gpsData.hours=hh.toInt();
  gpsData.minutes=mm.toInt();
  gpsData.seconds==ss.toInt();

  //decode latitude -> fieldIndex 3/4
  String ddLat, mmLat;
  ddLat=fields[3].charAt(0);
  ddLat+=fields[3].charAt(1);
  mmLat=fields[3].charAt(2);
  mmLat+=fields[3].charAt(3);
  mmLat+=fields[3].charAt(4);
  mmLat+=fields[3].charAt(5);
  mmLat+=fields[3].charAt(6);
  mmLat+=fields[3].charAt(7);
  mmLat+=fields[3].charAt(8);

  float lat=ddLat.toFloat()+mmLat.toFloat()/60;
  if(fields[4].charAt(0)=='S')
    lat=-lat;
  gpsData.coordinate.latitude=lat;

  //decode longitude -> fieldIndex 5/6
  String ddLon, mmLon;
  ddLon=fields[5].charAt(0);
  ddLon+=fields[5].charAt(1);
  ddLon+=fields[5].charAt(2);
  mmLon=fields[5].charAt(3);
  mmLon+=fields[5].charAt(4);
  mmLon+=fields[5].charAt(5);
  mmLon+=fields[5].charAt(6);
  mmLon+=fields[5].charAt(7);
  mmLon+=fields[5].charAt(8);
  mmLon+=fields[5].charAt(9);

  float lon=ddLon.toFloat()+mmLon.toFloat()/60;
  if(fields[6]=='W')
    lon=-lon;

  gpsData.coordinate.longitude=lon;
}

void decodeGpsString(String gpsString)
{
  if(gpsString.indexOf("$GPRMC")!=-1)
  {
    decodeRMC(gpsString);    
  }
  gpsString="";
}


void serialEvent1()
{
  String gpsString=Serial1.readStringUntil(13);
  decodeGpsString(gpsString);
}

String toStringGPSLocation()
{
  String s=String(gpsData.coordinate.latitude, DEC);
  s+="\n";
  s+=String(gpsData.coordinate.longitude, DEC);
  
  return s;
}

String toStringGPSTime()
{
  String s=String(gpsData.hours, DEC);
  s+=":";
  s+=String(gpsData.minutes, DEC);
  s+=":";
  s+=String(gpsData.seconds, DEC);
  s+="n";

  return s;
}
