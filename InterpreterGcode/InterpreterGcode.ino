#include <Arduino.h>

// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor(200, 2);
AF_Stepper motor2(200, 1);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor.setSpeed(50);  // 10 rpm
  motor2.setSpeed(50);
}

void motoAX(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
  if (step1>=i) {motor.step(1, FORWARD, SINGLE);motor.release();}
  if (step2>=i) {motor2.step(1, FORWARD, SINGLE);motor2.release();}
  }
}

void motoX(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
  if (step1>=i) {motor.step(1, BACKWARD, SINGLE);motor.release();}
  if (step2>=i) {motor2.step(1, BACKWARD, SINGLE);motor2.release();}
  }
}

void motoY(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
    if (step1>=i) {
      motor.step(1, BACKWARD, SINGLE);
      motor.release();
    }
    if (step2>=i) {
      motor2.step(1, FORWARD, SINGLE);
      motor2.release();
    }
  }
}

void motoAY(int step1, int step2){
  int m = max(step1,step2);
  for (int i = 1; i<m;i++){
    if (step1>=i) {
      motor.step(1, FORWARD, SINGLE);
      motor.release();
    }
    if (step2>=i) {
      motor2.step(1, BACKWARD, SINGLE);
      motor2.release();
    }
  }
}

void loop() {
  Serial.println("Single coil steps");
  motoX(200,200);
  motoY(200,200);
  motoAX(200,200);
  motoAY(200,200);
  motoX(200,0);
  motoY(0,200);
  motoAX(200,0);
  motoAY(0,200);

}
