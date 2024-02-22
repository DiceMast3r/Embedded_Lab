#define sw 0
#define LED1 11
#define LED2 10
#define LED3 9
#define LED4 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(sw);
  Serial.print("Value from sw is: ");
  Serial.println(adc);
  if (adc == 0) {
    digitalWrite(LED1, HIGH);
  }
  else if (adc == 415) {
    digitalWrite(LED2, HIGH);
  }
  else if (adc == 614) {
    digitalWrite(LED3, HIGH);
  }
  else if (adc == 827) {
    digitalWrite(LED4, HIGH);
  }
  else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }
  delay(100);
}
