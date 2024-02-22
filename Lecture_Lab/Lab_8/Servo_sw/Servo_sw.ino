#include <Servo.h>

Servo myservo;

const int switchLeft = 2;   
const int switchRight = 3;  

int angle = 90;  

void setup() {
  myservo.attach(9);  
  pinMode(switchLeft, INPUT_PULLUP);
  pinMode(switchRight, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(switchLeft) == LOW) {
    angle -= 45;
    if (angle < 0) {
      angle = 0;
    }
    myservo.write(angle);
    delay(200);  
  }

  if (digitalRead(switchRight) == LOW) {
    angle += 45;
    if (angle > 180) {
      angle = 180;
    }
    myservo.write(angle);
    delay(200);  
  }

}
