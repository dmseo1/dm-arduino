int BUTTON = 2;
int LED = 12;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  int state = digitalRead(BUTTON);

  if(state == 1) {
    Serial.println("누름");
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

}
