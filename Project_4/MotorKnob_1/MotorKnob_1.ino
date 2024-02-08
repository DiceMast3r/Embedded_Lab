#include <Stepper.h>

const int STEPS = 2038;

Stepper stepper(STEPS, 8,9,10,11);

int previous = 0;

void setup() {
  stepper.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  int move = val - previous;

  if (abs(move) > 3) {
    int stepsToMove = (move > 0) ? -STEPS / 4 : STEPS / 4;
    stepper.step(stepsToMove);
    delay(10);
  }

  previous = val;

  Serial.print("Diff Val: ");
  Serial.println(move);
  delay(10);
}
