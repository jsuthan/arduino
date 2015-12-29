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
 */


void lUp(int tPin){
  digitalWrite(tPin, HIGH);
}

void lDown(int tPin){
  digitalWrite(tPin, LOW);
}

void lC(int i,int tPin){
  if(i==1){
    lUp(tPin);
  }else{
    lDown(tPin);
  }
}

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  for(int i=8;i<14;i++)
  {
  pinMode(i, OUTPUT);
  }
  //Serial.begin(9600);
}

int s=1;
int c=1;
int j=11;
int d=50;

// the loop function runs over and over again forever
void loop() {
 
 d++; 
 c++;
 for(int i=10;i<14;i++){
    lC(s,i);
    lC(s,j);
    delay(d);
    j--;
  }

 
if(s==1){
  s=0;
}else{
  s=1;
}

for(int i=14;i>10;i--){
    lC(s,i);
    lC(s,j);
    delay(d);
    j++;
  }

if(s==1){
  s=0;
}else{
  s=1;
}

if (c>5){
  s=0;
  c=0;
}else{
  s=1; 
}

if(d>1500){
  d=50;
}

}
