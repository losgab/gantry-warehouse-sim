#define buttonPin 2
#include "Button.hpp"
#include <AccelStepper.h>
int buttonState = 0;
#define stepPin 8
#define directionPin 9
AccelStepper stepper(AccelStepper::DRIVER, stepPin, directionPin);

Button buttonGood(buttonPin, true);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  stepper.setAcceleration(1000);
  stepper.setMaxSpeed(3900);
  stepper.setSpeed(2000);
  // digitalWrite(9, LOW);
  // initialize the pushbutton pin as an input:
  // pinMode(buttonPin, INPUT);
}

void loop() {

  buttonGood.update_button();

  if (buttonGood.is_pressed()) {
    stepper.runSpeed();
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
}











// #define buttonPin 2
// #include "Button.hpp"
// #include <AccelStepper.h>
// int buttonState = 0;
// int currentPos = 0;
// int moveToPos = 180;
// #define stepPin 8
// #define directionPin 9
// AccelStepper stepper(AccelStepper::DRIVER, stepPin, directionPin);

// Button buttonGood(buttonPin, true);

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   stepper.setAcceleration(1000);
//   stepper.setMaxSpeed(3900);
//   stepper.setSpeed(-2000);
//   // digitalWrite(9, LOW);
//   // initialize the pushbutton pin as an input:
//   // pinMode(buttonPin, INPUT);
// }

// void loop() {

//   buttonGood.update_button();
//   if (buttonGood.is_pressed()) {
//     stepper.moveTo(180);
//     stepper.setSpeed(2000);
//   } else if (stepper.currentPosition() == moveToPos) {
//     Serial.println("DONE");
//     Serial.println("CurrentPos == moveTo");
//   }

//   // put your main code here, to run repeatedly:
//   // buttonState = digitalRead(buttonPin);
//   // if (buttonState == HIGH) {
//   //   Serial.println("Button is in HIGH state");
//   // } else {
//   //   Serial.println("Button is in LOW state");
//   // }
// }
