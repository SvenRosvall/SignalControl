class MockDistanceInput : public DistanceInput
{
  unsigned int freeBlockCount = 0;

public:
  virtual unsigned int freeBlocks() const
  {
    return freeBlockCount;
  }

  void setFreeBlocks(unsigned int count)
  {
    freeBlockCount = count;
  }
};
