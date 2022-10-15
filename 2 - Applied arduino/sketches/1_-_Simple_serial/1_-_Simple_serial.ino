
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600); // for Arduino nano it is better less than 57600, as 115200 has seldom flashing fails
}

// the loop routine runs over and over again forever:
void loop() {
//    Serial.println("Hello world");
//    Serial.print("Hello world");

  const uint8_t s[11] = {72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100};
  for (int i = 0; i<11; i++){
    Serial.write(s[i]);
  }
  Serial.println();
  
  
  delay(1000);        // delay in between reads for stability
}
