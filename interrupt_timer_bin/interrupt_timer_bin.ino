
#include <MsTimer2.h>

int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int status = 0;
int second = 0;
int cur = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  MsTimer2::set(1000, TIMER);
  MsTimer2::start();  //이 줄은 마지막에 쓰는 것이 좋다
}

void TIMER() {
  displayBin();
  second ++;
}

void loop() {
   //put your main code here, to run repeatedly:
  if(Serial.read() == 'R') {
    Serial.println("------RESET------");
    second = cur = 0;
  }
  if(second != cur) {
    Serial.print(second / 3600);
    Serial.print(":");
    Serial.print(second / 60 - ((second / 3600) * 60));
    Serial.print(":");
    Serial.println(second % 60);
    cur ++;
  }
}

void displayBin() {
  if(second & 4)
    digitalWrite(LED3, HIGH);
  else
    digitalWrite(LED3, LOW);

  if(second & 2)
    digitalWrite(LED2, HIGH);
  else
    digitalWrite(LED2, LOW);

  if(second & 1)
    digitalWrite(LED1, HIGH);
  else
    digitalWrite(LED1, LOW);
}
