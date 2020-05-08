#include <AmbientCO2.h>

AmbientCO2::AmbientCO2(void) {
  // Constructor
}

void AmbientCO2::begin(Stream &serialPort) {
  _mySerial = &serialPort;
}

byte AmbientCO2::available() {
  return _mySerial->available();
}

char AmbientCO2::read() {
  return _mySerial->read();
}

float AmbientCO2::getCO2() {
  return 123.4;
}
