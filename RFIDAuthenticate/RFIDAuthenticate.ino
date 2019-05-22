 
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
#define BUZZER 2 //buzzer pin MFRC522 mfrc522(SS_PIN, RST_PIN); 
#define LED_G 7 //define green LED
#define LED_R 6 //define red LED
MFRC522::MIFARE_Key key;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus mfrc522.
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();


  pinMode (LED_G, OUTPUT);  // LED green define output
  pinMode (LED_R, OUTPUT);  // LED red define output
  pinMode (BUZZER, OUTPUT); 
  noTone(BUZZER); 
  Serial.println("Put your card to the reader..."); 
  Serial.println();
  
}
void loop() 
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
  String content= "";
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
    Serial.println("Access for Cedric"); // 
    digitalWrite (LED_G, HIGH);
  
    delay (200);
    
    tone(BUZZER, 500);
    delay(500);
    digitalWrite (LED_G, LOW);
   delay(500);
    noTone(BUZZER);
  }
 
 else   {
    Serial.println(" Access denied");
    digitalWrite(LED_R, HIGH); 
    tone(BUZZER, 300); 
    delay(500); 
    digitalWrite(LED_R, LOW); 
    noTone(BUZZER);

  }
} 
