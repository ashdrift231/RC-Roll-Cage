#include <Arduino.h> 
const int CH_2_PIN = 11;
int RPWM=5;
int LPWM=6;
// timer 0
int L_EN=7;
int R_EN=8;
const int deadzone = 80;
int test = 13;
void setup() {
  // E18-D80NK Obstacle Sensor Code by Robojax.com 2018022
  Serial.begin(9600);// setup Serial Monitor to display information
 pinMode(test,OUTPUT);
 
}
int pulseToPWM(int pulse) {
  
  // If we're receiving numbers, convert them to motor PWM
  if ( pulse > 1000 ) {
    pulse = map(pulse, 1000, 2000, -500, 500);
    pulse = constrain(pulse, -1023, 1023);
  } else {
    pulse = 0;
  }

  // Anything in deadzone should stop the motor
  if ( abs(pulse) <= deadzone ) {
    pulse = 0;
  }
  return pulse;
}
void breaking(int SIGNAL){
  if(SIGNAL< -(deadzone)){
    digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
  delay(1000);
    digitalWrite(RPWM,HIGH);
    delay(2000);
  digitalWrite(test,HIGH);
  // if(digitalRead(proximity2) == 0){
     digitalWrite(R_EN,LOW);
    digitalWrite(L_EN,LOW);// halt
    analogWrite(RPWM, 0);
      
    }

   if(SIGNAL>(deadzone)){
     digitalWrite(R_EN,HIGH);
  digitalWrite(L_EN,HIGH);
  delay(1000);
    digitalWrite(LPWM,HIGH);
    delay(2000);
  digitalWrite(test,LOW);
  // if(digitalRead(proximity2) == 0){
     digitalWrite(R_EN,LOW);
    digitalWrite(L_EN,LOW);// halt
    analogWrite(LPWM, 0);
      }
  }
void loop() {
  breaking(pulseToPWM(pulseIn(CH_2_PIN, HIGH, 25000)));
}
