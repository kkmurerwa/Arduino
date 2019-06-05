#include<LCD.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
 
const int currentPin = A0;
int sensitivity = 66;
int adcValue= 0;
int offsetVoltage = 2500;
double adcVoltage = 0;
double currentValue = 0;
double totalCurrent = 0;
 
void setup() 
{
  Serial.begin(9600);
  pinMode(currentPin, INPUT);
  lcd.begin(16, 2);
  lcd.print(" Current Sensor ");
  lcd.setCursor(0,1);
  lcd.print("  with Arduino  ");
  delay(2000);
}
 
void loop()
{
  adcValue = analogRead(currentPin);
  adcVoltage = (adcValue / 1024.0) * 5000;
  currentValue = ((adcVoltage - offsetVoltage) / sensitivity);
  totalCurrent = currentValue;
  
  Serial.print("Raw Sensor Value = " );
  Serial.print(adcValue);
 
  lcd.clear();

  Serial.print("\t Voltage(mV) = ");
  Serial.print(adcVoltage,3);
 
  Serial.print("\t Current = ");
  Serial.println(currentValue,3);
 
  lcd.setCursor(0,0);
  lcd.print("Current =       ");
  lcd.setCursor(10,0);
  lcd.print(totalCurrent,2);
  lcd.setCursor(14,0);
  lcd.print("A");
  delay(2500);
}
