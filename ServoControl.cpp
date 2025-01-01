#include "ServoControl.h"
#include <ESP32Servo.h>
#include "ArduinoConfig.h"

void moveServo(int angle) {
  myServo.write(angle);
  Serial.println("Servo moved to " + String(angle) + " degrees");
  SerialBT.println("Servo moved to " + String(angle) + " degrees");
}
