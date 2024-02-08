#include <Stepper.h>  // Include the header file


// change this to the number of steps on your motor

<<<<<<< Updated upstream
#define STEPS 64
=======
#define STEPS 2038
>>>>>>> Stashed changes


// create an instance of the stepper class using the steps and pins

Stepper stepper(STEPS, 8, 10, 9, 11);


int P_c_val = 0;

int pot_val = 0;


void setup() {

  Serial.begin(9600);

<<<<<<< Updated upstream
  stepper.setSpeed(300);
=======
>>>>>>> Stashed changes
}


void loop() {


  pot_val = map(analogRead(A0), 0, 1024, 0, 500);

<<<<<<< Updated upstream
  if (pot_val > P_c_val)

    stepper.step(32);

  if (pot_val < P_c_val)

    stepper.step(-32);


=======
  if (pot_val > P_c_val) {
    stepper.setSpeed(20);
    stepper.step(5);
  }
  if (pot_val < P_c_val) {
    stepper.setSpeed(20);
    stepper.step(-20);
  }
>>>>>>> Stashed changes
  P_c_val = pot_val;

  Serial.print("Pval: ");
  Serial.println(P_c_val);  //for debugging
  delay(300);
}
