int sensorValue;
int pwm;
double voltage;
int LED = 11;

void setup() {
  pinMode(LED, OUTPUT);
  //pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {
  sensorValue=analogRead(A0);
  pwm = map(sensorValue, 0, 1023, 255, 0);
  voltage = map(pwm, 0, 255, 0, 5);

  analogWrite(LED, pwm);

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
