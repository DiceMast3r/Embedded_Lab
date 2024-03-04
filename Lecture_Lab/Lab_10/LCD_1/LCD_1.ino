#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x3F, 16, 2);  //0x27 for PCF8574 and 0x3F for PCF8574A
LiquidCrystal_I2C lcd2(0x3E, 16, 2);  //0x26 for PCF8574 and 0x3E for PCF8574A
void setup() {
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(2, 0);
  lcd1.print("Hello, world!");
  lcd1.setCursor(4, 1);
  lcd1.print("LCD 1");
  lcd2.init();
  lcd2.backlight();
  lcd2.setCursor(2, 0);
  lcd2.print("Hello, world!");
  lcd2.setCursor(4, 1);
  lcd2.print("LCD 2");
}
void loop() {
}