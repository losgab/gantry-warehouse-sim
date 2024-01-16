#define buttonPin 2
#include "Button.hpp"
#include <AccelStepper.h>
#include <Arduino.h>
int buttonState = 0;
#define stepPin 8
#define directionPin 9
AccelStepper stepper(AccelStepper::DRIVER, stepPin, directionPin);
Button buttonGood(buttonPin, true);
// put function declarations here:
int myFunction(int, int);

void setup() {
  Serial.begin(9600);
  stepper.setAcceleration(1000);
  stepper.setMaxSpeed(3900);
  stepper.setSpeed(2000);  // put your setup code here, to run once:

}

void loop() {
  buttonGood.update_button();

  if (buttonGood.is_pressed()) {
    stepper.moveTo(1000);
  } else {
    Serial.println("was NOT PUSHED");
  }
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}