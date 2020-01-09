int BUTTON = 2;
int LED_RED = 8;
int LED_YELLOW = 12;
int LED_WHITE = 10;

void setup() {
  pinMode(BUTTON, INPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);

}

void loop() {
  int state = digitalRead(BUTTON);
  if(state == 1) {
     digitalWrite(LED_RED, LOW);
     digitalWrite(LED_WHITE, HIGH);
     delay(1000);
     digitalWrite(LED_WHITE, LOW);
     int i = 3;
     while(i --) {
        digitalWrite(LED_YELLOW, HIGH);
        delay(500);
        digitalWrite(LED_YELLOW, LOW);
        delay(500);
     }
  } else {
    digitalWrite(LED_RED, HIGH);
  }
}
