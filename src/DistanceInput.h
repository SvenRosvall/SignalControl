#ifndef DistanceInput_h
#define DistanceInput_h

class DistanceInput
{
public:
  virtual unsigned int freeBlocks() const = 0;
  virtual void begin() const = 0;
  virtual void update() {}
};

#endif
