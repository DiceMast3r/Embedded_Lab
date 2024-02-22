#define ENB 9
#define IN3 3
#define IN4 2
#define POT A0

void setup() {
  // put your setup code here, to run once:
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  int adc = analogRead(POT);
  analogWrite(ENB, map(adc, 0, 1023, 0, 255));

}
