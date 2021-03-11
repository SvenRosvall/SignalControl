#ifndef BlockDistanceInput_H
#define BlockDistanceInput_H

#include "DistanceInput.h"
#include "DigitalInput.h"
#include "PinInput.h"

class BlockDistanceInput : public DistanceInput
{
  DigitalInput const & blockTrigger1;
  DigitalInput const & blockTrigger2;
  unsigned int freeBlockCount;

public:
  // Convenience constructor
  BlockDistanceInput(int block1Pin, int block2Pin)
    : BlockDistanceInput(* new PinInput(block1Pin), * new PinInput(block2Pin))
  {
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2)
    : blockTrigger1(blockTrigger1)
    , blockTrigger2(blockTrigger2)
  {
  }
  
  void update()
  {
    if (blockTrigger1.get())
    {
      freeBlockCount = 0;
    }
    else if (blockTrigger2.get())
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
