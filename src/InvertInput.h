#ifndef InvertInput_H
#define InvertInput_H

#include "DigitalInput.h"

class InvertInput : public DigitalInput
{
  DigitalInput & input;

public:
  InvertInput(DigitalInput & input)
    : input(input)
  {
  }

  virtual bool get()
  {
    return !input.get();
  }
};

#endif
