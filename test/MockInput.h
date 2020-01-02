class MockInput : public DigitalInput
{
  bool inputValue;

public:
  void set(bool value)
  {
    this->inputValue = value;
  }

  virtual bool get() const
  {
    return inputValue;
  }
};
