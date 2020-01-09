void setup() {
  Serial.begin(9600); //시리얼 모니터를 쓰겠다는 뜻
  
 
}

void loop() {
  int i = 65;
  float f = 65;
  char c = 65;
  Serial.println(i);
  Serial.println(f);
  Serial.println(c);
  Serial.println("MY name");
  while(1);
}
