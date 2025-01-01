#include <ESP32Servo.h>
#include <BluetoothSerial.h>
#include "ArduinoConfig.h"
#include "ArduinoUtils.h"
#include "MotorControl.h"
#include "ServoControl.h"

void setup() {
  initializePins();
  initializeSerial();
  initializeBluetooth();
  printStartupMessage();
}

void loop() {
  checkSerialInput();
  checkBluetoothInput();t
  delay(20); // Short delay to avoid overloading the serial buffer
}
