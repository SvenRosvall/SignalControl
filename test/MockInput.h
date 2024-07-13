class MockInput : public DigitalInput
{
  bool inputValue;

public:
  MockInput(bool inputValue = false)
    : inputValue(inputValue)
  {}

  virtual MockInput * move_clone() const
  {
    return new MockInput(inputValue);
  }

  virtual void begin() const override
  {}

  void set(bool value)
  {
    this->inputValue = value;
  }

  virtual bool get() const
  {
    return inputValue;
  }
};
