#include <Arduino.h>
#include <Wire.h>

// Variables
int LED = 13;
int x = 0;

void receiveEvent(int bytes){
  x = Wire.read();
}

void setup() {
  // Define the led pin as output
  pinMode(LED,OUTPUT);
  // Start the I2C Bus as slave on address 9
  Wire.begin (9);
  // Attach a function to trigger when something is receiving
  Wire.onReceive(receiveEvent);
}

void loop() {
  // If value received is 0 blink LED for 200 ms 
  if(x == 0){
    digitalWrite(LED,HIGH);
    delay(200);
    digitalWrite(LED,LOW);
    delay(200);
  }
  // If value received is 3 blink LED for 400 ms
}