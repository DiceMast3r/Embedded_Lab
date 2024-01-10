#define TRIGGER_PIN 9 // digital pin D9
#define ECHO_PIN 8 // digital pin D8

void setup() {
Serial.begin (9600);
pinMode(TRIGGER_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
}

void loop() {
double duration, distance;
digitalWrite(TRIGGER_PIN, LOW); // Get Start
delayMicroseconds(2); // stable the line
digitalWrite(TRIGGER_PIN, HIGH); // sending 10 us pulse
delayMicroseconds(10); // delay
digitalWrite(TRIGGER_PIN, LOW); // waiting to receive signals
duration = pulseIn(ECHO_PIN, HIGH); // calculating time
distance = microsecondsToCentimeters(duration);
Serial.print("Distance = ");
Serial.print(distance);
Serial.println(" cm");
delay(250);
}


long microsecondsToCentimeters(long microseconds) {
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds/2/29;
}