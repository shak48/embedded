#include <Arduino.h>
//#include "TimerInterrupt.h"
//#include "ISR_Timer.h" 


#define DI1 7
#define DO1 8


int COMP_MATCH1,COMP_MATCH2;

volatile boolean DI1_STATE=HIGH;
void ISR1(void);
void setup() 
{
  pinMode(LED_BUILTIN, OUTPUT);    

  pinMode(DI1, INPUT);    
  digitalWrite(DI1, HIGH); // int pullup
  
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;

  PCICR |= B00000100;

  PCMSK0 |= B10000100;

  COMP_MATCH1=15000;
  COMP_MATCH2=60000;
  TCNT1 = COMP_MATCH2;

  TCCR1B |= (1<<CS12);
  //TCCR1B |= (1<<CS11);
  //TCCR1B |= (1<<CS10);

  TIMSK1 |= (1<<OCIE1A);

  attachInterrupt(digitalPinToInterrupt(DI1),ISR1,FALLING);
  interrupts();

  Serial.begin(9600);
  Serial1.begin(9600);

 
}

void loop() {
/*   
digitalWrite(13, HIGH); // sets the digital pin 13 on
  digitalWrite(DO1, HIGH); // sets the digital pin 13 on

  delay(200);            // waits for a second
  digitalWrite(13, LOW);  // sets the digital pin 13 off
  digitalWrite(DO1, HIGH); // sets the digital pin 13 on

  delay(200);            // waits for a second 
  */

 if(DI1_STATE==LOW)
 {
  DI1_STATE = HIGH;
  Serial.println("DI1 STATE LOW###############################################################################");
 }


  //Serial.println("OK");

}

ISR(TIMER1_COMPA_vect)
{
  TCNT1 = COMP_MATCH1;
    digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN)^1); 
}


void ISR1(void){
DI1_STATE=LOW;
}







