#include <MeMegaPi.h>
#include <Wire.h>
#include <SoftwareSerial.h>

MeLineFollower lineFinder(PORT_6);
MeUltrasonicSensor ultraSensor(PORT_8);

//motor_setup
MeMegaPiDCMotor motor1(PORT1B);
MeMegaPiDCMotor motor2(PORT2B);
MeMegaPiDCMotor motor3(PORT3B);
MeMegaPiDCMotor motor4(PORT4B);
uint8_t motorSpeed = 100;
uint8_t motorSpeed2 = 100;
uint8_t motorSpeed3 = 70;
uint8_t motorStop = 0;
int WallCount = 0;
//motor_setup_end

void setup() {
  Serial.begin(9600);
  motor3.run(motorSpeed3);
  motor4.run(-motorSpeed3);
  delay(3000);
  motor3.run(motorStop);
  motor4.run(motorStop);
}

void loop(){
  Serial.print("Distance : ");
  Serial.print(ultraSensor.distanceCm() );
  Serial.println(" cm");
  delay(100);

 
  if(ultraSensor.distanceCm() < 8) {
    motor1.run(motorStop);
    motor2.run(motorStop);
    delay(1000);
    motor3.run(-motorSpeed3);
    delay(4000);
    motor3.run(motorStop);
    if(WallCount == 0){
    motor4.run(motorSpeed3);
    delay(3700);
    WallCount++;
    }else {
      motor4.run(-motorSpeed3);
      delay(4000);
      WallCount = 0;
    }
    motor4.run(motorStop);
    motor3.run(motorSpeed3);
    delay(3700);
    motor1.run(motorSpeed);
    motor2.run(motorSpeed);
    delay(6000);
  } else {
    int sensorState = lineFinder.readSensors();

  
    switch(sensorState){
      case S1_IN_S2_IN:
        Serial.println("Sensor 1 and 2 are inside of black line");
        motor1.run(-motorSpeed);
        motor2.run(motorSpeed2);
        break;
     case S1_IN_S2_OUT:
        Serial.println("Sensor 2 is outside of black line");
        motor1.run(-motorSpeed);
        motor2.run(-motorSpeed3);
       break;
     case S1_OUT_S2_IN:
       Serial.println("Sensor 1 is outside of black line");
       motor2.run(motorSpeed2);
       motor1.run(motorSpeed3);
       break;
      case S1_OUT_S2_OUT:
       Serial.println("sensor 1 and 2 are outside of black line");
       motor1.run(motorSpeed3);
       motor2.run(-motorSpeed3);
       break;
    }
  }
  delay(200);
}
