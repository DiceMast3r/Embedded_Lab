#define sw 0

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(sw);
  Serial.print("Value from sw is: ");
  Serial.println(adc);
  delay(100);
}
