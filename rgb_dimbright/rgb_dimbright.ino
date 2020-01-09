#include<math.h>
int BUTTON = 2;
int RED = 11;
int GREEN = 10;
int BLUE = 9;
int count = 0;
int flag = 0;


void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
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
  int i = 256;
  while((i -= 5) > 0) {
    setColor(i, 0, i);
    Serial.println(i);
    delay(10);
  }
  while((i += 5) < 256) {
    setColor(i, 0, i);
    Serial.println(i);
    delay(10);
  }

  
}

void setColor(int red, int green, int blue) {
  analogWrite(RED, red);
  analogWrite(GREEN, green);
  analogWrite(BLUE, blue);
}
