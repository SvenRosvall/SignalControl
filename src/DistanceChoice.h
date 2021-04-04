#pragma once

#include "DistanceInput.h"
#include "DigitalInput.h"

class DistanceChoice : public DistanceInput
{
  DigitalInput & condition;
  DistanceInput & route1;
  DistanceInput & route2;

public:
  DistanceChoice(DigitalInput & condition, DistanceInput & route1, DistanceInput & route2)
    : condition(condition)
    , route1(route1)
    , route2(route2)
  {
  }

  virtual unsigned int freeBlocks() const
  {
    return condition.get() == false
      ? route1.freeBlocks()  // Normal route
      : route2.freeBlocks(); // Diverging route
  }
};
