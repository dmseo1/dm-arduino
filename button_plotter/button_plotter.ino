int BUTTON = 2;
int LED = 12;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);

}

void loop() {
  int state = digitalRead(BUTTON);

  if(state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  Serial.println(state);
  delay(1);

}
