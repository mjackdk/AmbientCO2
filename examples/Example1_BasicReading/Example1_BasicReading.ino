#include <AmbientCO2.h>

AmbientCO2 ambient;

void setup() {

  Serial.begin(9600);
  Serial.println("Ambient CO2 Basic Reading");

  ambient.begin();
}

void loop() {
  Serial.println(ambient.readCO2());
}
