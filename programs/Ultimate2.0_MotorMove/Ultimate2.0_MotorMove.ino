#include <MeMegaPi.h>

MeMegaPiDCMotor motor1(PORT1B);
MeMegaPiDCMotor motor2(PORT2B);  
uint8_t motorSpeed = 100;
uint8_t motorStop = 0;
void setup()
{
    Serial.begin(9600);   
}
void loop()
{
    motor1.run(-motorSpeed);    // 前進
    motor2.run(motorSpeed);
    delay(3000);
    motor1.run(motorStop);
    motor2.run(motorStop);
    delay(1000);
    motor1.run(motorSpeed);     // 後退
    motor2.run(-motorSpeed);
    delay(3000);
    motor1.run(motorStop);
    motor2.run(motorStop);
    delay(1000);
}
