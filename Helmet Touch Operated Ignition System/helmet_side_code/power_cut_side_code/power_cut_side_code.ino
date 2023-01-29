#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const int relayPin = 7; // Pin connected to the relay module
const int cePin = 9;
const int csnPin = 10;

RF24 radio(cePin, csnPin);
const byte address[6] = "00001";

void setup() {
pinMode(relayPin, OUTPUT);
digitalWrite(relayPin, LOW);
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(0, address);
radio.setPALevel(RF24_PA_LOW);
radio.startListening();
}

void loop() {
if (radio.available()) {
char recievedMessage[32];
radio.read(&recievedMessage, 32);
String message = String(recievedMessage);
Serial.println("Message Recieved: " + message);
if (message == "Touch detected") {
digitalWrite(relayPin, HIGH);
delay(1000);
digitalWrite(relayPin, LOW);
Serial.println("Relay Disconnected");
}
}
}
