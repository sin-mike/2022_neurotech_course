#include "Servo.h"
Servo servo;

void setup() {
  servo.attach(9);
  servo.write(0);
  delay(1000);

  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  if (Serial.available()){
    int s = Serial.read();
    servo.write(s); 
  }
  
  // put your main code here, to run repeatedly:

}
