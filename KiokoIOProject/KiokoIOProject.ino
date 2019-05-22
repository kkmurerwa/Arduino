//Import libraries
#include<Wire.h>
#include<LCD.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


//Declare global variables
//Declare constants
const int pushButton = 2;
const int ledPin = 13;
const int MPU_ADDR = 0x68;

//Declare variables
int buttonPushCounter = 0; 
int buttonState = 0;
int lastButtonState = 0;     // previous state of the button
int16_t accelerometer_x, accelerometer_y, accelerometer_z; // variables for accelerometer raw data
int16_t gyro_x, gyro_y, gyro_z; // variables for gyro raw data
int16_t temperature; // variables for temperature data
char tmp_str[7]; // temporary variable used in convert function
char* convert_int16_to_str(int16_t i) { // converts int16 to string. Moreover, resulting strings will have the same length in the debug monitor.
  sprintf(tmp_str, "%6d", i);
  return tmp_str;
}



void setup(){
  pinMode(pushButton, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  //Setup wire and wire communication
  Wire.begin();
  Wire.beginTransmission(MPU_ADDR); // Begins a transmission to the I2C slave (GY-521 board)
  Wire.write(0x6B); // PWR_MGMT_1 register
  Wire.write(0); // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  //Set up LCD displayed content
  lcd.begin(16,2);
  lcd.clear();
//  lcd.print("Hello, World");
//  lcd.setCursor(0,1);
//  lcd.print("From Kioko");
}

void loop(){
  buttonState = digitalRead(pushButton);
  lcd.clear();

  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x3B); // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
  Wire.endTransmission(false); // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
  Wire.requestFrom(MPU_ADDR, 7*2, true); // request a total of 7*2=14 registers
  
  accelerometer_x = Wire.read()<<8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
  accelerometer_y = Wire.read()<<8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
  accelerometer_z = Wire.read()<<8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
  temperature = Wire.read()<<8 | Wire.read(); // reading registers: 0x41 (TEMP_OUT_H) and 0x42 (TEMP_OUT_L)
  
  // print out data
  // the following equation was taken from the documentation [MPU-6000/MPU-6050 Register Map and Description, p.30]
  Serial.print(" | tmp = "); Serial.println(temperature/340.00+36.53);

  if (temperature/340.00+36.53 >= 34.00){
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.print("Temp: ");
    lcd.print(temperature/340.00+36.53);
    lcd.setCursor(0,1);
    lcd.print("Bulb is ON ");
  }
  else {
    analogWrite(ledPin, LOW);
    lcd.clear();
    lcd.print("Temp: ");
    lcd.print(temperature/340.00+36.53);
    lcd.setCursor(0,1);
    lcd.print("Bulb is OFF");
  }
  delay(1000);
}
