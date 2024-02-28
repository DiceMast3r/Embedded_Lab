#include <LiquidCrystal.h>
/* The circuit:
* LCD RS pin to digital pin 7
* LCD E pin to digital pin 6
* LCD D4 pin to digital pin 2
* LCD D5 pin to digital pin 3
* LCD D6 pin to digital pin 4
* LCD D7 pin to digital pin 5
* LCD R/W pin to ground
*/
LiquidCrystal lcd(7, 6, 2, 3, 4, 5);  // set up the LCD's connection pins
void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(4, 0);  // set LCD size
  lcd.print("65010386");
}
void loop() {
  lcd.setCursor(4, 2);
  lcd.print("Thongchai");
  lcd.home();
}