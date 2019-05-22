/*
   The code below was used to send information to a mobile phone app
   via a bluetooth HC-06 module.

   Author: Kenneth Murerwa
*/



const int pushButton = 7;
int previousState = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);//Initialize serial communication
  pinMode(pushButton, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int inputValue = digitalRead(pushButton);
  if (inputValue == HIGH) {
    printer(1);
  }
  else {
    printer(0);
  }
}

void printer(int newState) {
  if (previousState != newState){
    Serial.println(newState);
    previousState = newState;
  }
}
