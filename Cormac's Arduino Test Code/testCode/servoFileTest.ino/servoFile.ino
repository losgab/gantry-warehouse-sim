#define buttonPin 2
#include "Button.hpp"
#include <Servo.h>
int buttonState = 0;
int pos = 0; 
Servo myservo; 

Button buttonGood(buttonPin, true);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(3);
  // initialize the pushbutton pin as an input:
  // pinMode(buttonPin, INPUT);
}

void loop() {

  buttonGood.update_button();
  if (buttonGood.was_pushed()) {
    Serial.println("was PUSHED");
    spinServo(2);
  } else {
    Serial.println("was NOT PUSHED");
  }

  // put your main code here, to run repeatedly:
  // buttonState = digitalRead(buttonPin);
  // if (buttonState == HIGH) {
  //   Serial.println("Button is in HIGH state");
  // } else {
  //   Serial.println("Button is in LOW state");
  // }
  delay(10);
}

void spinServo(int repeat) {
  for (int i = 0; i < repeat; i++) {
    for (pos = 0; pos <= 180; pos += 1) { 
        myservo.write(pos);             
        delay(10);                      
      }
      delay(1000);
    for (pos = 180; pos >= 0; pos -= 1) { 
      myservo.write(pos);              
      delay(10);                       
    }
  }
  delay(1000);
}
