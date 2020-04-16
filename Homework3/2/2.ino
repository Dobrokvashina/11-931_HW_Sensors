const int BTN = 3;     // номер вывода с кнопкой
const int LED =  13;      // номер вывода со светодиодом

volatile int buttonState = 1;
bool LEDstate = false;
int prevButState = 1;
int prevTime = 0;

void setup() 
{
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
  digitalWrite(LED, LOW);

  
  // прикрепить прерывание к вектору ISR
  attachInterrupt(1, pin_LRS, FALLING);

  Serial.begin(9600);
}

void loop() 
{
  if (buttonState != prevButState) {
    prevTime = millis();
    prevButState = buttonState;
    LEDstate =! LEDstate;
  }
  
  if (millis()-prevTime > 150 && digitalRead(BTN) == 1) {
    prevButState = 1;
    buttonState = 1;
  }
  if (LEDstate) {
    digitalWrite(LED, HIGH);
  } else {
    
    digitalWrite(LED, LOW);
  }
  Serial.println(digitalRead(LED), DEC);
}

void pin_LRS() 
{
  buttonState = 0;
}
