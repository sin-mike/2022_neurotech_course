void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int pot = analogRead(A4);
  Serial.println(pot);

  delay(50);
  // put your main code here, to run repeatedly:

}
