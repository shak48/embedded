#include <Arduino.h>
#include "TimerInterrupt.h"
#include "ISR_Timer.h" 


#define DI1 7
#define DO1 8


volatile byte flag=HIGH;
void int1Handler(void);

void setup() {
  pinMode(13, OUTPUT);    // sets the digital pin 13 as output
  pinMode(DI1, INPUT);    
  digitalWrite(DI1, HIGH); // int pullup

  Serial.begin(9600);
  Serial1.begin(9600);
  attachInterrupt(digitalPinToInterrupt(DI1),int1Handler,CHANGE);
  interrupts();


  
}

void loop() {
  digitalWrite(13, HIGH); // sets the digital pin 13 on
  digitalWrite(DO1, HIGH); // sets the digital pin 13 on

  delay(200);            // waits for a second
  digitalWrite(13, LOW);  // sets the digital pin 13 off
  digitalWrite(DO1, HIGH); // sets the digital pin 13 on

  delay(200);            // waits for a second
  Serial.println("OK! From VS CODE");
  Serial1.println("OK! From VS Serial1");
  Serial1.println(digitalRead(DI1));

}

void int1Handler(void)
{
  if(digitalRead(DI1)==HIGH)
  {
    flag = HIGH;
  }
  else
  {
    flag=LOW;
  }
}

void pollDIFlags(int pinNumber){
  static byte prevFlagState = flag;
if(digitalRead(digitalRead(DI1) != prevFlagState))
{
   Serial1.println("DI1 Updated! ");
  Serial1.println(digitalRead(DI1));

  Serial1.println(digitalRead(DI1));

}

}



