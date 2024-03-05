#include <Servo.h>

Servo myservo;

const int ldr_pin = A0;
constexpr int th_value = 500;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(ldr_pin, INPUT);
  myservo.write(90);
}

void loop() {
  int val_ldr = analogRead(ldr_pin);

  Serial.print("LDR: ");
  Serial.println(val_ldr);

  if (val_ldr >= th_value) {
    myservo.write(0);
    Serial.println("Left 90");
  } else if (val_ldr <= (th_value - 300)) {
    myservo.write(180);
    Serial.println("Right 90");
  } else {
    myservo.write(90);
    Serial.println("Middle");
  }

  delay(300); 
}
