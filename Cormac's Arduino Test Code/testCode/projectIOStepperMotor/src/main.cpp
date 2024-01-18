#define buttonPin 2
#include "Button.hpp"
#include <AccelStepper.h>
#include <Arduino.h>
int buttonState = 0;
#define stepPin 8
#define directionPin 9
#define numberOfSteps 200
AccelStepper stepper(AccelStepper::DRIVER, stepPin, directionPin);
Button buttonGood(buttonPin, true);
// put function declarations here:
void rotateAngle(AccelStepper stepper, float angle);

void setup() {
  Serial.begin(9600);
  stepper.setAcceleration(1000);
  stepper.setMaxSpeed(3900);
  stepper.setSpeed(2000);  // put your setup code here, to run once:

}

void loop() {
  buttonGood.update_button();

  if (buttonGood.is_pressed()) {
    rotateAngle(stepper, 180.0);
  } else {
    Serial.println("was NOT PUSHED");
  }
  // put your main code here, to run repeatedly:
}

// put function definitions here:
// rounds to the nearest angle in steps (to the even number if halfway)
void rotateAngle(AccelStepper stepper, float angle) {
  int stepsToTake = round(angle / 360 * numberOfSteps);
  stepper.move(stepsToTake);
  for(int i = 0; i < stepsToTake; i++) {
    stepper.run();
  } 
}