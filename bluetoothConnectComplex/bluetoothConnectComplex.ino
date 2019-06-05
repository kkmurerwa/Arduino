//Declare the constants to be used in the project
const int ledBulbOne = 13;
const int ledBulbtwo = 14;
const int ledBulbthree = 15;

//Initialize the state of the bulbs as OFF
int state = '0';


void setup() {
  //Declare the other bulbs as outputs
  pinMode(ledBulbOne, OUTPUT);
  pinMode(ledBulbtwo, OUTPUT);
  pinMode(ledBulbthree, OUTPUT);
  
  //Set inital value of other bulbs
  digitalWrite(ledBulbOne, LOW);
  digitalWrite(ledBulbtwo, LOW);
  digitalWrite(ledBulbthree, LOW);
  
  //Start serial communication
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port and changes value of the state variable
 }
 if (state == '0') {
  digitalWrite(ledBulbOne, LOW);
  digitalWrite(ledBulbtwo, LOW);
  digitalWrite(ledBulbthree, LOW);
 }
 else if (state == '1') {
  digitalWrite(ledBulbOne, HIGH);
  digitalWrite(ledBulbtwo, HIGH);
  digitalWrite(ledBulbthree, HIGH);
   
 }
 //Add else if statements for states "10", "11", "20", "21", "30", "31"
 //Set each of the six states to light or turn off their respective pins
 //Add the code here
  else if (state == '3') {
  digitalWrite(ledBulbOne, HIGH);
  
  }
  else if (state == '2') {
  digitalWrite(ledBulbOne, LOW);
 
 }
  else if (state == '5') {
  digitalWrite(ledBulbtwo, HIGH);
  
  }
  else if (state == '4') {
  digitalWrite(ledBulbtwo, LOW);
 
 }
  else if (state == '7') {
  digitalWrite(ledBulbthree, HIGH);
  
  }
  else if (state == '6') {
  digitalWrite(ledBulbthree, LOW);
 
 }
}
