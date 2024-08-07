#ifndef SettableInput_H
#define SettableInput_H

#include "DigitalInput.h"

class SettableInput : public DigitalInput
{
  bool state;

public:
  SettableInput(bool state = false)
    : state(state)
  {
  }

  virtual SettableInput * move_clone() const
  {
    return new SettableInput(state);
  }

  virtual void begin() const override
  {}

  virtual bool get() const
  {
    return state;
  }

  void set(bool newState)
  {
    state = newState;
  }
};

#endif
