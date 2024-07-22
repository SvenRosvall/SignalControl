class MockDistanceInput : public DistanceInput
{
  unsigned int freeBlockCount = 0;
  mutable bool beginCalled = false;

public:
  virtual void begin() const override
  {
    beginCalled = true;
  }

  bool wasBeginCalled() const
  {
    return beginCalled;
  }

  virtual unsigned int freeBlocks() const override
  {
    return freeBlockCount;
  }

  void setFreeBlocks(unsigned int count)
  {
    freeBlockCount = count;
  }
};
