#include "PinChangeInt.h"

#define RC_1 14
#define RC_2 16
#define RC_3 15
#define RC_4 8

unsigned long ch1, ch2, ch3, ch4, ch5;

unsigned long rc1_last_1 = micros();
unsigned long rc1_last_2 = micros();

unsigned long rc2_last_1 = micros();
unsigned long rc2_last_2 = micros();

unsigned long rc3_last_1 = micros();
unsigned long rc3_last_2 = micros();

unsigned long rc4_last_1 = micros();
unsigned long rc4_last_2 = micros();

void setup(){
  Serial.begin(115200); 
  rc_init();
}


void loop(){
  
  //Serial.print("RC1=");
  //Serial.print(ch1);
  //Serial.print(" RC2=");
  //Serial.print(ch2);
  //Serial.print(" RC3=");
  //Serial.print(ch3);
  //Serial.print(" RC4=");
  //Serial.println(ch4);
  //delay(500);
  
}



void rc_init(){
  PCattachInterrupt(RC_1, rcInterrupt1, CHANGE);
  PCattachInterrupt(RC_2, rcInterrupt2, CHANGE);
  PCattachInterrupt(RC_3, rcInterrupt3, CHANGE);
  PCattachInterrupt(RC_4, rcInterrupt4, CHANGE);
}


void rcInterrupt1(){
   ch1 = rc1_last_2 - rc1_last_1;
   rc1_last_1 = rc1_last_2;
   rc1_last_2 = micros();
   if( (rc1_last_2 - rc1_last_1) < ch1 )
     ch1=rc1_last_2 - rc1_last_1;   
}

void rcInterrupt2(){
   ch2 = rc2_last_2 - rc2_last_1;
   rc2_last_1 = rc2_last_2;
   rc2_last_2 = micros();
   if( (rc2_last_2 - rc2_last_1) < ch2 )
     ch2=rc2_last_2 - rc2_last_1; 
}

void rcInterrupt3(){
   ch3 = rc3_last_2 - rc3_last_1;
   rc3_last_1 = rc3_last_2;
   rc3_last_2 = micros();
   if( (rc3_last_2 - rc3_last_1) < ch3 )
     ch3=rc3_last_2 - rc3_last_1; 
}

void rcInterrupt4(){
   ch4 = rc4_last_2 - rc4_last_1;
   rc4_last_1 = rc4_last_2;
   rc4_last_2 = micros();
   if( (rc4_last_2 - rc4_last_1) < ch4 )
     ch4=rc4_last_2 - rc4_last_1; 
}
