#define TRIGGER_PIN 9 // digital pin D9
#define ECHO_PIN 8 // digital pin D8
#define buzzer 7
unsigned long distance, duration;

void setup() {
  Serial.begin(9600);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  digitalWrite(TRIGGER_PIN, LOW); // Get Start
  delayMicroseconds(2); // stable the line
  digitalWrite(TRIGGER_PIN, HIGH); // sending 10 us pulse
  delayMicroseconds(10); // delay
  digitalWrite(TRIGGER_PIN, LOW); // waiting to receive signals
  duration = pulseIn(ECHO_PIN, HIGH); // calculating time
  distance = (duration / 2) / 29;
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance <= 20) {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
  } else if (distance <= 15) {
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(buzzer, LOW);
  }
  delay(200);
}
