#include <LiquidCrystal.h>
const int rs = 51, e = 50, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int speed = 0;
const int btn1 = 7;
const int btn2 = 6;
const int btn3 = 5;
const int fan = 9;

int state = 0;

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(fan, OUTPUT);
  analogWrite(fan, speed);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Fan ready");
}

void loop() {

  if(digitalRead(btn3) == LOW) {
    if (state != 2) {
      state = 2;
      speed = 255;
      analogWrite(fan, speed);
      lcd.setCursor(0, 0);
      lcd.print("Fan Speed: MAX");
      lcd.setCursor(0, 1);
      lcd.print("[3]   2   1");
    }
    delay(150);
  }


  if(digitalRead(btn2) == LOW) {
    if (state != 1) {
      state = 1;
      speed = 127;
      analogWrite(fan, speed);
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("Fan Speed: MED");
      lcd.setCursor(0, 1);
      lcd.print("3   [2]   1");
    }
    delay(150);
  }


  if(digitalRead(btn1) == LOW) {
    if (state != 0) {
      state = 0;
      speed = 0;
      analogWrite(fan, speed);
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("Fan Speed: OFF");
      lcd.setCursor(0, 1);
      lcd.print("3   2   [1]");
    }
    delay(150);
  }
}
