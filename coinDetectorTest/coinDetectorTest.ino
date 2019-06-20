#include <Wire.h>

int coinValue = 0;
int coinInputPin = A0;
void setup(){
  pinMode(coinInputPin, INPUT);
  Serial.begin(9600);
}
void loop(){
  coinValue = analogRead(coinInputPin);
  Serial.println(coinValue);
  delay(1000);
}
