#define phaseA 4
#define phaseB 5
#define phaseC 6
#define phaseD 7
char PinCon[] = { phaseA, phaseB, phaseC, phaseD };
byte pattern_ccw[] = { 0B1000, 0B0100, 0B0010, 0B0001 };
byte pattern_cw[] = { 0B0001, 0B0010, 0B0100, 0B1000 };
void setup() {
  for (char i = 0; i < 4; i++) {
    pinMode(PinCon[i], OUTPUT);
  }
}
void loop() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < 4; i++) {
      send2port(pattern_ccw[i]);
      delay(280);
    }
  }
  send2port(0B0000);
  while (1)
    ;
}
void send2port(byte data) {
  if (data & 1) {
    digitalWrite(PinCon[0], HIGH);
  } else {
    digitalWrite(PinCon[0], LOW);
  }
  if (data & 2) {
    digitalWrite(PinCon[1], HIGH);
  } else {
    digitalWrite(PinCon[1], LOW);
  }
  if (data & 4) {
    digitalWrite(PinCon[2], HIGH);
  } else {
    digitalWrite(PinCon[2], LOW);
  }
  if (data & 8) {
    digitalWrite(PinCon[3], HIGH);
  } else {
    digitalWrite(PinCon[3], LOW);
  }
}