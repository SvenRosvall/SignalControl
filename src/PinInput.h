#ifndef PinInput_H
#define PinInput_H

#include "DigitalInput.h"

class PinInput : public DigitalInput
{
  int inputPin;

public:
  PinInput(int inputPin)
    : inputPin(inputPin)
  {
    pinMode(inputPin, INPUT_PULLUP);
  }

  virtual PinInput * move_clone() const
  {
    return new PinInput(inputPin);
  }

  // Returns true if the input pin is active (low).
  virtual bool get() const
  {
    return digitalRead(inputPin) == LOW;
  }
};

#endif
