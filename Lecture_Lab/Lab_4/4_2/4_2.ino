int val;
int tempPin = A5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(tempPin);
  float mv = (val / 1024.0) * 5000;
  float cel = mv / 10;

  Serial.print("TEMP = ");
  Serial.print(cel);
  Serial.print(" *C");
  Serial.println();
  delay(100);
}
