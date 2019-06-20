#include<LCD.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

//Variables for the coinDetector fuction
int threshold = 900;
int coinValue;
int previousState = 0;
int currentState = 1;
int coinInputPin = A0;

int previousState = 0;
int currentState = 1;
int coinInputPin = A0;

//Variables for the controllerModule function
char* names [7] = {"1. Liquid X", "2. Liquid Y", "3. Fudge", "4. Wafer", "5. Candy Bar", "6. Chocolate", ""};
int upButton = 12;
int okButton = 11;
int downButton = 10;
int scrollDown = LOW; 
int scrollUp = LOW;
int select = LOW;
int counter = 0;
char pointer = '>';
int maintainer = 0;//Maintains the display until an item is purchased

// liquids
int solenoid0 = 3;
int solenoid1 = 4;
// solids
int mot0 = 5;
int mot1 =6 ;
int mot2 =7 ;
int mot3 = 8;
 
void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
//  animator();

//  GUI
  pinMode(coinInputPin, INPUT);
  pinMode(LED_BUILTIN,  OUTPUT);
  pinMode(upButton, INPUT);
  pinMode(okButton, INPUT);
  pinMode(downButton, INPUT);
  
  //  solids
  pinMode(mot0, OUTPUT);
  pinMode(mot1, OUTPUT);
  pinMode(mot0, OUTPUT);
  pinMode(mot1, OUTPUT);
  
  
  

  
  //  liquids
  pinMode(solenoid0, OUTPUT);
  pinMode(solenoid1, OUTPUT);
}
 
void loop(){
  coinDetector();
}
