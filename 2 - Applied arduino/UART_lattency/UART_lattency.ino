void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);

}

void loop() {
  digitalWrite(4, 1);
  for (int i = 0; i<255; i++){
    Serial.write(1);
  }
  digitalWrite(4, 0);
  for (int i = 0; i<255; i++){
    Serial.write(0);
  }

  delay(1000);
}
