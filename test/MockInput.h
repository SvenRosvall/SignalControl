class MockInput : public DigitalInput
{
  bool inputValue;

public:
  explicit MockInput(bool inputValue = false)
    : inputValue(inputValue)
  {}

  virtual MockInput * move_clone() const override
  {
    return new MockInput(inputValue);
  }

  virtual void begin() const override
  {}

  void set(bool value)
  {
    this->inputValue = value;
  }

  virtual bool get() const override
  {
    return inputValue;
  }
};
