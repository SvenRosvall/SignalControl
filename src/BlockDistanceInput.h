#ifndef BlockDistanceInput_H
#define BlockDistanceInput_H

#include "DistanceInput.h"

class BlockDistanceInput : public DistanceInput
{
  int block1Pin;
  int block2Pin;
  unsigned int freeBlockCount;

public:
  BlockDistanceInput(int block1Pin, int block2Pin)
    : block1Pin(block1Pin)
    , block2Pin(block2Pin)
    , freeBlockCount(0)
  {
    pinMode(block1Pin, INPUT_PULLUP);
    pinMode(block2Pin, INPUT_PULLUP);
  }
  
  void update()
  {
    if (digitalRead(block1Pin) == LOW)
    {
      freeBlockCount = 0;
    }
    else if (digitalRead(block2Pin) == LOW)
    {
      freeBlockCount = 1;
    }
    else
    {
      freeBlockCount = 99;
    }
  }

  virtual unsigned int freeBlocks() const
  {
    return freeBlockCount;
  }
};
#endif
