#include <string.h>
const int red = 8;
const int blue = 9;
const int green = 10;   // how bright the LED is
String state = "0";
int counter = 0;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  //Start serial communication
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() { // Reads the data from the serial port and changes value of the state variable
  counter = 0;
  while(Serial.available() > 0){
    String received = Serial.readStringUntil(':');
    if (counter == 0){
      analogWrite(red, received.toInt()/1.4);
//      Serial.println("red");
    }
    else if(counter == 1){
      analogWrite(green, received.toInt()/1.4);
//      Serial.println("green");
    }
    else if  (counter == 2){
      analogWrite(blue, received.toInt()/1.4);
//      Serial.println("blue");
    }
    if(received != ""){
        Serial.println("Pos");
        Serial.println(received);
        counter ++;
    }
    
//    analogWrite(red, state.toInt()/1.4);
//    analogWrite(red, state.toInt()/1.4);
 }
}
