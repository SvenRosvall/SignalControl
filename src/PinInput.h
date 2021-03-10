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

  // Returns true if the input pin is active (low).
  virtual bool get() const
  {
    return digitalRead(inputPin) == LOW;
  }
};
