#ifndef DistanceToDigitalInput_h
#define DistanceToDigitalInput_h

#include "DigitalInput.h"
#include "DistanceInput.h"

class DistanceToDigitalInput : public DigitalInput
{
  const DistanceInput & input;

public:
  explicit DistanceToDigitalInput(const DistanceInput & input)
    : input(input)
  {}

  virtual DistanceToDigitalInput * move_clone() const override
  {
    return new DistanceToDigitalInput(input);
  }

  virtual void begin() const override
  {
    input.begin();
  }

  virtual bool get() const override
  {
    return input.freeBlocks() > 0;
  }
};

#endif
