#include <AmbientCO2.h>
AmbientCO2 myAmbient;

const byte rxPin = 10;
const byte txPin = 11;

#if defined(ARDUINO_AVR_UNO)
  #include <SoftwareSerial.h>
  SoftwareSerial mySerial(rxPin, txPin);
#elif defined(ARDUINO_AVR_MEGA2560)

#elif defined(ARDUINO_SAM_DUE)

#else
  #error Unsupported hardware
#endif

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  myAmbient.begin(mySerial);
}

void loop() {
  if (myAmbient.available()) {
    Serial.print(myAmbient.read());
  }
}
