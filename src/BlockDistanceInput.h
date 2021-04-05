#ifndef BlockDistanceInput_H
#define BlockDistanceInput_H

#include "DistanceInput.h"
#include "DigitalInput.h"
#include "PinInput.h"

class BlockDistanceInput : public DistanceInput
{
  DigitalInput const * blockTrigger;
  DistanceInput * distanceBeyond;
  unsigned int freeBlockCount;

public:
  // Convenience constructors
  BlockDistanceInput(int block1Pin)
    : BlockDistanceInput(* new PinInput(block1Pin))
  {
  }

  BlockDistanceInput(int block1Pin, int block2Pin)
    : BlockDistanceInput(* new PinInput(block1Pin), * new PinInput(block2Pin))
  {
  }

  BlockDistanceInput(int block1Pin, int block2Pin, int block3Pin)
    : BlockDistanceInput(* new PinInput(block1Pin), * new PinInput(block2Pin), * new PinInput(block3Pin))
  {
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1)
    : blockTrigger(&blockTrigger1)
    , distanceBeyond(nullptr)
    , freeBlockCount(0)
  {
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2)
    : blockTrigger(&blockTrigger1)
    , distanceBeyond(new BlockDistanceInput(blockTrigger2))
    , freeBlockCount(0)
  {
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2, DigitalInput const & blockTrigger3)
    : blockTrigger(&blockTrigger1)
    , distanceBeyond(new BlockDistanceInput(blockTrigger2, blockTrigger3))
    , freeBlockCount(0)
  {
  }

  void update()
  {
    freeBlockCount = findFreeBlocks();
  }

  virtual unsigned int freeBlocks() const
  {
    return freeBlockCount;
  }

private:
  int findFreeBlocks()
  {
    if (blockTrigger->get())
    {
      return 0;
    }
    else if (distanceBeyond != nullptr)
    {
      distanceBeyond->update();
      int freeBlocksBeyond = distanceBeyond->freeBlocks();
      if (freeBlocksBeyond >= 99)
      {
        return 99;
      }
      else
      {
        return 1 + freeBlocksBeyond;
      }
    }
    else
    {
      return 99;
    }
  }
};
#endif
