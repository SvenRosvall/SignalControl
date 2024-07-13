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
  }

  virtual PinInput * move_clone() const override
  {
    return new PinInput(inputPin);
  }

  virtual void begin() const override
  {
    pinMode(inputPin, INPUT_PULLUP);
  }

  // Returns true if the input pin is active (low).
  virtual bool get() const override
  {
    return digitalRead(inputPin) == LOW;
  }
};

#endif
