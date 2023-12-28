int ldr = A0;
int input_val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  input_val = analogRead(ldr);
  Serial.print("LDR Val: ");
  Serial.println(input_val);
  delay(1000);
}
