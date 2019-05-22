//Import libraries
#include<Wire.h>
#include<LCD.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


//Declare global variables
//Declare constants
const int pushButton = 2;
const int ledPin = 13;

//Declare variables
int buttonPushCounter = 0; 
int buttonState = 0;
int lastButtonState = 0;     // previous state of the button



void setup(){
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  //Set up LCD displayed content
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Hello, World");
  lcd.setCursor(0,1);
  lcd.print("From Kioko");
  delay(2000);
}

void loop(){
  buttonState = digitalRead(pushButton);
  lcd.clear();
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
    }
    delay(50);
  }
}
