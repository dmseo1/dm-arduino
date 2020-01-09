int LED1 = 8;
int LED2 = 12;
int LED3 = 10;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  char command;
  if(Serial.available() > 0) {
    command = Serial.read();

    switch(command) {
      case '1':
        digitalWrite(LED1, HIGH);
        //digitalWrite(LED2, LOW);
       //digitalWrite(LED3, LOW);
       //delay(1000);
        break;
       case '2':
       //digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        //digitalWrite(LED3, LOW);
        //delay(1000);
        break;
       case '3':
       //digitalWrite(LED1, LOW);
        //digitalWrite(LED2, LOW);
        digitalWrite(LED3, HIGH);
        //delay(1000);
        break;
       case '4':
       digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        digitalWrite(LED3, LOW);
        //delay(1000);
        break;
    }
  }
}
