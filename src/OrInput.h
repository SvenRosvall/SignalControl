#pragma once

#include "DigitalInput.h"
#include "mv.h"

class OrInput : public DigitalInput
{
  const DigitalInput * input1;
  const DigitalInput * input2;
  const bool owning1;
  const bool owning2;

private:
  OrInput(const DigitalInput * input1, bool owning1,
           const DigitalInput * input2, bool owning2)
    : input1(input1), input2(input2)
    , owning1(owning1), owning2(owning2)
  {}

public:
  OrInput(const DigitalInput & input1, const DigitalInput & input2)
    : OrInput(&input1, false, &input2, false)
  {
  }

  OrInput(const DigitalInput && input1, const DigitalInput & input2)
    : OrInput(input1.move_clone(), true, &input2, false)
  {
  }

  OrInput(const DigitalInput & input1, const DigitalInput && input2)
    : OrInput(&input1, false, input2.move_clone(), true)
  {
  }

  OrInput(const DigitalInput && input1, const DigitalInput && input2)
    : OrInput(input1.move_clone(), true, input2.move_clone(), true)
  {
  }

  virtual ~OrInput() override
  {
    if (owning1)
      delete input1;
    if (owning2)
      delete input2;
  }

  virtual OrInput * move_clone() const override
  {
    return new OrInput(owning1 ? input1->move_clone() : input1, owning1,
                        owning2 ? input2->move_clone() : input2, owning2);
  }

  virtual void begin() const override
  {
    input1->begin();
    input2->begin();
  }

  virtual bool get() const override
  {
    return input1->get() || input2->get();
  }
};

inline OrInput operator||(const DigitalInput & input1, const DigitalInput & input2)
{
  return OrInput(input1, input2);
}

inline OrInput operator||(const DigitalInput && input1, const DigitalInput && input2)
{
  return OrInput(mv(input1), mv(input2));
}
