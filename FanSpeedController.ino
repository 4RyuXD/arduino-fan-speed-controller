#include <LiquidCrystal.h>
// Include required libraries

const int rs = 51, e = 50, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
// Create variables for LCD pins
LiquidCrystal lcd(rs, e, d4, d5, d6, d7);

int speed = 0;
const int btn1 = 7;
const int btn2 = 6;
const int btn3 = 5;
const int fan = 9;
// Create variables for btns and fan output

int state = 0;
// Create a variable that corresponds to the fan setting, allowing for instantaneous fan speed switching

void setup() {
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(fan, OUTPUT);

  // Set the pin modes of btn pins and fan
  
  analogWrite(fan, speed);
  // Set the speed of the fan to current speed/0
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Fan ready");
  // Initialize LCD Screen
}

void loop() {

  if(digitalRead(btn3) == LOW) {
    // Check whether the button has been pressed
    if (state != 2) {
      // Check whether the fan state is the correct state
      state = 2;
      speed = 255;
      analogWrite(fan, speed);
      lcd.setCursor(0, 0);
      lcd.print("Fan Speed: MAX");
      lcd.setCursor(0, 1);
      lcd.print("[3]   2   1");
      // Print the updated speed to the LCD Screen
    }
    delay(150);
    // Delay for debounce
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
  // Does the same process but for a different button


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
  // Does pretty much the same procces but for a different button, as i said before
}
