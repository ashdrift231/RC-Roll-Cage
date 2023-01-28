#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_TSL2561_U.h>
#include <Adafruit_BME280.h>

// Temperature sensor pins
const int tempSensorPin = A0;
const int fanPin = 12;
const int relayPin = 13;
const int tempThreshold = 50;  // Temperature threshold for turning on LED

// Smoke sensor pins
const int smokeSensorPin = 2;
const int smokeLedPin = 4;

// Proximity sensor pins
const int proximitySensorPin = 3;
const int proximityLedPin = 5;

// Initialize temperature sensor
Adafruit_BME280 tempSensor;

void setup() {
  // Start serial communication
  Serial.begin(9600);

  // Initialize temperature sensor
  if (!tempSensor.begin(0x76)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }

  // Configure pins
  pinMode(tempSensorPin, INPUT);
  pinMode(smokeSensorPin, INPUT);
  pinMode(proximitySensorPin, INPUT);
  pinMode(tempLedPin, OUTPUT);
  pinMode(smokeLedPin, OUTPUT);
  pinMode(proximityLedPin, OUTPUT);
  pinMode(fanPin, OUTPUT);
  pinMode(relayPin, OUTPUT);

  // Set initial state for fan and relay
  digitalWrite(fanPin, LOW);
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read temperature sensor data
  int tempData = analogRead(tempSensorPin);
  float temperature = (tempData / 1024.0) * 5000;  // Convert to Celsius
  if (temperature > tempThreshold) {
    digitalWrite(tempLedPin, HIGH);
    digitalWrite(relayPin, HIGH);
  } else {
    digitalWrite(tempLedPin, LOW);
    digitalWrite(relayPin, LOW);
  }

  // Read smoke sensor data
  int smokeData = digitalRead(smokeSensorPin);
  if (smokeData == HIGH) {
    digitalWrite(smokeLedPin, HIGH);
    digitalWrite(fanPin, HIGH);
  } else {
    digitalWrite(smokeLedPin, LOW);
    digitalWrite(fanPin, LOW);
  }

  // Read proximity sensor data
  int proximityData = digitalRead(proximitySensorPin);
  if (proximityData == HIGH) {
    digitalWrite(proximityLedPin, HIGH);
  } else {
    digitalWrite(proximityLedPin, LOW);
  }

  delay(1000);
}
