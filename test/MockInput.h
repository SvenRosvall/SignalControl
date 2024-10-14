#include "DigitalInput.h"

class MockInput : public DigitalInput
{
  bool inputValue;
  mutable bool beginCalled = false;

public:
  explicit MockInput(bool inputValue = false)
    : inputValue(inputValue)
  {}

  virtual MockInput * move_clone() const override
  {
    return new MockInput(inputValue);
  }

  virtual void begin() const override
  {
    beginCalled = true;
  }
  
  bool wasBeginCalled() const
  {
    return beginCalled;
  }

  void set(bool value)
  {
    this->inputValue = value;
  }

  virtual bool get() const override
  {
    return inputValue;
  }
};
