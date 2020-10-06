#include <MeMegaPi.h>

const byte interruptPin =18;    
const byte NE1=31;                 
long count=0;
unsigned long time;
unsigned long last_time;
MeMegaPiDCMotor motor1(PORT1B);
MeMegaPiDCMotor motor2(PORT2B);  
uint8_t motorSpeed = 100;
uint8_t motorStop = 0;
void setup()
{
    pinMode(interruptPin, INPUT_PULLUP);
    pinMode(NE1, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink,RISING);   
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
    
    time =millis(); 
    if(time-last_time>2000)    
    {
          Serial.println(count);
          last_time=time;
   }
}
void blink()
{
    if (digitalRead(NE1)>0)   
    count++;
    else
    count = count -1;
}
