#include <LiquidCrystal.h>
#include <Keypad.h>


const byte ROWS = 4;  //four rows
const byte COLS = 3;  //three columns
char keys[ROWS][COLS] = {
  { '1', '2', '3' },
  { '4', '5', '6' },
  { '7', '8', '9' },
  { '*', '0', '#' }
};
byte rowPins[ROWS] = { 12, 11, 10, 9 };  //connect to the row pinouts of keypad
byte colPins[COLS] = { 6, 7, 8 };        //connect to the column pinouts of keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


LiquidCrystal lcd(5, 4, 0, 1, 2, 3);  // set up the LCD's connection pins

void setup() {
  lcd.begin(16, 2);
}


void loop() {
  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("Hello World");
    lcd.setCursor(1, 1);
    lcd.print("Key: ");
    lcd.print((char)key);
    lcd.print(",");
    lcd.print(key, DEC);
    lcd.print("d");
    lcd.print(",");
    lcd.print(key,HEX);
    lcd.print("h");
  }
}