#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x3F, 16, 2);  //0x27 for PCF8574 and 0x3F for PCF8574A
LiquidCrystal_I2C lcd2(0x3E, 16, 2);  //0x26 for PCF8574 and 0x3E for PCF8574A

int addr[128];
int arr[128];
int addr_count = 0;

void setup() {
  byte count = 0;
  Wire.begin();
  for (byte i = 8; i < 120; i++)  // Loop ค้นหา Address
  {
    Wire.beginTransmission(i);
    if (Wire.endTransmission() == 0) {
      addr[i] = i;
      count++;
      delay(1);
    }
  }
  for (int a = 0; a < 128; a++) {
    if (addr[a] != 0) {
      arr[addr_count] = addr[a];
      addr_count++;
    }
  }
  lcd1.init();
  lcd1.backlight();
  lcd1.setCursor(2, 0);
  lcd1.print("I2C SCANNER");
  lcd1.setCursor(1, 1);
  lcd1.print("Found ");
  lcd1.setCursor(7, 1);
  lcd1.print(count, DEC);
  lcd1.print(" Devices");
  lcd2.init();
  lcd2.backlight();
  lcd2.setCursor(0, 0);
  lcd2.print("0x");
  lcd2.print(arr[0], HEX);
  lcd2.print(",");
  lcd2.setCursor(6, 0);
  lcd2.print("0x");
  lcd2.print(arr[1], HEX);
  lcd2.print(",");
  lcd2.setCursor(12, 0);
  lcd2.print("0x");
  lcd2.print(arr[2], HEX);
  lcd2.setCursor(0, 1);
  lcd2.print("0x");
  lcd2.print(arr[3], HEX);
  lcd2.print(",");
  lcd2.setCursor(6, 1);
  lcd2.print("0x");
  lcd2.print(arr[4], HEX);
  lcd2.print(",");
  lcd2.setCursor(12, 1);
  lcd2.print("0x");
  lcd2.print(arr[5], HEX);

}

void loop() {}