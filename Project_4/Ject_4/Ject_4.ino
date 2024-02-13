#include <Stepper.h>  // Include the header file


// change this to the number of steps on your motor

#define STEPS 2048


// create an instance of the stepper class using the steps and pins

Stepper stepper(STEPS, 8, 9, 10, 11);


int P_c_val = 0;

int pot_val = 0;


void setup() {

  Serial.begin(9600);
  stepper.setSpeed(300);
}


void loop() {


  pot_val = map(analogRead(A0), 0, 1024, 0, 500);

  if (pot_val > P_c_val) {
    stepper.step(32);
  }

  if (pot_val < P_c_val) {
    stepper.step(-32);
  }

  P_c_val = pot_val;

  Serial.print("Pval: ");
  Serial.println(P_c_val);  //for debugging
  delay(300);
}
