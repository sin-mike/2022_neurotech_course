

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A7;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

void setup() {
  Serial.begin(57600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(A6);
 
  Serial.print(sensorValue);
  Serial.print(" ");

  sensorValue = analogRead(A7);
 
  Serial.println(sensorValue);

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(1);
}
