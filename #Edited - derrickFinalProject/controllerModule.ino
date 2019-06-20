void controllerModule(){
    counter = 0;
    lcd.clear();
    lcd.print(pointer);
    lcd.print(names[counter]);
    lcd.setCursor(0,1);
    lcd.print(" ");
    lcd.print(names[counter+1]);
    for (maintainer = 0; maintainer <1;){
      digitalWrite(13, HIGH);
      scrollDown = digitalRead(downButton);
      scrollUp = digitalRead(upButton);
      select = digitalRead(okButton);
      if (counter >=0  && counter < (sizeof(names)/2)){
        if (counter < (sizeof(names)/2)-2){
          if (scrollUp == HIGH){
            counter += 1;
            digitalWrite(13, HIGH);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(pointer);
            lcd.print(names[counter]);
            lcd.setCursor(0,1);
            lcd.print(" ");
            lcd.print(names[counter+1]);
            delay(500);
          }
        }
        if (counter >0){
          if (scrollDown == HIGH){
            counter -= 1;
            digitalWrite(13, HIGH);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(pointer);
            lcd.print(names[counter]);
            lcd.setCursor(0,1);
            lcd.print(" ");
            lcd.print(names[counter+1]);
            delay(500);
          }
        }
        if (select == HIGH){
          //Do something
          digitalWrite(13, HIGH);
          lcdPrinter("You selected: ", names[counter]);
          delay(2000);
          coinDetector();
          maintainer += 1;
        }
      }
    }
}
