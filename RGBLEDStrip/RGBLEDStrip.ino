// the setup function runs once when you press reset or power the board
const int red = 8;
const int blue = 9;
const int green = 10;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(red, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(red, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(red, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(blue, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(blue, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(green, LOW);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(green, HIGH);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
