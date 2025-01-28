#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int rightDirection = 12;
int rightPWM = 3;
int brakeLeft = 9;

int leftDirection = 13;
int leftPWM = 11;
int brakeRight = 8;

int speed = 5;

int incomingByte = 0;

void setup() {
  Serial.begin(9600);
  Dabble.begin(9600);

  pinMode(rightDirection, OUTPUT);
  pinMode(rightPWM, OUTPUT);
  pinMode(brakeRight, OUTPUT);

  pinMode(leftDirection, OUTPUT);
  pinMode(leftPWM, OUTPUT);
  pinMode(brakeLeft, OUTPUT);  
}

void loop() {

  Dabble.processInput();
  if(GamePad.isUpPressed()){
    Serial.println("U");
    
    digitalWrite(rightDirection, HIGH); //Motor control for forward
    analogWrite(rightPWM, speed*51);
    digitalWrite(brakeRight, LOW);

    digitalWrite(leftDirection, HIGH);
    analogWrite(leftPWM, speed*51);
    digitalWrite(brakeLeft, LOW);
  }
  if(GamePad.isDownPressed()){
    Serial.println("D");
    digitalWrite(rightDirection, LOW); //Motor control for backward
    analogWrite(rightPWM, speed*51);
    digitalWrite(brakeRight, LOW);

    digitalWrite(leftDirection, LOW);
    analogWrite(leftPWM, speed*51);
    digitalWrite(brakeLeft, LOW);
  }
  if(GamePad.isRightPressed()){
    Serial.println("R");
    digitalWrite(rightDirection, HIGH); //Motor control for right
    analogWrite(rightPWM, speed*51);
    digitalWrite(brakeRight, LOW);

    digitalWrite(leftDirection, HIGH);
    analogWrite(leftPWM, speed*5);
    digitalWrite(brakeLeft, LOW);
  }
  if(GamePad.isLeftPressed()){
    Serial.println("L");
    digitalWrite(rightDirection, HIGH); //Motor control for left
    analogWrite(rightPWM, speed*5);
    digitalWrite(brakeRight, LOW);

    digitalWrite(leftDirection, HIGH);
    analogWrite(leftPWM, speed*51);
    digitalWrite(brakeLeft, LOW);
  }
  if(GamePad.isCrossPressed()){
    Serial.println("Stop");
    digitalWrite(rightDirection, LOW); //Motor control for brakes
    analogWrite(rightPWM, 0);
    digitalWrite(brakeRight, HIGH);

    digitalWrite(leftDirection, LOW);
    analogWrite(leftPWM, 0);
    digitalWrite(brakeLeft, HIGH);
  }
  if(GamePad.isSquarePressed()){
    speed = 2.5;
  }
  if(GamePad.isCirclePressed()){
    speed = 5;
  }
}
