#ifndef AmbientCO2_h
#define AmbientCO2_h

#include <Arduino.h>

class AmbientCO2 {
  public:
    AmbientCO2(void);
    void begin(Stream &serialPort = Serial); // Defaults to Serial
    byte available();
    char read();
    float getCO2(); // Type 'float', since max value is 99999 * 10
  private:
    Stream *_mySerial;
};

#endif
