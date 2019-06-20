void animator(){
  lcd.setCursor(16, 0);
  char messageArray[50];
  String message = "Vending Machinani                 ";
  message.toCharArray(messageArray, 50);
  lcd.autoscroll();
  // print from 0 to 9:
  for (int i = 0; i < 34; i++) {
    lcd.print(message[i]);
    delay(500);
  }
  // turn off automatic scrolling
  lcd.noAutoscroll();

  lcd.setCursor(16, 0);
  for (int j = 0; j< 6; j++){
    lcd.clear();
    lcd.print("Please wait");
    if (j==0 || j==3){
      lcd.print(".");
    }
    else if (j==1 || j==4){
      lcd.print("..");
    }
    else{
      lcd.print("...");
    }
    delay(1000);
  }
  // clear screen for the next loop:
  lcd.clear();
  delay(1000);
}
