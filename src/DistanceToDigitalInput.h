#ifndef DistanceToDigitalInput_h
#define DistanceToDigitalInput_h

#include "DigitalInput.h"
#include "DistanceInput.h"

class DistanceToDigitalInput : public DigitalInput
{
  const DistanceInput & input;

public:
  DistanceToDigitalInput(const DistanceInput & input)
    : input(input)
  {}

  virtual DistanceToDigitalInput * move_clone() const
  {
    return new DistanceToDigitalInput(input);
  }

  virtual bool get() const
  {
    return input.freeBlocks() > 0;
  }
};

#endif
