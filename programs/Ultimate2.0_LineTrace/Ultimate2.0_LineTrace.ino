#include <MeMegaPi.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeLineFollower lineFinder(PORT_6);

//motor_setup
MeMegaPiDCMotor motor1(PORT1B);  
MeMegaPiDCMotor motor2(PORT2B); 
uint8_t motorSpeed = 70;
uint8_t motorSpeed2 = 70;
uint8_t motorSpeed3 = 70;
uint8_t motorStop = 0;
//motor_setup_end

void setup(){
  Serial.begin(9600);
}

void loop(){
  int sensorState = lineFinder.readSensors();
  switch(sensorState){
    case S1_IN_S2_IN:
      Serial.println("Sensor 1 and 2 are inside of black line");
      motor1.run(motorSpeed);
      motor2.run(motorSpeed2);
      break;
    case S1_IN_S2_OUT:
      Serial.println("Sensor 2 is outside of black line");
      motor1.run(motorSpeed);
      motor2.run(-motorSpeed3);
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line");
      motor2.run(motorSpeed2);
      motor1.run(-motorSpeed3);
      break;
    case S1_OUT_S2_OUT:
      Serial.println("Sensor 1 and 2 are outside of black line");
      motor1.run(-motorSpeed3);
      motor2.run(-motorSpeed3);
      break; 
  }
  delay(200);
}
