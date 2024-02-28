#include <Servo.h>

Servo myservo;

const int ldr_L = A0;
const int ldr_R = A1;
constexpr int th_value = 600;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(ldr_L, INPUT);
  pinMode(ldr_R, INPUT);
  myservo.write(90);
}

void loop() {
  int val_ldr_L = analogRead(ldr_L);
  int val_ldr_R = analogRead(ldr_R);

  Serial.print("LDR 1: ");
  Serial.print(val_ldr_L);
  Serial.print(", ");
  Serial.print("LDR 2: ");
  Serial.print(val_ldr_R);
  Serial.print(", ");

  if ((val_ldr_L > th_value) && (val_ldr_R < val_ldr_L)) {
    myservo.write(0);
    Serial.println("Left");
  } else if ((val_ldr_R > th_value) && (val_ldr_L < val_ldr_R)) {
    myservo.write(180);
    Serial.println("Right");
  } else {
    myservo.write(90);
    Serial.println("Middle");
  }

  delay(300); 
}
