/*
  Домашняя работа №1
  LED & Button 
  Ex-s 2
*/

boolean buttonWasUp = true;
boolean buttonIsUp  = false;
boolean ledEnabled  = false;

void setup() {
  pinMode(13, OUTPUT);
  pinMode(A1, INPUT_PULLUP);
}

void loop() {
  buttonIsUp = digitalRead(A1);
  
  if (buttonWasUp && !buttonIsUp) {

    delay(10);еу
    buttonIsUp = digitalRead(A1);

    if (!buttonIsUp) {
      ledEnabled = !ledEnabled;
      digitalWrite(13, ledEnabled);
    }
  }

  buttonWasUp = buttonIsUp;
}
