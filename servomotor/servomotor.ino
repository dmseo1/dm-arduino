#include<Servo.h>
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo.write(0);
//  delay(5000);
//  myservo.write(180);
//  delay(5000);
//  for(int i = 0; i <= 180; i ++) {
//    myservo.write(i);
//    delay(10);
//  }
//  delay(500);
//  for(int i = 180; i >= 0; i --) {
//    myservo.write(i);
//    delay(10);
//  }
//  delay(500);
}
