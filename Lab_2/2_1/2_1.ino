char LED_pin[] = {2,3,4,5};
void send2port(byte data);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (char i = 0; i < 4; i++) {
  pinMode(LED_pin[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  send2port(0B1000);
  delay(250);
  send2port(0B0100);
  delay(250);
  send2port(0B0010);
  delay(250);
  send2port(0B0001);
  delay(250);
}

void send2port(byte data) {
  if (data & 1) {
  digitalWrite(LED_pin[0], HIGH);
  } else {
  digitalWrite(LED_pin[0], LOW);
  }
  if (data & 2) {
  digitalWrite(LED_pin[1], HIGH);
  } else {
  digitalWrite(LED_pin[1], LOW);
  }
  if (data & 4) {
  digitalWrite(LED_pin[2], HIGH);
  } else {
  digitalWrite(LED_pin[2], LOW);
  }
  if (data & 8) {
  digitalWrite(LED_pin[3], HIGH);
  } else {
  digitalWrite(LED_pin[3], LOW);
  }

}
