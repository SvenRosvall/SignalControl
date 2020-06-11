#ifndef DistanceTimer_H
#define DistanceTimer_H

#include "DistanceInput.h"

const long interval = 5 * 1000;

class DistanceTimer : public DistanceInput
{
  int triggerPin;
  unsigned long timer;
  unsigned int freeBlockCount;

public:
  DistanceTimer(int triggerPin)
    : triggerPin(triggerPin)
    , timer(0)
    , freeBlockCount(0)
  {
    pinMode(triggerPin, INPUT_PULLUP);
  }
  
  void setTimer(unsigned long timer)
  {
    this->timer = timer;
  }

  void update()
  {
    if (digitalRead(triggerPin) == LOW)
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
