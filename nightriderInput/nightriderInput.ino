#include <TimerOne.h>

/*
  Blink
 Turns on an LED on for one second, then off for one second, repeatedly.
 
 Most Arduinos have an on-board LED you can control. On the Uno and
 Leonardo, it is attached to digital pin 13. If you're unsure what
 pin the on-board LED is connected to on your Arduino model, check
 the documentation at http://arduino.cc
 
 This example code is in the public domain.
 
 modified 8 May 2014
 by Scott Fitzgerald
 modified 30 Dec 2015
 by jsuthan in memory of 2015 :)
 */

#define IntPeriod 100000
#define IntPin 9
int d=500; // initial delay
int max_led_pin=14; // max LED pin
int mid_led_pin=10; // middle LED pin
int low_led_pin=8; // low LED pin
int j=mid_led_pin + 1; // middle LED pin
int s = 1;  // current s value
int os = 1; // old s value
volatile boolean inFlag = 1;
volatile int inInt = 1;

void lUp(int tPin){
  digitalWrite(tPin, HIGH);
}

void lDown(int tPin){
  digitalWrite(tPin, LOW);
}

void lC(int i,int tPin){
  if(i==1){
    lUp(tPin);
  }
  else{
    lDown(tPin);
  }
}


void b8led(){
  lUp(8);
  delay(100);
  lDown(8);
}

// the setup function runs once when you press reset or power the board
int c=1; 

void setup() {
  for(int i=low_led_pin;i<max_led_pin;i++)
  {
    pinMode(i, OUTPUT);
  }

  Timer1.initialize(IntPeriod);
  Timer1.attachInterrupt(b8led);
  Serial.begin(9600);
}


boolean debounce(int last){
    boolean current = inInt;
    if(last != current){
     delay(100);
     current = inInt; 
    }
    return current;
}


// the loop function runs over and over again forever
void loop() {

  if ( os == inInt ){
    return;
  }else{
    os=inInt;
  }

  d++; 
  c++;
  for(int i=mid_led_pin;i<max_led_pin;i++){
    lC(s,i);
    lC(s,j);
    delay(d);
    j--;
  }


  for(int i=max_led_pin;i>mid_led_pin;i--){
    lC(s,i);
    lC(s,j);
    delay(d);
    j++;
  }

  if (c>5){
    c=0;
  }

  if(d>1500){
    d=50;
  }

  s=inInt;

}

void serialEvent(){
  while(Serial.available()){
    int inChar = (int)Serial.read();
    if(inChar==48) {
        Serial.println("set 1");
      inInt=1;
    }
    else if(inChar==49){
        Serial.println("set 0");
      inInt=0;   }
  }
}


