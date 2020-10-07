#include <MeMegaPi.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeUltrasonicSensor ultraSensor(PORT_8);

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.print("Distance : ");
  Serial.print(ultraSensor.distanceCm() );
  Serial.println(" cm");
  delay(100);
}
