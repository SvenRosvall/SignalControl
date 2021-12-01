#pragma once

#include "DistanceInput.h"
#include "DigitalInput.h"

class DistanceChoice : public DistanceInput
{
  const DigitalInput * condition;
  bool owningCondition;
  DistanceInput & route1;
  DistanceInput & route2;

public:
  DistanceChoice(const DigitalInput & condition, DistanceInput & route1, DistanceInput & route2)
    : condition(&condition), owningCondition(false)
    , route1(route1)
    , route2(route2)
  {
  }
  DistanceChoice(const DigitalInput && condition, DistanceInput & route1, DistanceInput & route2)
    : condition(condition.move_clone()), owningCondition(true)
    , route1(route1)
    , route2(route2)
  {
  }

  virtual unsigned int freeBlocks() const
  {
    return (condition->get() == false)
      ? route1.freeBlocks()  // Normal route
      : route2.freeBlocks(); // Diverging route
  }
};
