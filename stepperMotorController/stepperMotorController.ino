/*
 * Stepper motor code controls both unidirectional and bidirectional motors
 * In order to connect the motor correctly, connect as follows for the Epoch Stepper
 * With the chips farthest from you on the board and from the closest pin to the 
 * epoch stepper
 * First pin to pin 11 of arduino
 * Second pin to pin 10
 * Third pin to pin 9
 * Fourth pin to pin 8
 * 
 * Sankyo stepper
 * First pin to pin 4 of arduino
 * Second pin to pin 6
 * Third pin to pin 5
 * Fourth pin to pin 7
 */
#include <Stepper.h>

const int buttonPin1 = 11;     // the number of the pushbutton pin
const int buttonPin2 = 12;  //Second pushbbutton pin
const int buttonPin3 = 13;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
// for your motor
int motorSpeed = 0;//Set the initial rotate speed
int location[3][2] = {{300, 450},{350, 550},{400, 650}};

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
Stepper myStepper2(stepsPerRevolution, 4, 5, 6, 7);//Pins for the second stepper motor

int stepCount = 0;         // number of steps the motor has taken
int scrollDown = LOW; 
int scrollUp = LOW;
int select = LOW;
int counter = 1;
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  Serial.println(counter);
}

void loop() {
  scrollDown = digitalRead(buttonPin1);
  scrollUp = digitalRead(buttonPin3);
  select = digitalRead(buttonPin2);
  Serial.print("Up: ");
  Serial.println(scrollUp);
  Serial.print("Down: ");
  Serial.println(scrollDown);
  Serial.print("Select: ");
  Serial.println(select);
  if (counter >=1  && counter <=3){
//    Serial.println(counter);
    if (counter < 3){
      if (scrollUp == HIGH){
        counter += 1;
        delay(500);
        Serial.println(counter);
      }
    }
    if (counter >1){
      if (scrollDown == HIGH){
        counter -= 1;
        delay(500);
        Serial.println(counter);
      }
    }
    if (select == HIGH){
      //Do something
      motorSpeed = 30;
      myStepper.setSpeed(motorSpeed);
      myStepper2.setSpeed(motorSpeed);
      runMotorOne(location[counter-1][0]);
      runMotorTwo(location[counter-1][1]);
    }
  }
  else{
     //Do nothing
  }
  
}

void runMotorOne(int rot){
  myStepper.step(rot);//Change sign to reverse motor directione
}

void runMotorTwo(int rot){
  myStepper2.step(rot);//Change sign to reverse motor directione
  motorSpeed = 0;
}
