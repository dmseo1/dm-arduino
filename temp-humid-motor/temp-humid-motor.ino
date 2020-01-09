#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>
#include <MsTimer2.h>
#include <Servo.h>

int DHTPIN = 4;
int DHTTYPE = DHT11;
int LED = 12;
int next = 0;
int cur = 0;
float t = 0;
float h = 0;
int led_state = 0;
unsigned long led_ptime = 0;
Servo myservo;
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(LED, OUTPUT);


   myservo.attach(9);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  
  led_ptime = millis();
  MsTimer2::set(1000, timer);
  MsTimer2::start();  //이 줄은 마지막에 쓰는 것이 좋다
}

void timer() {
  next ++;
}

void loop() {
  // put your main code here, to run repeatedly:

  if(next != cur) {
    t = dht.readTemperature();
    h = dht.readHumidity();
  
    if(isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    lcd.setCursor(1, 0);
    lcd.print("Tem: ");
    lcd.print(t);
    lcd.println(" 'C   ");
  
    lcd.setCursor(1, 1);
    lcd.print("Hum: ");
    lcd.print(h);
    lcd.println("  %   ");
  
    
    myservo.write(180 - (((t - 26) * 180) / (4.0)));
    
    cur++;
  }

  if(t >= 29 && millis() - led_ptime > 200) {
    digitalWrite(LED, led_state ^= 1);
    led_ptime = millis();
  }
  if(t < 29) {
    digitalWrite(LED, LOW);
  }
}
