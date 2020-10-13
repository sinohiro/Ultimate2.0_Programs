#include "MeMegaPi.h"
#include "MeDCMotor.h"
#include "MeEncoderMotor.h"

const byte interruptPin =18;    
const byte NE1=31;                 
long count=0;
unsigned long time;
unsigned long last_time;
MeMegaPiDCMotor motor1(PORT1B);   
MeMegaPiDCMotor motor2(PORT2B)
uint8_t motorSpeed = 185;
uint8_t motorSpeed2 = 100;
uint8_t motorSpeed3 = 50;


void setup()
{
    pinMode(interruptPin, INPUT_PULLUP);
    pinMode(NE1, INPUT);
    attachInterrupt(digitalPinToInterrupt(interruptPin), blink,RISING);   
    Serial.begin(9600);   
}
void loop()
{
    motor1.run(motorSpeed);       // value: between -255 and 255
    motor2.run(motorSpeed2);
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
    count = count - 1;
}
