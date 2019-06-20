void IRRelay() {
  //decodes the infrared input
  if (irrecv.decode(&results)){
    long int decCode = results.value;
    Serial.println(results.value);
    //switch case to use the selected remote control button
    switch (results.value){
      case 13033: //when you press the Red button
      case 112: //when you press the Red button
        digitalWrite(led, HIGH);
        digitalWrite(relay,LOW);
        break;   
      case 2064 : //when you press the 1 off button
      case 2320 : //when you press the 1 off button 
        digitalWrite(led, LOW); 
        digitalWrite(relay,HIGH);  
        break;
    }
    irrecv.resume();
  }
  delay(10);
}
