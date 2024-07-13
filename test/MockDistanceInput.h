class MockDistanceInput : public DistanceInput
{
  unsigned int freeBlockCount = 0;

public:
  virtual void begin() const override
  {}

  virtual unsigned int freeBlocks() const override
  {
    return freeBlockCount;
  }

  void setFreeBlocks(unsigned int count)
  {
    freeBlockCount = count;
  }
};
