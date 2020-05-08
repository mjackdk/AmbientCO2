#include <AmbientCO2.h>
AmbientCO2 myAmbient;

// Modify to suit board setup
const byte rxPin = 10;
const byte txPin = 11;

// Include proper library, based on board type
#if defined(ARDUINO_AVR_UNO)
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(rxPin, txPin);
#elif defined(ARDUINO_AVR_MEGA2560)
  // MEGA specific code
#elif defined(ARDUINO_SAM_DUE)
  // Due specific code
#else
  #error Unsupported hardware
#endif

void setup() {

  // Ambient CO2 sensor UART only supports baud rate 9600
  Serial.begin(9600);
  mySerial.begin(9600);
  myAmbient.begin(mySerial);

}

void loop() {

  // Wait for data, write out data to Serial port, one char at a time
  if (myAmbient.available()) {
    Serial.print(myAmbient.read()); // Example: 'Z 00678'
  }

}
