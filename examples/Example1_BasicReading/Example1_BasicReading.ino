/*

 Example1_BasicReading.ino

 This sketch shows how to use the AmbientCO2 library to get CO2 readings
 from a CozIR Ambient CO2 sensor in streaming mode, using serial UART.

 Arduino --- sensor
 ------------------
 GND ------- Pin 1
 3.3V ------ Pin 3
 rxPin ----- Pin 7
 txPin ----- Pin 5

 See User's Manual, page 7, for sensor pinout
 http://co2meters.com/Documentation/Manuals/Manual_GC_0024_0025_0026_Revised8.pdf

 Open Serial Moniter or Serial Plotter in Arduino IDE after uploading sketch.

 Created by Michael Jack, April, 2020.
 Repository https://github.com/mjackdk/AmbientCO2
 Released under MIT license.

*/

#include <SoftwareSerial.h> // Arduino UNO
#include <AmbientCO2.h>

// Change to match board setup
const byte rxPin = 10;
const byte txPin = 11;

// Do NOT change, Ambient sensors only support 9600
const int baudRate = 9600;

SoftwareSerial mySerial(rxPin, txPin); // Arduino UNO

AmbientCO2 myAmbient(mySerial);

int co2 = 0;

void setup() {
  Serial.begin(baudRate);
  mySerial.begin(baudRate);
  myAmbient.begin();
}

void loop() {
  co2 = myAmbient.getCO2();
  Serial.println(co2);
}
