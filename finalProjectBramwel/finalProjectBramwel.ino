//Variables for PIR Sensor
#define pirPin A3
int PIRValue = 0;

//Variables and constants for LDR
int sensorPin = A2; // select the input pin for LDR
int sensorValue = 0; // variable to store the value coming from the sensor
int threshold = 400;//Threshold for the ldr sensor

//Variables for the LED pins
int ledStrip = 7;

void setup() {
  pinMode(pirPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  if (sensorValue >= threshold){
    analogWrite(ledStrip, 0);
  }
  else {
    delay(1000);                       // wait for a second
    if(digitalRead(pirPin) == HIGH) {
      analogWrite(ledStrip, 255);
      delay(50);
    }
    else if(digitalRead(pirPin) == LOW) {
      analogWrite(ledStrip, 0);
      delay(50);
    }
  }
  delay(1000);
}
