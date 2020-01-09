void setup() {
  Serial.begin(9600);
}

void loop() {
  char command;
  if(Serial.available() > 0) {
    command = Serial.read();
    if(command >= 'a' && command <= 'z') {
      Serial.println((char)(command - 32));
    }
  }
}
