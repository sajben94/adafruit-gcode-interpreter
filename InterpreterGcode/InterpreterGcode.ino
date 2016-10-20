#include <Arduino.h>

// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(80, 2);
AF_Stepper motor2(80, 1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(250);  // 10 rpm
  motor2.setSpeed(250);
}


void motoX(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
    if (step1>=i) {
      motor.step(1, BACKWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE); 
    }
  }
}

void motoAX(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
    if (step1>=i) {
      motor.step(1, FORWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
  }
}


void motoY(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
    if (step1>=i) {
      motor.step(1, BACKWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE); 
    }
  }
}

void motoAY(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
    if (step1>=i) {
      motor.step(1, FORWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
  }
}

void loop() {
  Serial.println("Single coil steps");
  motoY(250,250);
  motoX(250,250);
  motoAY(250,250);
  motoAX(250,250);

}
