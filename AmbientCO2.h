#ifndef AmbientCO2_h
#define AmbientCO2_h

#include <Arduino.h>

class AmbientCO2 {
  public:
    AmbientCO2(void);
    void begin(Stream &serialPort = Serial);
    byte available();
    char read();
    float getCO2();
  private:
    Stream *_mySerial;
};

#endif
