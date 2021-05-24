#ifndef AndInput_H
#define AndInput_H

#include "DigitalInput.h"

class AndInput : public DigitalInput
{
  DigitalInput & input1;
  DigitalInput & input2;

public:
  AndInput(DigitalInput & input1, DigitalInput & input2)
    : input1(input1), input2(input2)
  {
  }

  virtual bool get() const
  {
    return input1.get() && input2.get();
  }
};

#endif
