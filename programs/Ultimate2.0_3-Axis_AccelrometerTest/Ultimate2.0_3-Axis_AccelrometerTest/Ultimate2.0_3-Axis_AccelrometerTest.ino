#include <MeMegaPi.h>
#include <SoftwareSerial.h>
#include <Wire.h>

MeGyro gyro(PORT_7);

void setup(){
  Serial.begin(9600);
  gyro.begin();
}

void loop(){
  gyro.update();
  Serial.read();
  Serial.print("X: ");
  Serial.print(gyro.getAngleX());
  Serial.print("Y: ");
  Serial.print(gyro.getAngleY());
  Serial.print("Z: ");
  Serial.println(gyro.getAngleZ());
  delay(550);
}
