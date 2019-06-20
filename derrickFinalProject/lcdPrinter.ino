void lcdPrinter(String first, String second){
  lcd.clear();
  lcd.print(first);
  lcd.setCursor(0,1);
  lcd.print(second);
}
