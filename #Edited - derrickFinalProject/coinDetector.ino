void coinDetector(){
  coinValue = analogRead(coinInputPin);
  previousState = currentState;
  if (coinValue > threshold){
    currentState = 1;
    if (currentState != previousState){
      lcdPrinter("Select an Item", "");
      delay(2000);
      controllerModule();
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
  else {
    currentState = 0;
    if (currentState != previousState){
      digitalWrite(LED_BUILTIN, HIGH);
      lcdPrinter("Insert Coin","");
    }
  }
}
