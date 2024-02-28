#include <Servo.h>

#define pot_L A0
#define pot_R A1
constexpr int threshold = 100;

Servo myservo;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
}

void loop() {
  int val_L = map(analogRead(pot_L), 0, 1023, 0, 180);
  int val_R = map(analogRead(pot_R), 0, 1023, 0, 180);

  Serial.print("Left_val: ");
  Serial.print(val_L);
  Serial.print(", Right_val: ");
  Serial.print(val_R);
  Serial.print(", ");

  if (val_L >= threshold && val_R < val_L) {
    myservo.write(180);
    Serial.println("Right angle: 90");
  } else if (val_L < threshold && val_R < threshold) {
    myservo.write(90);
    Serial.println("In The Middle");
  } else if (val_R >= threshold && val_L < val_R) {
    myservo.write(0);
    Serial.println("Left angle: 90");
  }

  delay(700);
}
