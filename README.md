# Arduino_on_JECCbot_mini

## Introduction

This software is intended for Outdoor Robots which are based on Arduino. The software should support several contest tasks (more or less successful) and could also be used for general experimenting with robots.

### Supported contests

 * Robotem Rovne in Pisek ( http://kufr.cz/ )

## Hardware

### Electronics

  * Arduino Mega ( https://store.arduino.cc/arduino-mega-2560-rev3 )
  * Arduino Motor Shield ( https://store.arduino.cc/arduino-motor-shield-rev3 )
  * LCD Keypad Shield ( https://create.arduino.cc/projecthub/electropeak/using-1602-lcd-keypad-shield-w-arduino-w-examples-e02d95 or https://wiki.dfrobot.com/Arduino_LCD_KeyPad_Shield__SKU__DFR0009_ )
  * Adafruit 9-DOF Absolute Orientation IMU Fusion Breakout - BNO055 ( https://www.adafruit.com/product/2472 )

This software is tested with these components and works. It may also work with other components but we simply haven't tested it.

#### Modifications

  1. Rewire the line for the keys on the lcd keypad shield from A0 to A2.
  2. Cut the Brake signal (BRAKEA and BRAKEB) on the motor shield (Arduino Pin 8 and 9).

#### Arduino pin usage

**0** not used (communication to PC) 

**1** not used (communication to PC) 

**2** not used 

**3** Motor PWMA 

**4** Display DB4 

**5** Display DB5 

**6** Display DB6 

**7** Display DB7 

**8** Display RS 

**9** Display EN 

**10** Display PWM 

**11** Motor PWMB 

**12** Motor DIRA 

**13** Motor DIRB 

**A0** Motor SNS0 

**A1** Motor SNS1 

**A2** Display Key (Shield modified) 

**A3** not used 

**A4** I2C-SDA (BNO055) 

**A5** I2C-SCL (BNO055) 

### Mechanics

Any suitable outdoor robot with differential steering which doesn't overload the motor drivers.

For example the [JECCbot mini](https://github.com/generationmake/JECCbot_mini).
