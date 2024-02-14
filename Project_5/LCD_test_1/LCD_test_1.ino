#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

byte Heart[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000
};


void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.createChar(0, Heart);
  // Print a message to the LCD.

  lcd.setCursor(3, 0);

  lcd.print("Hello");

  lcd.setCursor(9, 0);

  lcd.print("World");
  lcd.setCursor(8, 1);
  lcd.write(byte(0));
}

void loop() {
  // put your main code here, to run repeatedly:
}
