#define LED 9
#define POT 5

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(POT);
  analogWrite(LED, adc / 4);
}
