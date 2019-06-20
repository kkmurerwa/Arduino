/*---------Various imports for all the modules---------*/

//Imports for the Motor
#include <SoftwareSerial.h>

//Imports for the RFID Module
#include <DRV8835MotorShield.h>

#include <deprecated.h>
#include <require_cpp11.h>
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

//Imports for IR Relay
#include <RelayModule.h>
#include <IRremote.h>


/*------------Global Constants for the various modules----------*/

//Constants for the RFID Module
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
//
//
/*------------Variables for all the modules----------*/

//Variable for Bluetooth Module
int stateBT = 0;// to store input character received via BT.

//Variables for the Motors
int motorPin1 = 10;                // pin 8 on L293D IC
int motorPin2 = 11;                // pin 9 on L293D IC
int motorPin3 = 12;               // pin 10 on L293D IC
int motorPin4 = 14;               // pin 11 on L293D IC

//Variables for the RFID Module
int led_g = 7;
int led_r = 6;
int in1 = 4;
int in2 = 5;

//Variables for the PIR Module
int led = 13;                // the pin that the LED is atteched to
int sensor = 16;             // the pin that the sensor is atteched to
int statePIR = LOW;             // by default, no motion detected
int valPIR = 0;  // variable to store the sensor status (value)

//Variables for the IR Relay
int relay = 9; // choose the pin for the RELAY
int LED = 13;
int IR_Recv = 8;
IRrecv irrecv(IR_Recv);
decode_results results;
int val = 0; // variable for reading the pin status

//Extra variables
int maintainer = 0;

void setup(){
  //Declare the variables to be used as I/O in the project
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

  //Initialize the variables
  //Motor Pins
  digitalWrite (motorPin1, LOW);
  digitalWrite (motorPin2, LOW);
  digitalWrite (motorPin3, LOW);
  digitalWrite (motorPin4, LOW);

  //RFID Pins
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(led_g , OUTPUT);
  pinMode(led_r , OUTPUT);

  //PIRModule Pins
  pinMode(led, OUTPUT);      // initalize LED as an output 
  pinMode(sensor, INPUT);    // initialize sensor as an input

  //IR Relay Module
  irrecv.enableIRIn();
  pinMode(relay, OUTPUT); // declare lamp as output
  pinMode(led, OUTPUT);


  digitalWrite (relay, HIGH);
  //Begin serial
  Serial.begin(9600);
}

void loop(){
  //Start up the RFID Module to allow entry into the house
  RFIDModule();
}
