#include <AccelStepper.h>

const int lightPin = 36;    // Analog pin connected to the light sensor
const int motorDirectionPin = 32;    // GPIO pin connected to the direction pin of the motor
const int motorStepPin = 33;    // GPIO pin connected to the step pin of the motor
const int increaseButtonPin = 21;   // GPIO pin connected to the increase (blue) button
const int decreaseButtonPin = 22;   // GPIO pin connected to the decrease (red) button
const int resetButtonPin = 19;   // GPIO pin connected to the reset (black) button

AccelStepper stepper(AccelStepper::DRIVER, motorStepPin, motorDirectionPin); // Stepper Setup

bool lastIncreaseButtonState = HIGH;
bool lastDecreaseButtonState = HIGH;
bool lastResetButtonState = HIGH;

int Angle = 0;

void setup() {
  Serial.begin(115200);

  //Stepper Setup
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);

  // Initialize the button pins as an input with an internal pull-up resistor
  pinMode(increaseButtonPin, INPUT_PULLUP);
  pinMode(decreaseButtonPin, INPUT_PULLUP);
  pinMode(resetButtonPin, INPUT_PULLUP);
}

void loop() {
  int rawValue = analogRead(lightPin);
  int adjustedValue = 4095 - rawValue; // Adjusts light intensity value

  //Serial.print("Light Intensity: ");
  //Serial.println(adjustedValue);

  // Read the current state of the button
  bool increaseButtonState = digitalRead(increaseButtonPin);
  bool decreaseButtonState = digitalRead(decreaseButtonPin);
  bool resetButtonState = digitalRead(resetButtonPin);

  // Check if the buttons were pressed (LOW state)
  if (increaseButtonState == LOW && lastIncreaseButtonState == HIGH) {
    if (Angle < 180) {
      Angle += 1;

      stepper.move(1); // 1/2 microstepping
      stepper.runToPosition();

      Serial.print("Angle: ");
      Serial.println(Angle);
    }
    else {
      Serial.print("Angle: ");
      Serial.println(Angle);
    }

    delay(100);
  }
  if(decreaseButtonState == LOW && lastDecreaseButtonState == HIGH) {
    if (Angle > 0) {
      Angle -= 1;
      
      stepper.move(-1); // 1/2 microstepping
      stepper.runToPosition();
      
      Serial.print("Angle: ");
      Serial.println(Angle);
    }
    else {
      Serial.print("Angle: ");
      Serial.println(Angle);
    }

    delay(100);
  }
  if(resetButtonState == LOW && lastResetButtonState == HIGH) {
    stepper.move(-Angle);
    stepper.runToPosition();

    Angle = 0;

    Serial.print("Angle: ");
    Serial.println(Angle);

    delay(100);
  }

  lastIncreaseButtonState = increaseButtonState;
  lastDecreaseButtonState = decreaseButtonState;
  lastResetButtonState = resetButtonState;

  delay(10);
}
