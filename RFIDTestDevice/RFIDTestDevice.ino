#include <MFRC522.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>
#include <SPI.h>
//
//
//#define OLED_RESET 4
//Adafruit_SSD1306 display(OLED_RESET);

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class

MFRC522::MIFARE_Key key; 

int code[] = {69,141,8,136}; //This is the stored UID
int codeRead = 0;
String uidString;
void setup() {
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522   
}

void loop() {
  if(  rfid.PICC_IsNewCardPresent())
  {
      readRFID();
  }
  delay(100);

}

void readRFID()
{
  
  rfid.PICC_ReadCardSerial();
  Serial.print(F("\nPICC type: "));
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));
   
    Serial.println("Scanned PICC's UID:");
    printDec(rfid.uid.uidByte, rfid.uid.size);

    uidString = String(rfid.uid.uidByte[0])+" "+String(rfid.uid.uidByte[1])+" "+String(rfid.uid.uidByte[2])+ " "+String(rfid.uid.uidByte[3]);

    int i = 0;
    boolean match = true;
    while(i<rfid.uid.size){
      if(!(rfid.uid.uidByte[i] == code[i])){
           match = false;
      }
      i++;
    }

    if(match){
      Serial.println("\nI know this card!");
    }
    else{
      Serial.println("\nUnknown Card");
    }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}

void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
