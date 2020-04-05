#include <LiquidCrystal.h>
#include <ros.h>
#include <std_msgs/String.h>



LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define BTN_UP   1
#define BTN_DOWN 2
#define BTN_LEFT 3
#define BTN_RIGHT 4
#define BTN_SELECT 5
#define BTN_NONE 10

int x = 8;
int y = 1;
String recived = "0";
bool changed = false;


ros::NodeHandle nh;

void reciveCallback(const std_msgs::String& msg) {
  recived = (String)msg.data;
  writeX();
  switch (recived.charAt(0)) {
    case 'w':
    case 's':
      if (y == 0) {
        y=1;
      } else {
        y=0;
      }
      writeO();
      break;
    case 'a':
      if (x==0) {
        x = 15;
      } else {
        x-=1;
      }
      writeO();
      break;
    case 'd':
      if (x==15) {
        x = 0;
      } else {
        x+=1;
      }
      writeO();
      break;
    default:
      writeX();
      break;
  }
}


ros::Subscriber<std_msgs::String> sub("keyCode", &reciveCallback);

void clearLine(int line){
  lcd.setCursor(0, line);
  lcd.print("                ");
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  nh.initNode();
  nh.subscribe(sub);
  
  lcd.setCursor(x, y);
  lcd.print("O");
  
}

void writeO() {
      clearLine(0);
      clearLine(1);
      
      lcd.setCursor(x, y);
      lcd.print("O");
}

void writeX() {
      clearLine(0);
      clearLine(1);
      
      lcd.setCursor(x, y);
      lcd.print("X");
}

void loop() {
  nh.spinOnce();
}
