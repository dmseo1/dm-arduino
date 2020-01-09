int RED_LED = 11;
int YELLOW_LED = 12;

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
}

void loop() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(YELLOW_LED, LOW);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(1000);
}
