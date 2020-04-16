//порты
const int BLED = 9;
const int GLED = 10;
const int YLED = 11;
const int RLED = 6;
const int BTN = 5;
const int Xin= A0;
const int Yin = A1; 

// счетчик
float count = 0;

void setup() 
{
   pinMode(BLED, OUTPUT);

//   дополнительные LED
//   pinMode(GLED, OUTPUT);
//   pinMode(YLED, OUTPUT);
//   pinMode(RLED, OUTPUT);


   pinMode (BTN, INPUT);
   digitalWrite(BTN, HIGH); 

}

void loop() 
{
  int xVal = analogRead (Xin);         // Считываем значение с порта Xin
  int yVal = analogRead (Yin);         // Считываем значене с порта Yin
  int buttonVal = digitalRead (BTN); // считываем значение с прта KEYin

  if ((xVal > 600 || yVal < 400)&& count < 255) {
    count +=0.1;
  }


  if ((xVal < 400 || yVal > 600 ) && count > 0) {
    count -=0.1;
  }
  
  if (buttonVal == LOW)
   {            
    count = 0 ;
   }
    analogWrite(BLED, count);

//    дополнительные LED
//    analogWrite(YLED, count);
//    analogWrite(GLED, count);
//    analogWrite(RLED, count);


//  включение 4 LED волной
//
//if ((xVal > 600 || yVal < 400)&& count < 1020) {
//    count +=0.3;
//  }
//
//
//  if ((xVal < 400 || yVal > 600 ) && count > 0) {
//    count -=0.3;
//  }
//  
//  if (buttonVal == LOW)
//   {            
//    count = 0 ;
//   }
//
//  if (count < 255) {
//    analogWrite(RLED, count);
//    analogWrite(YLED, 0);
//    analogWrite(GLED, 0);
//    analogWrite(BLED, 0);
//  } else {
//    if (count < 510) {
//      
//      analogWrite(RLED, 255);
//      analogWrite(YLED, count-255);
//      analogWrite(GLED, 0);
//      analogWrite(BLED, 0);
//    } else {
//      if (count < 765) {
//        
//        analogWrite(RLED, 255);
//        analogWrite(YLED, 255);
//        analogWrite(GLED, count-510);
//        analogWrite(BLED, 0);
//      } else {
//        analogWrite(RLED, 255);
//        analogWrite(YLED, 255);
//        analogWrite(GLED, 255);
//        analogWrite(BLED, count - 765);
//      }
//    }
  }

  
   
}
