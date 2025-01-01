#include "MotorControl.h"
#include <Arduino.h>
#include "ArduinoConfig.h"

void moveStepperX(long steps) {
  if (steps > 0) {
    digitalWrite(DIR_PIN_X, HIGH); // Move forward
  } else {
    digitalWrite(DIR_PIN_X, LOW); // Move backward
    steps = -steps; // Make steps positive
  }

  for (long x = 0; x < steps; x++) {
    digitalWrite(STEP_PIN_X, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN_X, LOW);
    delayMicroseconds(1000);
  }
}

void moveStepperY(long steps) {
  if (steps > 0) {
    digitalWrite(DIR_PIN_Y, HIGH); // Move forward
  } else {
    digitalWrite(DIR_PIN_Y, LOW); // Move backward
    steps = -steps; // Make steps positive
  }

  for (long y = 0; y < steps; y++) {
    digitalWrite(STEP_PIN_Y, HIGH);
    delayMicroseconds(1000);
    digitalWrite(STEP_PIN_Y, LOW);
    delayMicroseconds(1000);
  }
}

void controlRelay(int state) {
  digitalWrite(RELAY_PIN, state);
}
