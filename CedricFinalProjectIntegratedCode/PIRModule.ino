void PIRModule(){
  valPIR = digitalRead(sensor);   // read sensor value
  if (valPIR == HIGH) {           // check if the sensor is HIGH
    Serial.println("Mot!"); 
    digitalWrite(led, HIGH);   // turn LED ON
    delay(5000);                // delay 100 milliseconds 
    digitalWrite(led, LOW);
    
    if (statePIR == LOW) {
      Serial.println("Motion detected!"); 
      statePIR = HIGH;       // update variable state to HIGH
    } 
  }
}
