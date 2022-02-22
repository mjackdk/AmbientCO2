/*
  AmbientCO2.cpp - Arduino library for CozIR Ambient CO2 sensors.
  Created by Michael Jack, April, 2020.
  Repository https://github.com/mjackdk/AmbientCO2
  Released under MIT license.
*/

#include <AmbientCO2.h>

// Constructor
AmbientCO2::AmbientCO2(void) {
  _mode = 0;
}

// Set up initial mode
bool AmbientCO2::begin(Stream &serialPort) {
  _serial = &serialPort;
	
	 // Default to streaming mode
	if (setMode(1) == true) {
		delay(1000); // Let sensor warm up
		getCO2(); // Discard first reading
		return true;
	}
	else {
		return false;
	}
}

// Helper function for getCO2() method
void AmbientCO2::fillBuffer() {
  _index = 0;

  while(_buffer[_index - 1] != 0x0A) { // ASCII LF in hex
    if (_serial->available()) {
      _buffer[_index] = _serial->read();
      _index++;
    }
  }
}

int AmbientCO2::getCO2() {
  fillBuffer();

  return parseBuffer();
}

int AmbientCO2::getMode() {
	return _mode;
}

bool AmbientCO2::isConnected() {
	return true;
}

 // Helper function for getCO2() method
int AmbientCO2::parseBuffer() {
  _value = 0;

  for (byte j = 7; j > 2; j--) { // Buffer contains e.g. ASCII ' Z 00567' in hex
    _value += (_buffer[j] - 0x30) * pow(10, 7 - j); // Subtract 0, multiply by proper power of 10
  }

  return _value; // Value contains e.g '567' as int
}

bool AmbientCO2::setMode(int sensorMode) {
	// Command mode
	if (sensorMode == 0) {
		_serial->println("K 0");
		_mode = 0;
		return true;
	}
	// Streaming mode
	else if (sensorMode == 1) {
		_serial->println("K 1");
		_mode = 1;
		return true;
	}
	// Poll mode
	else if (sensorMode == 2) {
		_serial->println("K 2");
		_mode = 2;
		return true;
	}
	// Unknown mode
	else {
		return false;
	}
}