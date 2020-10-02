#include "MeMegaPi.h"
//#include "MeLineFollower.h"
#include <Wire.h>
#include <SoftwareSerial.h>

MeLineFollower lineFinder(PORT_6);

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorState = lineFinder.readSensors();
  switch(sensorState){
    case S1_IN_S2_IN:
      Serial.println("Sensor 1 and 2 are inside of black line");
      break;
    case S1_IN_S2_OUT:
      Serial.println("Sensor 2 is outside of black line");
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line");
      break;
    case S1_OUT_S2_OUT:
      Serial.println("Sensor 1 and 2 are outside of black line");
      break; 
  }
  delay(200);
}
