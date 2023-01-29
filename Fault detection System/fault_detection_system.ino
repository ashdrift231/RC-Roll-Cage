// This code uses an ACS712 current sensor to detect current levels and control LEDs.
#define cs1 A0 // define the pin for the first current sensor
#define cs2 A1 // define the pin for the second current sensor
#define cs3 A2 // define the pin for the third current sensor
#define cs4 A3 // define the pin for the fourth current sensor
#define cs5 A4 // define the pin for the fifth current sensor

int led[5] = {12, 11, 10, 9,8}; // array to store the pin numbers for the LEDs

float cov = 8.50; // threshold for current level to trigger the first LED
float covt = 2.00; // threshold for current level to trigger the fourth LED

void setup(){
Serial.begin(9600); //initialize serial monitor
for (int i = 1; i < 6; i++)
pinMode(led[i], OUTPUT); // set the LED pins as output
Serial.println("ALL SET");
Serial.println("ACS712 Current Sensors");
}

void loop() {

float current[5]; // array to store the current level values
current[1] = (((0.5 / 1023.0) * analogRead(cs1) - 2.488) / 0.100);
current[2] = (((0.5 / 1023.0) * analogRead(cs2) - 2.488) / 0.100);
current[3] = (((0.5 / 1023.0) * analogRead(cs3) - 2.488) / 0.100);
current[4] = (((0.5 / 1023.0) * analogRead(cs4) - 2.488) / 0.100);
current[5] = (((0.5 / 1023.0) * analogRead(cs5) - 2.488) / 0.100);

int c; // variable to store the current sensor that triggered the LED
if (current[1] < cov) // check if the current level of the first sensor is below the threshold
c = 1;
if (current[2] < cov) // check if the current level of the second sensor is below the threshold
c = 2;
if (current[3] < cov) // check if the current level of the third sensor is below the threshold
c = 3;
if (current[4] < covt) // check if the current level of the fourth sensor is below the threshold
c = 4;

switch (c) {
    case 1:
      Serial.print(current[1], 2); //Print the current measurement of sensor 1 in the serial monitor
      digitalWrite(led[1], HIGH); //Turn on the LED associated with sensor 1
      delay(500); //Wait for half a second
      digitalWrite(led[1], LOW); //Turn off the LED associated with sensor 1
      delay(500); //Wait for half a second

      digitalWrite(led[1], LOW); //Turn off all other LEDs
      digitalWrite(led[2], LOW);
      digitalWrite(led[3], LOW);
      digitalWrite(led[4], LOW);
      break;
    case 2:
      Serial.print(current[2], 2); //Print the current measurement of sensor 2 in the serial monitor
      digitalWrite(led[2], HIGH); //Turn on the LED associated with sensor 2
      delay(500); //Wait for half a second
      digitalWrite(led[2], LOW); //Turn off the LED associated with sensor 2
      delay(500); //Wait for half a second

      digitalWrite(led[1], LOW); //Turn off all other LEDs
      digitalWrite(led[3], LOW);
      digitalWrite(led[4], LOW);
      break;
    case 3:
       Serial.print(current[3], 2); //Print the current measurement of sensor 3 in the serial monitor
      digitalWrite(led[3], HIGH); //Turn on the LED associated with sensor 3
      delay(500); //Wait for half a second
      digitalWrite(led[3], LOW); //Turn off the LED associated with sensor 3
      delay(500); //Wait for half a second

      digitalWrite(led[1], LOW); //Turn off all other LEDs
      digitalWrite(led[2], LOW);
      digitalWrite(led[4], LOW);
      break;
    case 4:
      Serial.print(current[4], 2); //Print the current measurement of sensor 4 in the serial monitor
      digitalWrite(led[4], HIGH); //Turn on the LED associated with sensor 4
      delay(500); //Wait for half a second
      digitalWrite(led[4], LOW); //Turn off the LED associated with sensor 4
      delay(500); //Wait for half a second

      digitalWrite(led[1], LOW); //Turn off all other LEDs
      digitalWrite(led[2], LOW);
      digitalWrite(led[3], LOW);
      break;
  }

}
/*The switch case statement is used to control the flow of the program based on the value of the variable "c".
Depending on the value of "c", different actions will be taken. 
The "case" statements are used to specify the different possible values of "c" and the corresponding actions to be taken.
The "break" statements are used to exit the switch case statement once the corresponding action has been taken.
In this case, it checks the current measurement of each sensor and turns on the corresponding LED if the current measurement is less 
than the defined threshold and print the current measurement in the serial monitor. 
All other LEDs will be turned off.*/
