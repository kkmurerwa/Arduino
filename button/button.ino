
int but1 = 10;
int but2 = 11;
int but3 = 12;


void setup() {
  // put your setup code here, to run once:
  pinMode(but1, INPUT);
  pinMode(but2, INPUT);
  pinMode(but3, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(but1));
  Serial.println(digitalRead(but2));
  Serial.println(digitalRead(but3));
  if (digitalRead(but1) == LOW){
    digitalWrite(13, HIGH);
  }
  else{
    digitalWrite(13, LOW);
  }
  delay(2000);
}
