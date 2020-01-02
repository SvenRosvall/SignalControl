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
  
  bool get() const
  {
    return input.freeBlocks() > 0;
  }
};

#endif
