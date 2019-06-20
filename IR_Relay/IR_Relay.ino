#include <RelayModule.h>
#include <IRremote.h>

int relay = 3; // choose the pin for the RELAY
int led = 13;
int IR_Recv = 2;

IRrecv irrecv(IR_Recv);
decode_results results;
int val = 0; // variable for reading the pin status



void setup() {
  // put your setup code here, to run once:

 irrecv.enableIRIn();
pinMode(relay, OUTPUT); // declare lamp as output
pinMode(led, OUTPUT);
Serial.begin(9600);

digitalWrite (relay, HIGH);
}

void loop() {
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 13033: //when you press the Red button
      case 112: //when you press the Red button
        digitalWrite(led, HIGH);
        digitalWrite(relay,LOW);
        break;   
      case 2064 : //when you press the 1 off button
      case 2320 : //when you press the 1 off button 
        digitalWrite(led, LOW); 
        digitalWrite(relay,HIGH);  
        break;
    }
    irrecv.resume();
  }
  delay(10);
}
 
