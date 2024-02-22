#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);  // Adjust the I2C address if needed

uint8_t HeartChar[] = { 0x00, 0x00, 0x0a, 0x15, 0x11, 0x0a, 0x04, 0x00 };
uint8_t SpeakerChar[] = { 0x01, 0x03, 0x07, 0x1f, 0x1f, 0x07, 0x03, 0x01 };
uint8_t SmileyFaceChar[] = { 0x00, 0x00, 0x0a, 0x00, 0x1f, 0x11, 0x0e, 0x00 };
uint8_t BellChar[] = { 0x04, 0x0e, 0x0a, 0x0a, 0x0a, 0x1f, 0x00, 0x04 };
uint8_t Battery1Char[] = { 0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x11, 0x1f };
uint8_t Battery2Char[] = { 0x0e, 0x1b, 0x11, 0x11, 0x11, 0x11, 0x1f, 0x1f };
uint8_t Battery3Char[] = { 0x0e, 0x1b, 0x11, 0x11, 0x11, 0x1f, 0x1f, 0x1f };
uint8_t Battery4Char[] = { 0x0e, 0x1b, 0x11, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f };

const int voltagePin = A1;
const int currentPin = A0;
const int frequencyPin = 2;
const int sw1 = 3;
const int inputPin = 2;
int mode = 0;

volatile unsigned long pulseCount = 0;
unsigned long previousMillis = 0;
unsigned long interval = 0.000160;
unsigned long displayInterval = 500;  // Interval to update the display (in milliseconds)

// Function declarations
void countPulse();
void updateDisplay();
void showName();
void resetMode();

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(0, HeartChar);
  lcd.createChar(1, SpeakerChar);
  lcd.createChar(2, SmileyFaceChar);
  lcd.createChar(3, BellChar);
  lcd.createChar(4, Battery1Char);
  lcd.createChar(5, Battery2Char);
  lcd.createChar(6, Battery3Char);
  lcd.createChar(7, Battery4Char);

  lcd.setCursor(4, 0);
  lcd.print("BOOTING!");
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(2, 1);
  lcd.write(byte(1));
  lcd.setCursor(4, 1);
  lcd.write(byte(2));
  lcd.setCursor(6, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(4));
  lcd.setCursor(10, 1);
  lcd.write(byte(5));
  lcd.setCursor(12, 1);
  lcd.write(byte(6));
  lcd.setCursor(14, 1);
  lcd.write(byte(7));

  delay(400);
  lcd.clear();

  pinMode(voltagePin, INPUT);
  pinMode(currentPin, INPUT);
  pinMode(frequencyPin, INPUT_PULLUP);
  pinMode(sw1, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(frequencyPin), countPulse, FALLING);

  Serial.begin(9600);
}

void loop() {
  updateDisplay();  // Update the display in every iteration

  if (digitalRead(sw1) == LOW) {
    mode += 1;   // mode change
    delay(200);  // Debounce delay
  }

  switch (mode) {
    case 0:
      measureVoltage();
      break;
    case 1:
      measureCurrent();
      break;
    case 2:
      measureFrequency();
      break;
    case 3:
      showName();
      break;
    case 4:
      resetMode();
      break;
  }
}

void measureVoltage() {
  int voltageValue = analogRead(voltagePin);
  float voltageOut = voltageValue * (5.0 / 1023.0);  // Assuming 5V Arduino
  float voltageIn = voltageOut * 6.0;

  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Voltage:");
  lcd.print(voltageIn, 2);  // Display two decimal places
  lcd.print("V");
  lcd.setCursor(6, 1);
  lcd.write(byte(0));
  lcd.setCursor(8, 1);
  lcd.write(byte(1));
  lcd.setCursor(10, 1);
  lcd.write(byte(2));
  delay(100);
}

void measureCurrent() {
  float current_in = analogRead(currentPin);
  float current = current_in / 1000.0;
  lcd.clear();
  lcd.setCursor(1, 0);
  lcd.print("Current:");
  lcd.print(current, 2);
  lcd.print("A");
  lcd.setCursor(6, 1);
  lcd.write(byte(3));
  lcd.setCursor(8, 1);
  lcd.write(byte(5));
  lcd.setCursor(10, 1);
  lcd.write(byte(6));
  delay(100);
}

void measureFrequency() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= displayInterval) {
    unsigned long currentTime = currentMillis - previousMillis;
    float frequency = pulseCount / (currentTime / 1000.0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Frequency:");
    lcd.print((int)frequency);
    lcd.print("Hz");

    // Ensure the pulse counting mechanism can handle higher frequencies
    unsigned long newInterval = max(currentTime, interval);
    unsigned long totalTime = newInterval;
    unsigned long onTime = pulseCount;
    float dutyCycle = (float)onTime / totalTime * 100.0;
    lcd.setCursor(0, 1);
    lcd.print("Duty Cycle: ");
    lcd.print(dutyCycle, 2);
    lcd.print("%");
    pulseCount = 0;
    previousMillis = currentMillis;
  }
}

void countPulse() {
  pulseCount++;
}

void showName() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Thongchai");
  lcd.setCursor(6, 1);
  lcd.write(byte(0));
  lcd.setCursor(8, 1);
  lcd.write(byte(2));
  lcd.setCursor(10, 1);
  lcd.write(byte(7));
  delay(200);
}

void resetMode() {
  mode = 0;
}

void updateDisplay() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= displayInterval) {
    lcd.clear();
    switch (mode) {
      case 0:
        measureVoltage();
        break;
      case 1:
        measureCurrent();
        break;
      case 2:
        measureFrequency();
        break;
      case 3:
        showName();
        break;
      case 4:
        resetMode();
        break;
    }
  }
}
