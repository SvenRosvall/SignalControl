#ifndef TwoPinInput_H
#define TwoPinInput_H

#include "DigitalInput.h"

// Input logic controlled by two pins, one for on and one for off.
class TwoPinInput : public DigitalInput
{
  int onPin;
  int offPin;
  mutable bool isOn = false;

public:
  explicit TwoPinInput(int onPin, int offPin)
    : onPin(onPin), offPin(offPin)
  {
  }

  virtual TwoPinInput * move_clone() const override
  {
    return new TwoPinInput(onPin, offPin);
  }

  virtual void begin() const override
  {
    pinMode(onPin, INPUT_PULLUP);
    pinMode(offPin, INPUT_PULLUP);
  }

  // Returns true if the input pin is active (low).
  virtual bool get() const override
  {
    if (digitalRead(onPin) == LOW)
    {
      isOn = true;
    }
    else if (digitalRead(offPin) == LOW)
    {
      isOn = false;
    }
    return isOn;
  }
};

#endif
