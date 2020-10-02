#include <MeMegaPi.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeLineFollower lineFinder(PORT_6);

//motor_setup
const byte interruptPin =18;    
const byte NE1=31;                 
long count=0;
unsigned long time;
unsigned long last_time;
MeMegaPiDCMotor motor1(PORT1B);  
MeMegaPiDCMotor motor2(PORT2B);
MeMegaPiDCMotor motor3(PORT3B); 
uint8_t motorSpeed = 185;
uint8_t motorSpeed2 = 100;
uint8_t motorSpeed3 = 100;
uint8_t motorStop = 0;
//motor_setup_end

void setup(){
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(NE1, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink,RISING);
  Serial.begin(9600);
}

void loop(){
  int sensorState = lineFinder.readSensors();
  switch(sensorState){
    case S1_IN_S2_IN:
      Serial.println("Sensor 1 and 2 are inside of black line");
      motor1.run(motorStop);
      motor2.run(motorStop);
      break;
    case S1_IN_S2_OUT:
      Serial.println("Sensor 2 is outside of black line");
      motor1.run(motorSpeed);
      motor2.run(motorStop);
      break;
    case S1_OUT_S2_IN:
      Serial.println("Sensor 1 is outside of black line");
      motor2.run(motorSpeed2);
      motor1.run(motorStop);
      break;
    case S1_OUT_S2_OUT:
      Serial.println("Sensor 1 and 2 are outside of black line");
      motor1.run(motorSpeed);
      motor2.run(motorSpeed2);
      break; 
  }
  delay(200);
}

void blink()
{
    if (digitalRead(NE1)>0)   
    count++;
    else
    count = count -1;
}
