#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define the pins used by the nrf24l01 transceiver
#define CE_PIN 9
#define CSN_PIN 10

// Define the touch sensor pin
#define TOUCH_SENSOR_PIN 2

// Create an instance of the RF24 class
RF24 radio(CE_PIN, CSN_PIN);

// The address to send the message to
byte addresses[][6] = {"1Node"};

void setup() {
  // Start the serial communication
  Serial.begin(9600);
  // Start the touch sensor as input
  pinMode(TOUCH_SENSOR_PIN, INPUT);

  // Initialize the radio and set the channel
  radio.begin();
  radio.setChannel(120);
  // Set the payload size to be 1 byte
  radio.setPayloadSize(1);
  // Open a writing pipe to the address
  radio.openWritingPipe(addresses[0]);
}

void loop() {
  // Check if the touch sensor is pressed
  if (digitalRead(TOUCH_SENSOR_PIN) == HIGH) {
    // If it is, send the message "Touch"
    char message[] = "Touch";
    radio.write(message, sizeof(message));
    // Wait for a moment to prevent multiple messages
    delay(100);
  }
}
