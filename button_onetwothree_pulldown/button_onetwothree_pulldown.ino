int RED = 8;
int WHITE = 10;
int YELLOW = 12;
int BUTTON = 2;
int count = 0;
int flag = 0;


void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(WHITE, OUTPUT);
  pinMode(BUTTON, INPUT);
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
  if(SW_chk() == 1) {
    count ++;
//    if(count > 1) {
//      count = 0;
//    }
  }

  switch(count % 4) {
    case 0:
      digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(WHITE, LOW);
      break;
    case 1:
       digitalWrite(RED, HIGH);
      digitalWrite(YELLOW, LOW);
      digitalWrite(WHITE, LOW);
      break;
     case 2:
     digitalWrite(RED, LOW);
      digitalWrite(YELLOW, HIGH);
      digitalWrite(WHITE, LOW);
      break;
     case 3:
     digitalWrite(RED, LOW);
      digitalWrite(YELLOW, LOW);
      digitalWrite(WHITE, HIGH);
      break;
  }
//  if(count == 0) {
//    digitalWrite(RED, LOW);
//    count = 0;
//  } else {
//    digitalWrite(RED, HIGH);
//  }
}
