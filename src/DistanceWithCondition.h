#ifndef DistanceWithCondition_H
#define DistanceWithCondition_H

#include "DistanceInput.h"
#include "DigitalInput.h"

class DistanceWithCondition : public DistanceInput
{
  const DistanceInput & distanceInput;
  const DigitalInput * stopInput;
  bool owningStopInput;

public:
  DistanceWithCondition(const DistanceInput & distanceInput, const DigitalInput & stopInput)
    : distanceInput(distanceInput)
    , stopInput(&stopInput), owningStopInput(false)
  {
  }

  DistanceWithCondition(const DistanceInput & distanceInput, const DigitalInput && stopInput)
    : distanceInput(distanceInput)
    , stopInput(stopInput.move_clone()), owningStopInput(true)
  {
  }

  virtual void begin() const override
  {
    distanceInput.begin();
    stopInput->begin();
  }

  virtual unsigned int freeBlocks() const override
  {
    return stopInput->get()
      ? 0
      : distanceInput.freeBlocks();
  }
};
#endif
