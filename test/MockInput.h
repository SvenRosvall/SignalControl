class MockInput : public DigitalInput
{
  bool inputValue;

public:
  MockInput(bool inputValue = false)
    : inputValue(inputValue)
  {}

  virtual MockInput * move_clone()
  {
    return new MockInput(inputValue);
  }

  void set(bool value)
  {
    this->inputValue = value;
  }

  virtual bool get() const
  {
    return inputValue;
  }
};
