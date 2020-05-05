#ifndef AmbientCO2_h
#define AmbientCO2_h

#include "Arduino.h"

class AmbientCO2 {
  public:
    AmbientCO2();
    bool begin();
    int readCO2();
  private:
    //
};

#endif
