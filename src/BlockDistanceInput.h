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
  BlockDistanceInput(DigitalInput const & blockTrigger, DistanceInput & distanceBeyond)
    : blockTrigger(&blockTrigger)
    , distanceBeyond(&distanceBeyond)
    , freeBlockCount(0)
  {
  }

  explicit BlockDistanceInput(DigitalInput const & blockTrigger)
    : blockTrigger(&blockTrigger)
    , distanceBeyond(nullptr)
    , freeBlockCount(0)
  {
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2)
    : BlockDistanceInput(blockTrigger1, * new BlockDistanceInput(blockTrigger2))
  {
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2, DigitalInput const & blockTrigger3)
    : BlockDistanceInput(blockTrigger1, * new BlockDistanceInput(blockTrigger2, blockTrigger3))
  {
  }

  // Convenience constructors for backwards compatibility. Takes input pins for track sensors.
  explicit BlockDistanceInput(int block1Pin)
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

  virtual void begin() const override
  {
    blockTrigger->begin();
    distanceBeyond->begin();
  }

  virtual void update() override
  {
    freeBlockCount = findFreeBlocks();
  }

  virtual unsigned int freeBlocks() const override
  {
    return freeBlockCount;
  }

private:
  unsigned int findFreeBlocks()
  {
    if (blockTrigger->get())
    {
      return 0;
    }
    else if (distanceBeyond != nullptr)
    {
      distanceBeyond->update();
      unsigned int freeBlocksBeyond = distanceBeyond->freeBlocks();
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
