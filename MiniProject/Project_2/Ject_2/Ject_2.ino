int thermistorPin = A0;
int V_o;
float logR2, R2, t_K, t_C, t_F;
const float Beta = 3974;
const float roomTemp = 298.15;
const float R_o = 10000;
const float R1 = 10000;
#define ENA 9
#define IN1 3
#define IN2 2
#define LED 8

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  V_o = analogRead(thermistorPin);
  R2 = R1 * (1023.0 / (float)V_o - 1.0);
  logR2 = log(R2);
  t_K =  (Beta * roomTemp) / (Beta + (roomTemp * log(R2 / R_o)));
  t_C = t_K - 273.15;
  t_F = (t_C * 9.0) / 5.0 + 32.0;

  Serial.print("Temperature: ");
  Serial.print(t_C);
  Serial.println("C");
  float speed = map(t_C, 35, 50, 0, 255);
  Serial.print("Speed: ");
  Serial.print((speed / 255) * 100);
  Serial.println("%");
  if (speed >= 35) {
    analogWrite(ENA, (int)speed);
  }
  if (t_C >= 50) {
  digitalWrite(LED, HIGH);
  }
  else {
  digitalWrite(LED, LOW);
  }
  delay(200);
  

}
