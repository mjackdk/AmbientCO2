/*
  AmbientCO2.cpp - Arduino library for CozIR Ambient CO2 sensors.
  Created by Michael Jack, April, 2020.
  Repository https://github.com/mjackdk/AmbientCO2
  Released under MIT license.
*/

#include <AmbientCO2.h>

// Constructor
AmbientCO2::AmbientCO2(Stream &serialPort) {
  _serial = &serialPort;
  _setup = false;
}

// Set up initial state
void AmbientCO2::begin() {

  // Only run begin() once
  if (_setup == false) {
    delay(1000);  // Let sensor warm up
    _setup = true;
  }
}

int AmbientCO2::getCO2() {
  fillBuffer();

  return parseBuffer();
}

void AmbientCO2::fillBuffer() {
  _index = 0;

  while(_buffer[_index - 1] != 0x0A) { // ASCII LF in hex
    if (_serial->available()) {
      _buffer[_index] = _serial->read();
      _index++;
    }
  }
}

int AmbientCO2::parseBuffer() {
  _value = 0;

  for (byte j = 7; j > 2; j--) { // Buffer contains e.g. ASCII ' Z 00567' in hex
    _value += (_buffer[j] - 0x30) * pow(10, 7 - j); // Subtract 0, multiply by proper power of 10
  }

  return _value; // Value contains e.g '567' as int
}
