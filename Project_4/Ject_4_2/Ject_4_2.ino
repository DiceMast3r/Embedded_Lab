int motorPin1 = 8;// Blue   - 28BYJ48 pin 1

int motorPin2 = 9;// Pink   - 28BYJ48 pin 2

int motorPin3 = 10;// Yellow - 28BYJ48 pin 3

int motorPin4 = 11;// Orange - 28BYJ48 pin 4

int motorSpeed = 400;     //variable to set stepper speed

char val = '0';

 

void setup() {

  //declare the motor pins as outputs

  pinMode(motorPin1, OUTPUT);

  pinMode(motorPin2, OUTPUT);

  pinMode(motorPin3, OUTPUT);

  pinMode(motorPin4, OUTPUT);

  Serial.begin(9600);

}

 

void loop(){

 if (Serial.available())

  {

    val = Serial.read();

    Serial.println(val);

  }

  if (val == '1'){

      clockwise();     

  }

    if (val == '2'){

      counterclockwise();    

  }             

    if (val == '0'){

  digitalWrite(motorPin1, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin4, LOW);

  }      

}

 

 

void counterclockwise (){

  // 1

  digitalWrite(motorPin1, HIGH);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin4, LOW);

  delay(motorSpeed);

  // 2

  digitalWrite(motorPin1, HIGH);

  digitalWrite(motorPin2, HIGH);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin4, LOW);

  delay (motorSpeed);

  // 3

  digitalWrite(motorPin1, LOW);

  digitalWrite(motorPin2, HIGH);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin4, LOW);

  delay(motorSpeed);

  // 4

  digitalWrite(motorPin1, LOW);

  digitalWrite(motorPin2, HIGH);

  digitalWrite(motorPin3, HIGH);

  digitalWrite(motorPin4, LOW);

  delay(motorSpeed);

  // 5

  digitalWrite(motorPin1, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin3, HIGH);

  digitalWrite(motorPin4, LOW);

  delay(motorSpeed);

  // 6

  digitalWrite(motorPin1, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin3, HIGH);

  digitalWrite(motorPin4, HIGH);

  delay (motorSpeed);

  // 7

  digitalWrite(motorPin1, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin4, HIGH);

  delay(motorSpeed);

  // 8

  digitalWrite(motorPin1, HIGH);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin4, HIGH);

  delay(motorSpeed);

}

 

void clockwise(){

  // 1

  digitalWrite(motorPin4, HIGH);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin1, LOW);

  delay(motorSpeed);

  // 2

  digitalWrite(motorPin4, HIGH);

  digitalWrite(motorPin3, HIGH);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin1, LOW);

  delay (motorSpeed);

  // 3

  digitalWrite(motorPin4, LOW);

  digitalWrite(motorPin3, HIGH);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin1, LOW);

  delay(motorSpeed);

  // 4

  digitalWrite(motorPin4, LOW);

  digitalWrite(motorPin3, HIGH);

  digitalWrite(motorPin2, HIGH);

  digitalWrite(motorPin1, LOW);

  delay(motorSpeed);

  // 5

  digitalWrite(motorPin4, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin2, HIGH);

  digitalWrite(motorPin1, LOW);

  delay(motorSpeed);

  // 6

  digitalWrite(motorPin4, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin2, HIGH);

  digitalWrite(motorPin1, HIGH);

  delay (motorSpeed);

  // 7

  digitalWrite(motorPin4, LOW);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin1, HIGH);

  delay(motorSpeed);

  // 8

  digitalWrite(motorPin4, HIGH);

  digitalWrite(motorPin3, LOW);

  digitalWrite(motorPin2, LOW);

  digitalWrite(motorPin1, HIGH);

  delay(motorSpeed);

}