void RFIDModule()
{
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "6E 97 7B 89") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Access FOR CEDRIC");
    Serial.println();
    analogWrite (in1, 80);
    digitalWrite (led_g, HIGH);
    delay(1000);
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);

    delay(1000);

    analogWrite (in2, 100);
    delay(100);
    digitalWrite (in1, LOW);
    digitalWrite (in2, LOW);
    digitalWrite (led_g, LOW);
    for (maintainer = 0; maintainer <1;){
      //Add code
      PIRModule();
      IRRelay();
      btMotor();
    }

  }

  else   {
    Serial.println(" Access denied");
    digitalWrite (led_r, HIGH);
    delay(1000);
    digitalWrite (led_r, LOW);
  }
}
