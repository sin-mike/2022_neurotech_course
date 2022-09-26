void setup() {
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);

}

void loop() {
  if (Serial.available()){
    int a = Serial.read();
    digitalWrite(4, a);
    Serial.write(a);
  }
}
