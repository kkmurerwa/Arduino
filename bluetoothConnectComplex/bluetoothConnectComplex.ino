//Declare the constants to be used in the project
const int ledBulbOne = 13;
const int mainSwitch = 12;
//const int ledBulbtwo = 14;
//const int ledBulbthree = 15;

//Initialize the state of the bulbs as OFF
int state = '0';


void setup() {
  //Declare the other bulbs as outputs
  pinMode(ledBulbOne, OUTPUT);
  
  
  //Set inital value of other bulbs
  digitalWrite(ledBulbOne, LOW);
//  digitalWrite(ledBulbtwo, LOW);
//  digitalWrite(ledBulbthree, LOW);
  
  //Start serial communication
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port and changes value of the state variable
  }
  if (state == '0') {
    digitalWrite(mainSwitch, LOW);
  //  digitalWrite(ledBulbtwo, LOW);
  //  digitalWrite(ledBulbthree, LOW);
  }
   else if (state == '1') {
    digitalWrite(mainSwitch, HIGH);
  //  digitalWrite(ledBulbtwo, HIGH);
  //  digitalWrite(ledBulbthree, HIGH);
     
   }
 //Add else if statements for states "10", "11", "20", "21", "30", "31"
 //Set each of the six states to light or turn off their respective pins
 //Add the code here
  if (state == '3' || state == '2' || state == '4' || state == '5' || state == '6' || state == '7') {
    digitalWrite(ledBulbOne, HIGH);
    delay(500);
    digitalWrite(ledBulbOne, LOW); 
    delay(500); 
    state = '0';
  }
//  else if (state == '5') {
//  digitalWrite(ledBulbOne, HIGH);
//  delay(500);
//  digitalWrite(ledBulbOne, LOW);
//  
//  }
//  else if (state == '4') {
//  digitalWrite(ledBulbOne, HIGH);
//  delay(500);
//  digitalWrite(ledBulbOne, LOW); 
// }
//  else if (state == '7') {
//  digitalWrite(ledBulbOne, HIGH);
//  delay(500);
//  digitalWrite(ledBulbOne, LOW);
//  }
//  else if (state == '6') {
//  digitalWrite(ledBulbOne, HIGH);
//  delay(500);
//  digitalWrite(ledBulbOne, LOW);
// }
}
