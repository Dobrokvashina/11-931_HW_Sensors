/*
  Домашняя работа №1
  LED & Button 
  Ex-s 1b
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  for (int i = 0; i <3; i++){
    tochka();
  }
  for (int i = 0; i <3; i++){
    tire();
  }
  for (int i = 0; i <3; i++){
    tochka();
  }
  probel();
}

void tire() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(600);
  digitalWrite(LED_BUILTIN, LOW);
  delay(600); 
}

void tochka() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(300);
  digitalWrite(LED_BUILTIN, LOW);
  delay(600); 
}

void probel() {
  delay(1800);
}
