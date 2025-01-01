#include "ArduinoConfig.h"

Servo myServo;
BluetoothSerial SerialBT;

void initializePins() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Ensure the relay is initially off

  myServo.attach(SERVO_PIN);

  pinMode(STEP_PIN_X, OUTPUT);
  pinMode(DIR_PIN_X, OUTPUT);
  pinMode(ENABLE_PIN_X, OUTPUT);

  pinMode(STEP_PIN_Y, OUTPUT);
  pinMode(DIR_PIN_Y, OUTPUT);
  pinMode(ENABLE_PIN_Y, OUTPUT);

  digitalWrite(ENABLE_PIN_X, LOW);
  digitalWrite(ENABLE_PIN_Y, LOW);
}

void initializeSerial() {
  Serial.begin(115200);
}

void initializeBluetooth() {
  SerialBT.begin("ESP32_BT");
}

void printStartupMessage() {
  Serial.println("The device started, now you can pair it with Bluetooth!");
  Serial.println("Enter command:");
  Serial.println("Servo motor: 2 for 180 degrees, 8 for 0 degrees");
  Serial.println("Relay: 6 to turn on, 4 to turn off");
  Serial.println("Stepper motor X: x:<number_of_steps>");
  Serial.println("Stepper motor Y: y:<number_of_steps>");
}
