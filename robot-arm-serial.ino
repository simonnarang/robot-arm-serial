#include <Arduino.h>
#include "vexMotor.h"

vexMotor base;
vexMotor shoulder;
vexMotor elbow;
Servo claw;
Servo coinFlipper;
String manual = "+-------+---+----------+---+-------+---+-------+---+-------------+---+------------+---+------------+---+\n| Base  |   | Shoulder |   | Elbow |   | Claw  |   | Coin Holder |   | Fine Motor |   | Fine Motor |   |\n+-------+---+----------+---+-------+---+-------+---+-------------+---+------------+---+------------+---+\n| Left  | A | Forward  | W | Up    | R | Open  | 3 | Flip        | 2 | Left       | J | Forward    | I |\n+-------+---+----------+---+-------+---+-------+---+-------------+---+------------+---+------------+---+\n| Right | B | Backward | S | Down  | F | Close | 4 | Un-flip     | 1 | Right      | L | Backward   | K |\n+-------+---+----------+---+-------+---+-------+---+-------------+---+------------+---+------------+---+";

int moveServo;

void setup() {
  // put your setup code here, to run once:
  base.attach(6);
  shoulder.attach(11);
  elbow.attach(3);
  claw.attach(9);
  coinFlipper.attach(10);

 Serial.begin(9600);
 Serial.println("Welcome to your new iPhone!");
 Serial.println("Just kidding, good luck using this interface :)");
 Serial.println(manual);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    moveServo = Serial.read();

    Serial.print("In ASCII, sent ");
    Serial.print(moveServo);
    Serial.println(" command to Arduino.");
    
    
    if (moveServo == 97) { base.write(100); }
    if (moveServo == 100) { base.write(-100); }
    if (moveServo == 106) { base.write(50); }
    if (moveServo == 108) { base.write(-50); }
   
   
    if (moveServo == 49) { coinFlipper.write(6); }
    if (moveServo == 50) { coinFlipper.write(167); }
   
    if (moveServo == 119) { shoulder.write(-100); }
    if (moveServo == 115) { shoulder.write(100); }
    if (moveServo == 105) { shoulder.write(-50); }
    if (moveServo == 107) { shoulder.write(50); }

    if (moveServo == 114) { elbow.write(-110); }
    if (moveServo == 102) { elbow.write(90); }

    if (moveServo == 51) { claw.write(-200); }
    if (moveServo == 52) { claw.write(250); }

    if (moveServo == 32) { base.write(0);  shoulder.write(0); elbow.write(0); claw.write(0); }
   
 }

}
