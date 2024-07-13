#ifndef DistanceTimer_H
#define DistanceTimer_H

#include "DistanceInput.h"
#include "DigitalInput.h"
#include "PinInput.h"

const long interval = 5 * 1000;

class DistanceTimer : public DistanceInput
{
  DigitalInput const & trigger;
  unsigned long timer;
  unsigned int freeBlockCount;

public:
  // Convenience Constructor
  DistanceTimer(int triggerPin)
    // Note: Lifetime of PinInput object infinite.
    // This is OK as the DistanceTimer is usually never destroyed.
    : DistanceTimer(* new PinInput(triggerPin))
  {
  }

  DistanceTimer(DigitalInput const & trigger)
    : trigger(trigger)
    , timer(0)
    , freeBlockCount(0)
  {
  }

  void setTimer(unsigned long timer)
  {
    this->timer = timer;
  }
  
  virtual void begin() const override
  {
    trigger.begin();
  }

  void update()
  {
    if (trigger.get())
    {
      timer = millis();
    }
    freeBlockCount = (millis() - timer) / interval;
  }

  virtual unsigned int freeBlocks() const
  {
    return freeBlockCount;
  }
};
#endif
