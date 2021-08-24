//Praktikum 3 - Digital Read Push Button

int ledPin = 13;
int button = 7;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT);

}

void loop() {
  int val = digitalRead(button);
  if( val == HIGH ){
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
