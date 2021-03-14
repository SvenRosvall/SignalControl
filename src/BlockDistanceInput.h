#ifndef BlockDistanceInput_H
#define BlockDistanceInput_H

#include "DistanceInput.h"
#include "DigitalInput.h"
#include "PinInput.h"

class BlockDistanceInput : public DistanceInput
{
  int blockTriggerCount;
  DigitalInput const ** blockTriggers;
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
    : blockTriggerCount(1)
    , blockTriggers(new DigitalInput const *[1])
    , freeBlockCount(0)
  {
    blockTriggers[0] = &blockTrigger1;
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2)
    : blockTriggerCount(2)
    , blockTriggers(new DigitalInput const *[2])
    , freeBlockCount(0)
  {
    blockTriggers[0] = &blockTrigger1;
    blockTriggers[1] = &blockTrigger2;
  }

  BlockDistanceInput(DigitalInput const & blockTrigger1, DigitalInput const & blockTrigger2, DigitalInput const & blockTrigger3)
    : blockTriggerCount(3)
    , blockTriggers(new DigitalInput const *[3])
    , freeBlockCount(0)
  {
    blockTriggers[0] = &blockTrigger1;
    blockTriggers[1] = &blockTrigger2;
    blockTriggers[2] = &blockTrigger3;
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
    for (int i = 0 ; i < blockTriggerCount ; ++i)
    {
      if (blockTriggers[i]->get())
      {
        return i;
      }
    }

    return 99;
  }
};
#endif
