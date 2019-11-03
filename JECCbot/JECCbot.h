/***JECCbot library final object oriented include header
 * Author: Jonas Wuehr
 * Date: 31.10.2019
 * Purpose: JECCbot mini
 */

#ifndef JECCBOT_H
#define JECCBOT_H

#include "Bno055.h"
#include "DisplayShield.h"
#include "DriveUtils.h"
#include "GeoUtils.h"
#include "Gps.h"
#include "MoveUtils.h"

class JECCbot
{
  public:

    /***Initializes JECCbot instance with all sensors and actuators***/
    JECCbot();

    /***Returns data from BNO055 as struct including
     * calibration data and heading:
     * int calibStat; //0-100%
     * int sys; //0-100%
     * int gyr; //0-100%
     * int acc; //0-100%
     * int mag; //0-100%
     * int heading; //-180 to 180 degrees
     */
    BNOData getBNOData();

    /***Returns data from BNO055 as String suitable for lcd display shield***/
    String toStringBNOData();

    /***Returns data from GPS module as struct including
     * time and location:
     * int hours, minutes, seconds;
     * Coordinate coordinate; (struct including float latitude and float longitude)
     */
    GPSData getGPSData();

    /***Returns GPS location as String suitable for lcd display shield***/
    String toStringLocation();

    /***Returns GPS time as String suitable for lcd display shield***/
    String toStringTime();

    /***Returns distance between two geolocations in meters***/
    float getDistance(float latitude1, float longitude1, float latitude2, float longitude2);

    /***Returns bearing between two geolocations in degrees from -180 to 180***/
    float getBearing(float latitude1, float longitude1, float latitude2, float longitude2);

    /***Set velocity of motors from -100 to +100***/
    void setMotorSpeeds(int speedLeft, int speedRight);

    /***Moves robot using BNO055 data to a heading between -180 and 180 with
     * the maximum velocity velMax
     */
    void moveToHeading(int heading, int speedMax);

    /***Sends String with suitable size (16 characters, linefeed, 16 characters) to display***/
    void sendStringToDisplay(String s);

    /***Wait until a specific key is pressed (keynumber see defines in DisplayShield.h)***/
    void waitForKey(int key);

    /***Returns number of currently active key (see defines in DisplayShield.h***/
    int getCurrentKey();
};
#endif
