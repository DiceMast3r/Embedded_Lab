const int voltagePin = A1;
const int currentPin = A0;
const int frequencyPin = 2;
const int sw1 = 3;
int mode = 0;

volatile unsigned long pulseCount = 0;
unsigned long previousMillis = 0;
unsigned long interval = 500;
int ontime, offtime, duty;
float freq, period;

void setup()
{
  pinMode(voltagePin, INPUT);
  pinMode(currentPin, INPUT);
  pinMode(frequencyPin, INPUT);
  pinMode(sw1, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(sw1) == LOW)
  {
    mode += 1; // mode change
    delay(200); // Debounce delay
  }

  switch (mode)
  {
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

void measureVoltage()
{
  int voltageValue = analogRead(voltagePin);
  float voltageOut = voltageValue * (5.0 / 1023.0); // Assuming 5V Arduino
  float voltageIn = voltageOut * 6.0;

  Serial.print("Voltage: ");
  Serial.print(voltageIn, 2); // Display two decimal places
  Serial.println(" V");
  delay(100);
}

void measureCurrent() {
  // Calibration parameters
  float offsetVoltage = 2.5;   // Offset voltage when no current is flowing
  float sensitivity = 0.185;  // Sensitivity, in volts per ampere
  float calibrationFactor = 0.925;  // Calibration factor to adjust the reading

  // Read the raw ADC value
  int currentRawValue = analogRead(currentPin);

  // Map the raw ADC value to voltage (0V to 5V)
  float voltage = currentRawValue * (5.0 / 1023.0);

  // Subtract the offset voltage (2.5V when 0A)
  voltage -= offsetVoltage;

  // Convert voltage to current based on the sensitivity
  float current = (voltage / sensitivity) * calibrationFactor;

  Serial.print("Current: ");
  Serial.print(current, 2);  // Display current with two decimal places
  Serial.println(" A");
  delay(100);
}


void measureFrequency()
{
  unsigned long onTime = pulseIn(frequencyPin, HIGH);
  unsigned long offTime = pulseIn(frequencyPin, LOW);
  unsigned long period = onTime + offTime;

  float frequency = 0.0;
  float dutyCycle = 0.0;

  if (period > 0)
  {
    frequency = 1000000.0 / period;
    dutyCycle = (onTime / (float)period) * 100.0;
  }

  Serial.print("Frequency: ");
  Serial.print((int)frequency);
  Serial.println(" Hz");

  if (period > 0)
  {
    Serial.print("Duty Cycle: ");
    Serial.print(dutyCycle, 2);
    Serial.println(" %");
  }

  delay(200);
}

void showName()
{
  Serial.println("65010386 Thongchai");
  delay(200);
}

void resetMode()
{
  mode = 0;
}
