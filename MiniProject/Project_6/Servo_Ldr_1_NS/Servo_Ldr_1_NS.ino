#include <Servo.h>

typedef struct {
  int max;
  int index;
} MaxResult;

Servo myservo;

const int ldr_pin = A0;
constexpr int th_value = 500;
int val[181];

int prevMaxIndex = 90;  // Assume starting position is at 90 degrees
int minLightChange = 50; // Minimum change in light to trigger servo movement

void setup() {
  myservo.attach(9);
  pinMode(ldr_pin, INPUT);
  myservo.write(90);
}

MaxResult findMax(int arr[], int size) {
  MaxResult result;

  if (size <= 0) {
    // Handle the case of an empty array or invalid size
    result.max = -1;
    result.index = -1;
    return result;
  }

  result.max = arr[0];  // Assume the first element is the maximum
  result.index = 0;

  for (int i = 1; i < size; ++i) {
    if (arr[i] > result.max) {
      result.max = arr[i];  // Update the maximum if a larger element is found
      result.index = i;     // Update the index of the maximum
    }
  }

  return result;
}

void loop() {
  for (int a = 0; a < 181; a++) {
    myservo.write(a);
    delay(15); // Delay to allow the servo to reach the position
    val[a] = analogRead(ldr_pin);
  }

  int size = sizeof(val) / sizeof(val[0]);
  MaxResult maxInfo = findMax(val, size);
  myservo.write(maxInfo.index);

  // Check if the difference between the light values is more than the threshold
  int lightDifference = abs(maxInfo.max - val[prevMaxIndex]);
  if (lightDifference > minLightChange) {
    // Update the previous maximum index
    prevMaxIndex = maxInfo.index;

    // Perform any action you want when the light difference is significant
    // For example, print a message
    Serial.println("Significant change in light!");

    // You can add additional actions here, like moving the servo to a specific position
    // or triggering some other behavior.
  }

  delay(500); // Adjust the delay to your needs
}
