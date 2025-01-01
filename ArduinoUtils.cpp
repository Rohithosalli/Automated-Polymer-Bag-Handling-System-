#include "ArduinoUtils.h"
#include "MotorControl.h"
#include "ServoControl.h"
#include "ArduinoConfig.h"
#include <Arduino.h>

void handleCommand(String command) {
  command.trim(); // Remove any trailing newline characters

  if (command == "2") {
    moveServo(180);
  } else if (command == "8") {
    moveServo(0);
  } else if (command == "4") {
    controlRelay(HIGH);
  } else if (command == "6") {
    controlRelay(LOW);
  } else if (command.startsWith("x:")) {
    long steps = command.substring(2).toInt();
    Serial.println("Moving Motor X " + String(steps) + " steps");
    SerialBT.println("Moving Motor X " + String(steps) + " steps");
    moveStepperX(steps);
  } else if (command.startsWith("y:")) {
    long steps = command.substring(2).toInt();
    Serial.println("Moving Motor Y " + String(steps) + " steps");
    SerialBT.println("Moving Motor Y " + String(steps) + " steps");
    moveStepperY(steps);
  } else {
    Serial.println("Invalid command. Use: 2, 8, 6, 4, x:<steps>, y:<steps>");
    SerialBT.println("Invalid command. Use: 2, 8, 6, 4, x:<steps>, y:<steps>");
  }
}

void checkSerialInput() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    handleCommand(command);
  }
}

void checkBluetoothInput() {
  if (SerialBT.available()) {
    String command = SerialBT.readStringUntil('\n');
    handleCommand(command);
  }
}
