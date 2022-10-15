void setup() {
  Serial.begin(57600);
  pinMode(13, INPUT);
  // put your setup code here, to run once:

}

int state = 0;

void loop() {
  int button = digitalRead(13);

//  // simple printing
//  Serial.println(button);
//  delay(50);
  

  // bouncing effects
  if ((button) & (!state)) {
    Serial.println("1");
    state = 1;
  }

  if ((!button) & (state)) {
    Serial.println("0");
    state = 0;
  }

}
