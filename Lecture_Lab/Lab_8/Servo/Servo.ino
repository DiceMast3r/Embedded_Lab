#include <Servo.h>
#define pot 5
Servo myservo;  // create servo object to control a servo
void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}
void loop() {
  int val = analogRead(pot);  // reads the value of the potentiometer
  Serial.print("POT received: ");
  Serial.println(val, DEC);
    val = map(val, 0, 1023, 0, 180);  // scale it to use it with the servo
  Serial.print("After mapI");
  Serial.println(val, DEC);
  myservo.write(val);  // sets the servo position
  delay(15);           // waits for the servo to get there
}