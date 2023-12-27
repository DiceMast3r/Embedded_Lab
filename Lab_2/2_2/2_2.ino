#define LED1 2
#define LED2 3
#define SW1 9
#define SW2 10
#define SW3 11
#define SW4 12

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(SW1) == LOW) {
  digitalWrite(LED1, HIGH);
  }
  else if (digitalRead(SW2) == LOW) {
  digitalWrite(LED1, LOW);
  }
  else if (digitalRead(SW3) == LOW) {
  digitalWrite(LED2, HIGH);
  }
  else if (digitalRead(SW4) == LOW) {
  digitalWrite(LED2, LOW);
  }

}
