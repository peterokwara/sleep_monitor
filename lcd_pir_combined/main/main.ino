// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Connect the input pin from the motion sensor to 9
// Connect the positive end of the led to pin 13

int ledPin = 13;
int inputPin = 9;
int pirState = LOW;
int val = 0;
int count;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);

  
  lcd.begin(16, 2);
  lcd.print("You moved");

}

void loop() {
  // put your main code here, to run repeatedly:
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin); // read input value
  digitalWrite(ledPin, val);
  if (val == 1){
    digitalWrite(ledPin, LOW);
  //    delay(250);
    count++;
  }

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(count/1678);

}
