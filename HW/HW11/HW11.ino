#include <Wire.h>

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd1(0x39, 16, 2);
LiquidCrystal_I2C lcd2(0x3F, 16, 2);
LiquidCrystal_I2C lcd3(0x38, 16, 2);

#include <Keypad_I2C.h>
#include <Keypad.h>
#define I2CADDR 0x23
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  { '7', '8', '9', '/' },
  { '4', '5', '6,' '*' },
  { '1', '2', '3', '-' },
  { 'C', '0', '=', '+' }
};

byte rowPins[ROWS] = { 0, 1, 2, 3 };
byte colPins[COLS] = { 4, 5, 6, 7 };

Keypad_I2C keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS, I2CADDR, PCF8574);

#include "SHT2x.h"
SHT2x sht;

#include "RTCDS1307.h"
RTCDS1307 rtc(0x68);
uint8_t year, month, weekday, day, hour, minute, second;
bool period = 0;
String m[12] = { "January", "February", "March", "April", "May", "June",
                 "July", "August", "September", "October", "November", "December" };
String w[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
                "Friday", "Saturday" };

#define EN1 11
#define IN1 12
#define IN2 13

int timer[2];
int i, n = 0;
int low = 8;
int high = 18;
int set;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}
