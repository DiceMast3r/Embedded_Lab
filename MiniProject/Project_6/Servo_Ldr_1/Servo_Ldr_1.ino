#include <Servo.h>

Servo myservo;

const int ldr_pin = A0;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(ldr_pin, INPUT);
}

void loop() {
  int val_ldr = analogRead(ldr_pin);
  int servo_angle = map(val_ldr, 600, 1000, 0, 180);
  
  Serial.print("LDR: ");
  Serial.println(val_ldr);
  Serial.print("Servo angle: ");
  Serial.println(servo_angle);

  if (servo_angle >= 0) {
    myservo.write(servo_angle);
    delay(45);
  } else if  (servo_angle < 0) {
    myservo.write(0);
    delay(45);
  }

}
