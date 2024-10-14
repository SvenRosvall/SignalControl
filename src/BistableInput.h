#pragma once

#include "DigitalInput.h"
#include "PinInput.h"

// Input logic controlled by two momentary inputs, one for on and one for off.
class BistableInput : public DigitalInput
{
  const DigitalInput * onInput;
  bool owningOnInput;
  const DigitalInput * offInput;
  bool owningOffInput;
  mutable bool isOn = false;


  BistableInput(const DigitalInput *onInput, bool owningOnInput,
                const DigitalInput *offInput, bool owningOffInput)
    : onInput(onInput), owningOnInput(owningOnInput)
    , offInput(offInput), owningOffInput(owningOffInput)
  { }

public:

  BistableInput(const DigitalInput & onInput, const DigitalInput & offInput)
    : BistableInput(&onInput, false, &offInput, false)
  {

  }
  
  // Convenience ctor
  BistableInput(int onPin, int offPin)
    : BistableInput(new PinInput(onPin), true, new PinInput(offPin), true)
  {
  }

  virtual BistableInput * move_clone() const override
  {
    return new BistableInput(onInput, owningOnInput, offInput, owningOffInput);
  }

  virtual void begin() const override
  {
    onInput->begin();
    offInput->begin();
  }

  // Returns true if the input pin is active (low).
  virtual bool get() const override
  {
    if (onInput->get())
    {
      isOn = true;
    }
    else if (offInput->get())
    {
      isOn = false;
    }
    return isOn;
  }
};
