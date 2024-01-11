int ldr = A0;
int input_val = 0;
#define relay 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  input_val = analogRead(ldr);
  Serial.print("LDR Val: ");
  Serial.println(input_val);
  if (input_val <= 100) {
    digitalWrite(relay, HIGH);
  }
  else {
    digitalWrite(relay, LOW);
  }
  delay(500);
}
