#include <Stepper.h>
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution for your motor
int motorSpeed;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
int stepCount = 0;         // number of steps the motor has taken

void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  motorSpeed = 100;
  myStepper.setSpeed(motorSpeed);
  myStepper.step(-
  6000);//Change sign to reverse motor directione
  delay(2000);
}
