#define EN1 11
#define EN2 10
#define IN1 12
#define IN2 13
#define IN3 8
#define IN4 9

void AllStop(void);

void setup() {
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  AllStop();
}

void loop() {
  analogWrite(EN1, 63);   // 50% duty cycle for motor 1
  analogWrite(EN2, 128);  // 100% duty cycle for motor 2

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(3000);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);

  AllStop();

  analogWrite(EN1, 128);  // 50% duty cycle for motor 1
  analogWrite(EN2, 255);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(3000);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);

  AllStop();
}

void AllStop(void) {
  analogWrite(EN1, 0);  // Stop motor 1
  analogWrite(EN2, 0);  // Stop motor 2
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  delay(250);
}
