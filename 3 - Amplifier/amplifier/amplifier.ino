

// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A7;  // Analog input pin that the potentiometer is attached to

int sensorValue = 0;        // value read from the pot

void setup() {
  Serial.begin(57600);
}

void loop() {

  sensorValue = analogRead(analogInPin);
 
  Serial.println(sensorValue);

  delay(3);
}
