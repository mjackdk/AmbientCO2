/*
  AmbientCO2.h - Arduino library for CozIR Ambient CO2 sensors.
  Created by Michael Jack, April, 2020.
  Repository https://github.com/mjackdk/AmbientCO2
  Released under MIT license.
*/

#ifndef AmbientCO2_h
#define AmbientCO2_h

#include <Arduino.h>

class AmbientCO2 {
  public:
    AmbientCO2(Stream &serialPort = Serial); // Default to Serial
    void begin();
    int getCO2();
  private:
    Stream *_serial;
    int _buffer[16];
    int _index;
    int _value;
    void fillBuffer();
    int parseBuffer();
};

#endif
