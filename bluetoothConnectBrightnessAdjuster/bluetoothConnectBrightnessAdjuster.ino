int led = 6;           // the pin that the LED is attached to
int brightness = 255;    // how bright the LED is
String state = "0";
int atoi(const char *string);


void setup() {
  pinMode(led, OUTPUT);  
  //Start serial communication
  Serial.begin(9600); // Default communication rate of the Bluetooth module
}
void loop() {
  while(Serial.available() > 0){ // Checks whether data is comming from the serial port
    state = Serial.readString(); // Reads the data from the serial port and changes value of the state variable
    Serial.println(state);
    analogWrite(led, state.toInt()/1.4);
 }
}
