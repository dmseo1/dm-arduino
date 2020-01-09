#include <MsTimer2.h>
#include <LiquidCrystal_I2C.h>

int count = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
int first = 0;
int BUTTON = 2;
int LED1 = 11;
int LED2 = 10;
int LED3 = 9;
int status = 0;
int second = 0;
int cur = 0;
int reset_flag = 0;
int key = 0;
int flag = 0;

// 실행시 가장 먼저 호출되는 함수이며, 최초 1회만 실행됩니다.
// 변수를 선언하거나 초기화를 위한 코드를 포함합니다.
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(BUTTON), timer_reset, HIGH);
  MsTimer2::set(1000, TIMER);
  MsTimer2::start();  //이 줄은 마지막에 쓰는 것이 좋다
}

void TIMER() {
 // displayBin();
  second ++;
}

void timer_reset() {
  reset_flag = 1;
}

void loop() {
   //put your main code here, to run repeatedly:
  if(Serial.read() == 'R' || reset_flag) {
    second = cur = 0;
    lcd.clear();
    
    MsTimer2::stop();
    MsTimer2::set(1000, TIMER);
    MsTimer2::start();
    
    lcd.setCursor(0, 0);
    lcd.print("    0:00:00     ");
    lcd.setCursor(0, 1);
    lcd.print("-----RESET----- ");
    reset_flag = 0;
    
  }


   
   if(!first) {
     lcd.setCursor(0, 0);
     lcd.print("    0:00:00     ");
     lcd.setCursor(0, 1);
     lcd.print("-----START----- ");
     first ++;
   }
  
  
  if(second != cur) {
    if(first == 1) {
      lcd.setCursor(0, 1);
      lcd.print("                ");
    }
    int s_hr = second / 3600;
    int s_mn = second / 60 - ((second / 3600) * 60);
    int s_sc = second % 60;


  
    lcd.setCursor(0, 0);
    lcd.print("    ");
    lcd.print(s_hr);
    lcd.print(":");
    if(s_mn < 10) lcd.print("0");
    lcd.print(s_mn);
    lcd.print(":");
    if(s_sc < 10) lcd.print("0");
    lcd.print(s_sc);
    lcd.print("    ");

    cur ++;
  }
}

//void loop() { 
//  lcd.setCursor(0, 0);
//  lcd.print("  hello  ^^;;;  ");
//  lcd.setCursor(0, 1);
//  lcd.print(" count :  ");
//  lcd.setCursor(10, 1);
//  if(count <= 255) {
//    count ++;
//    lcd.print(count);
//    delay(500);
//  } else {
//    count = 0;
//    lcd.clear();
//  }
//}

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
