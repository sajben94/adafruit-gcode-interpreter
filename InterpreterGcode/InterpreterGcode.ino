#include <Arduino.h>

// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

// Connect a stepper motor with 48 steps per revolution (7.5 degree)
// to motor port #2 (M3 and M4)
AF_Stepper motor1(80, 1);
AF_Stepper motor2(80, 2);

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!");

  motor1.setSpeed(250);  //rpm
  motor2.setSpeed(250);
}

void motoAY(int step1, int step2){
  if (step1>step2) {
    for (int i = 1; i<step2;i++){
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
    for (int i = 1; i < (step1-step2); i++) {
      motor2.release();
      motor1.step(1, FORWARD, SINGLE);
    }
  }else if(step1<step2){
    for (int i = 1; i<step1;i++){
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
    for (int i = 1; i < (step2-step1); i++) {
      motor1.release();
      motor2.step(1, BACKWARD, SINGLE);
    }
  }
}

void motoY(int step1, int step2){
  if (step1>step2) {
    for (int i = 1; i<step2;i++){
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    for (int i = 1; i < (step1-step2); i++) {
      motor2.release();
      motor1.step(1, BACKWARD, SINGLE);
    }
  }else if(step1<step2){
    for (int i = 1; i<step1;i++){
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    for (int i = 1; i < (step2-step1); i++) {
      motor1.release();
      motor2.step(1, FORWARD, SINGLE);
    }
  }
}

void motoAX(int step1, int step2){
  if (step1>step2) {
    for (int i = 1; i<step2;i++){
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    for (int i = 1; i < (step1-step2); i++) {
      motor2.release();
      motor1.step(1, FORWARD, SINGLE);

    }
  }else if(step1<step2){
    for (int i = 1; i<step1;i++){
      motor1.step(1, FORWARD, SINGLE);
      motor2.step(1, FORWARD, SINGLE);
    }
    for (int i = 1; i < (step2-step1); i++) {
      motor1.release();
      motor2.step(1, FORWARD, SINGLE);
    }
  }
}

void motoX(int step1, int step2){
  if (step1>step2) {
    for (int i = 1; i<step2;i++){
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
    for (int i = 1; i < (step1-step2); i++) {
      motor2.release();
      motor1.step(1, BACKWARD, SINGLE);
    }
  }else if(step1<step2){
    for (int i = 1; i<step1;i++){
      motor1.step(1, BACKWARD, SINGLE);
      motor2.step(1, BACKWARD, SINGLE);
    }
    for (int i = 1; i < (step2-step1); i++) {
      motor1.release();
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
