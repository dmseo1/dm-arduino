int sensorValue;
int pwm;
double voltage;
int LED1 = 11;
int LED2 = 10;
int LED3 = 9;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  //pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  sensorValue=analogRead(A0);
  pwm = map(sensorValue, 0, 1023, 255, 0);
  //map 매개변수: (값, 측정최저, 측정최고, 변환할 값의 최저, 변환할 값의 최대)
  voltage = map(pwm, 0, 255, 0, 5);

  if(sensorValue >= 300) {
     digitalWrite(LED1, HIGH);
     digitalWrite(LED2, HIGH);
     digitalWrite(LED3, HIGH);
  } else if(sensorValue >= 150) {
      digitalWrite(LED1, HIGH);
     digitalWrite(LED2, HIGH);
     digitalWrite(LED3, LOW);
  } else if(sensorValue >= 50){
    digitalWrite(LED1, HIGH);
     digitalWrite(LED2, LOW);
     digitalWrite(LED3, LOW);
  } else {
    digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     digitalWrite(LED3, LOW);
  }

  Serial.print("CDS value : ");
  Serial.print(sensorValue);
  Serial.print("     ");
  Serial.print("PWM : ");
  Serial.print(pwm);
  Serial.print("     ");
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println("[V]");

  

  delay(100);
}
