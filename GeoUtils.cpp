#include "GeoUtils.h"

float calculateDistance(Coordinate c1, Coordinate c2)
{
  float la1=c1.latitude; float lo1=c1.longitude;
  float la2=c2.latitude; float lo2=c2.longitude;
  float latitude1R = (la1*M_PI)/180.0;
  float longitude1R = (lo1*M_PI)/180.0;
  float latitude2R = (la2*M_PI)/180.0;
  float longitude2R = (lo2*M_PI)/180.0;  
  float dlat=latitude2R-latitude1R;
  float dlong=longitude2R-longitude1R;
  float a=sin(dlat/2.0) * sin(dlat/2.0) +
            cos(latitude1R) * cos(latitude2R) *
            sin(dlong/2.0) * sin(dlong/2.0);

  return 6371000* 2 * atan2(sqrt(a), sqrt(1-a));       
}

float calculateBearing(Coordinate c1, Coordinate c2)
{
  float la1=c1.latitude; float lo1=c1.longitude;
  float la2=c2.latitude; float lo2=c2.longitude;
  float latitude1R = (la1*M_PI)/180.0;
  float longitude1R = (lo1*M_PI)/180.0;
  float latitude2R = (la2*M_PI)/180.0;
  float longitude2R = (lo2*M_PI)/180.0;    
  float y = sin(longitude2R-longitude1R) * cos(latitude2R);
  float x = cos(latitude1R)*sin(latitude2R) -
            sin(latitude1R)*cos(latitude2R)*cos(longitude2R-longitude1R);
  return (atan2(y, x)/(2*M_PI))*360.0;

}
