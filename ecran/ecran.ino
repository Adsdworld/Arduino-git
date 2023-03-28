#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F for a 16 chars and 2 line display


void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      
}

void loop() {
  lcd.setCursor(6,0);   
  lcd.print("YOU");
  lcd.setCursor(4,1);   
  lcd.print("MADE IT");
  lcd.display();
}