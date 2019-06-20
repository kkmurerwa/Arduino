void dispenser(char selection){
  switch (selection) {
    case '1':
      digitalWrite(solenoid0, HIGH); 
      delay(motorTimer);
      digitalWrite(solenoid0, LOW); 
      break;
    case '2':
      digitalWrite(solenoid1, HIGH); 
      delay(motorTimer);
      digitalWrite(solenoid1, LOW); 
      break;
    case '3':
      digitalWrite(motor0, HIGH); 
      delay(motorTimer);
      digitalWrite(motor0, LOW); 
      break;
    case '4':
      digitalWrite(motor1, HIGH); 
      delay(motorTimer);
      digitalWrite(motor1, LOW); 
      break;
    case '5':
      digitalWrite(motor2, HIGH); 
      delay(motorTimer);
      digitalWrite(motor2, LOW); 
      break;
    case '6':
      digitalWrite(motor3, HIGH); 
      delay(motorTimer);
      digitalWrite(motor3, LOW); 
      break;
  }
  lcdPrinter("Please pick", "your item");
  delay(2500);
  coinDetector();
}
