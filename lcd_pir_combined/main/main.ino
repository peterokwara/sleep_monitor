// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int resetButtonPin = 0;    // the number of the pushbutton pin

// Connect the input pin from the motion sensor to 9
// Connect the positive end of the led to pin 13

int ledPin = 13;
int inputPin = 9;
int pirState = LOW;
int val = 0;
int count;

int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(inputPin, INPUT);

  pinMode(resetButtonPin, INPUT);

  
  lcd.begin(16, 2);
  lcd.print("You moved");

}

void loop() {
  
  // read the state of the switch into a local variable:
  int reading = digitalRead(resetButtonPin);

// If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == LOW) {
        count = 0;
        lcd.clear();
        setup();
      }
    }
  }

//  // set the LED:
//  digitalWrite(ledPin, ledState);


  
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

  lastButtonState = reading;

}
