#ifndef DistanceWithCondition_H
#define DistanceWithCondition_H

#include "DistanceInput.h"
#include "DigitalInput.h"

class DistanceWithCondition : public DistanceInput
{
  DistanceInput & distanceInput;
  DigitalInput & stopInput;

public:
  DistanceWithCondition(DistanceInput & distanceInput, DigitalInput & stopInput)
    : distanceInput(distanceInput)
    , stopInput(stopInput)
  {
  }

  virtual unsigned int freeBlocks() const
  {
    return stopInput.get()
      ? 0
      : distanceInput.freeBlocks();
  }
};
#endif
