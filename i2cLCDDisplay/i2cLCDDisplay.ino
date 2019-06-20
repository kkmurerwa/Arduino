//Import libraries
#include<Wire.h>
#include<LCD.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



//Declare global variables
int counter = 0;
char* names [8] = {"1. Kenneth", "2. Derrick", "3. Moses", "4. Kioko", "5. Martin", "6. Ann Linda", "7. Pesh", "8. Bramwell"};
const int buttonPin1 = 10;     // the number of the pushbutton pin
const int buttonPin3 = 12;
char pointer = '>';
int counterDown = LOW; 
int counterUp = LOW;
int scrollDown = LOW; 
int scrollUp = LOW;


void setup(){
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16,2);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  
  lcd.clear();
  lcd.print("List of names");//Set output < 16 characters
  delay(4000);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin3, INPUT);
  digitalWrite(buttonPin1, LOW);
  digitalWrite(buttonPin3, LOW);
  lcd.setCursor(0,0);
  lcd.print(pointer);
  lcd.print(names[counter]);
  lcd.setCursor(0,1);
  lcd.print(" ");
  lcd.print(names[counter+1]);
}

void loop(){
  scrollDown = digitalRead(buttonPin1);
  scrollUp = digitalRead(buttonPin3);
  if (counter >=0  && counter < (sizeof(names)/2)){
    if (counter < (sizeof(names)/2)-1){
      if (scrollUp == HIGH){
        counter += 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(pointer);
        lcd.print(names[counter]);
        lcd.setCursor(0,1);
        lcd.print(" ");
        lcd.print(names[counter+1]);
        delay(500);
      }
    }
    if (counter >0){
      if (scrollDown == HIGH){
        counter -= 1;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(pointer);
        lcd.print(names[counter]);
        lcd.setCursor(0,1);
        lcd.print(" ");
        lcd.print(names[counter+1]);
        delay(500);
      }
    }
  }
}
