int ldr_pin = A0;
int input_val = 0;
unsigned int LDR_open = 400;
#define relay 7

void setup() {
  pinMode(relay, OUTPUT);
}

void loop() {
  input_val = analogRead(ldr_pin);
  if (input_val <= LDR_open) {
    digitalWrite(relay, HIGH);
    delay(1500);
  } else {
    digitalWrite(relay, LOW);
    delay(1500);
  }
  delay(350);
}
