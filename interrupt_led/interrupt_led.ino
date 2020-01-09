#include <MsTimer2.h>

int LED1 = 11;
int LED2 = 10;
int BUTTON = 2;
int sta1 = 0;
int sta2 = 0;
unsigned long time1 = 0;
unsigned long time2 = 0;
int key = 0;
int flag = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
  time1 = millis();
  time2 = millis();
  attachInterrupt(0, yellow, CHANGE);
  //digitalPinToInterrupt(BUTTON) => 0번으로 맵핑
  //INT0 => 0 이 저장되어 있음
  //
  //attachInterrupt(INT0, yellow, CHANGE);
  //attachInterrupt(digitalPinToInterrupt(BUTTON), yellow, CHANGE);

}

void yellow() {
  time2 = millis();
  digitalWrite(LED2, HIGH);
}

int SW_chk() {
  int key = digitalRead(BUTTON);
  if(!key) {  //버튼이 눌러지지 않은 경우
    if(!flag) return 0;
    else {
      delay(20);
      flag = 0;
      return key;
    }
  } else {
    if(flag != 0) return 0;
    else {
      delay(50);
      flag = 1;
      return key;
    }
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - time1 > 1000) {
    digitalWrite(LED1, sta1 ^= 1);
    time1 = millis();
  }

  if(millis() - time2 > 1000) {
    digitalWrite(LED2, LOW);
  }
}
