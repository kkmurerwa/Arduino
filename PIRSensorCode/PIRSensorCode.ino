//Constant declaration
const int LEDBulb = 12;//Pin for LED indicator
const int PIRPin = 8;//Pin for the PIR


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDBulb, LOW);
  pinMode(PIRPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIRPin)== HIGH){
    //Actions performed if input is detected
    pinMode(LEDBulb, HIGH);
    delay(200);
    pinMode(LEDBulb,LOW);
    delay(200);
  }
}
