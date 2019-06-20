//This function controls the motor used to open the window
void btMotor(){
  if(Serial.available() > 0){ // Checks whether data is comming from the serial port
    stateBT = Serial.read(); // Reads the data from the serial port
 }
  if (stateBT == '0') {
    digitalWrite(motorPin1, LOW);   
    digitalWrite(motorPin2, LOW);  
    digitalWrite(motorPin3, LOW);   
    digitalWrite(motorPin4, LOW);  
    Serial.println("Motors are rotating left");
    stateBT = 0;
  }
    else if (stateBT=='b')
    {
      digitalWrite(motorPin1, LOW);   
      digitalWrite(motorPin2, HIGH);  
      digitalWrite(motorPin3, LOW);   
      digitalWrite(motorPin4, HIGH);  
      Serial.println("Motors are rotating left");
    }
    else if (stateBT=='f')
    {
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      digitalWrite(motorPin3, HIGH); 
      digitalWrite(motorPin4, LOW); 
      Serial.println("Motors are rotating right");
    }
   else if (stateBT=='r')
    {
      digitalWrite(motorPin1, HIGH); 
      digitalWrite(motorPin2, LOW); 
      digitalWrite(motorPin3, LOW); 
      digitalWrite(motorPin4, HIGH); 
      Serial.println("First Motor is rotating right & Second is left");
    }
    else if (stateBT=='l')
    {
      digitalWrite(motorPin1, LOW); 
      digitalWrite(motorPin2, HIGH); 
      digitalWrite(motorPin3, HIGH); 
      digitalWrite(motorPin4, LOW); 
      Serial.println("First Motor is rotating Left & second is right");
    }
}
