#include <Servo.h>

Servo myservo;

int ldr1 = A0;     // input pin for first sensor
int ldr2 = A1;     // input pin for second sensor
int val1;          // variable for first sensor value
int val2;          // variable for second sensor value
int thresh = 600;  // threshold LDR
int pos = 90;      // initial position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);
  myservo.write(pos);  // write initial position
}

void loop() {
  val1 = analogRead(ldr1);
  val2 = analogRead(ldr2);
  Serial.print("LDR 1: ");
  Serial.print(val1);
  Serial.print(", ");
  Serial.print("LDR 2: ");
  Serial.println(val2);

  if (val1 > thresh) {  // if light intensity increases on LDR 1
    myservo.write(0);   // move servo to 0 degree position
    delay(300);
  } else if (val2 > thresh) {  // if light intensity increases on LDR 2
    myservo.write(180);        // move servo to 180 degree position
    delay(300);
  } else {               // if light intensity is below threshold on both LDRs
    myservo.write(pos);  // maintain current position
    delay(300);
  }
}