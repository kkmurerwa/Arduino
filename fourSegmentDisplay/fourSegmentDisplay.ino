//Declare pins being used by each segment with segment as variable
const int d = 3;
const int c = 4;
const int e = 2;
const int g = 6;
const int f = 5;
const int a = 7;
const int b = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  turnAllOff();
}

void loop() {
  // put your main code here, to run repeatedly:
  one();
  delay(1000);
  turnAllOff();
  two();
  delay(1000);
  turnAllOff();
  three();
  delay(1000);
  turnAllOff();
  four();
  delay(1000);
  turnAllOff();
  five();
  delay(1000);
  turnAllOff();
  six();
  delay(1000);
  turnAllOff();
  seven();
  delay(1000);
  turnAllOff();
  eight();
  delay(1000);
  turnAllOff();
  nine();
  delay(1000);
  turnAllOff();
  zero();
  delay(1000);
  turnAllOff();
}

void turnAllOff(){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void one(){
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
}
void two(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(e, LOW);
  digitalWrite(d, LOW);
}
void three(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(g, LOW);
}
void four(){
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
  digitalWrite(g, LOW);
  digitalWrite(f, LOW);
}
void five(){
  digitalWrite(a, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void six(){
  digitalWrite(a, LOW);
  digitalWrite(e, LOW);
  digitalWrite(c, LOW);
  digitalWrite(g, LOW);
  digitalWrite(d, LOW);
  digitalWrite(f, LOW);
}
void seven(){
  digitalWrite(c, LOW);
  digitalWrite(b, LOW);
  digitalWrite(a, LOW);
}
void eight(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void nine(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void zero(){
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
}
