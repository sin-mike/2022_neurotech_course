#include <Servo.h>

Servo servo;

void setup() {

  servo.attach(9);
  servo.write(0);
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {

  for (int i = 0; i <= 180; i++){
    servo.write(i);
    delay(2); 
  }

  delay(100);

  for (int i = 180; i >= 0; i--){
    servo.write(i);
    delay(2); 
  }

  delay(100);
  // put your main code here, to run repeatedly:

}
