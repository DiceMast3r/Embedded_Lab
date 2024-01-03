#define LED1 9
#define LED2 10
#define POT 5

void setup() {
  // put your setup code here, to run once:
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc = analogRead(POT);
  Serial.print("Analog read value: ");
  Serial.print(adc);
  adc = map(adc,0,1023,0,255);
  Serial.print("map value to: ");
  Serial.println(adc);
  analogWrite(LED1, adc);
  analogWrite(LED2, 255 - adc);
  delay(500);
}
