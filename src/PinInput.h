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

  virtual bool get() const
  {
    return digitalRead(inputPin) == HIGH;
  }
};
