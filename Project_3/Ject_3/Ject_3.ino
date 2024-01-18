int ldr = A0;
int input_val = 0;
int val_1, val_2, val_3, input_avg;
unsigned int LDR_open = 400;
#define relay 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  input_val = analogRead(ldr);
  Serial.print("LDR value: ");
  Serial.println(input_val);
  if (input_val <= LDR_open) {
    digitalWrite(relay, HIGH);
    Serial.println("LIGHT ON!!");
    delay(2500);
  }
  else {
    digitalWrite(relay, LOW);
    Serial.println("LIGHT OFF!!");
    delay(2500);
  }
  delay(350);
}
