int LED1 = 12;
int LED2 = 13;
int LED3 = 9;

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  attachInterrupt(0, OFF, RISING);
  attachInterrupt(1, ON, RISING);
  // 1 = Interrupt for Arduino Uno at pin 3
  // OFF = Own function
  // RISING = Case interrupt
}
void loop() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, HIGH);
  delay(50);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, LOW);
  delay(50);
}
void ON() {
  digitalWrite(LED3, HIGH);
}

void OFF() {
  digitalWrite(LED3, LOW);
}