#include <Stepper.h>

const int stepsPerRevolution = 2038;
Stepper myStepper = Stepper(stepsPerRevolution, 8, 9, 10, 11);

int P_c_val = 0;
int pot_val = 0;

void setup() {
    Serial.begin(9600);
    myStepper.setSpeed(20);
}

void loop() {
    pot_val = map(analogRead(A0), 0, 1024, 0, 500);

    if ((pot_val - P_c_val) > 5) {
        // Rotate CW slowly at 5 RPM
        myStepper.step(stepsPerRevolution / 2);
    } else if ((P_c_val - pot_val) > 5) {
        // Rotate CCW slowly at 5 RPM
        myStepper.step(-stepsPerRevolution / 2);
    }

    P_c_val = pot_val;

    Serial.print("POT: ");
    Serial.println(pot_val);

    delay(100); // You can adjust this delay based on your requirements
}
