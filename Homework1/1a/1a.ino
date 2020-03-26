/*
  Домашняя работа №1
  LED & Button 
  Ex-s 1a
*/

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(250);
  digitalWrite(LED_BUILTIN, LOW);
  delay(250);
}
