#include <AmbientCO2.h>

AmbientCO2::AmbientCO2(void) {
  // Constructor
}

void AmbientCO2::begin(Stream &serialPort) {
  _mySerial = &serialPort;
}

// Mimics Serial connection 'available()' function
byte AmbientCO2::available() {
  return _mySerial->available();
}

// Mimics Serial connection 'read()' function
char AmbientCO2::read() {
  return _mySerial->read();
}

// Fill buffer, parse buffer, multiply by range factor from sensor
float AmbientCO2::getCO2() {
  return 123.4;
}
