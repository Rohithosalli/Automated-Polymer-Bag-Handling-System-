#pragma once
#include <ESP32Servo.h>
#include <BluetoothSerial.h>

// Pin definitions
#define RELAY_PIN 32
#define SERVO_PIN 33
#define STEP_PIN_X 27
#define DIR_PIN_X 14
#define ENABLE_PIN_X 13
#define STEP_PIN_Y 25
#define DIR_PIN_Y 26
#define ENABLE_PIN_Y 12

extern Servo myServo;
extern BluetoothSerial SerialBT;

void initializePins();
void initializeSerial();
void initializeBluetooth();
void printStartupMessage();
