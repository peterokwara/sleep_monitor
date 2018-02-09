
int ledPin = 13;
int inputPin = 9;
int pirState = LOW;
int val = 0;



void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin); // read input value
  digitalWrite(ledPin, val);
  if (val == 1){
    digitalWrite(ledPin, LOW);
  }

}
