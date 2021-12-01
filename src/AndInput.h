#ifndef AndInput_H
#define AndInput_H

#include "DigitalInput.h"
#include "mv.h"

class AndInput : public DigitalInput
{
  const DigitalInput * input1;
  const DigitalInput * input2;
  bool owning1;
  bool owning2;

private:
  AndInput(const DigitalInput * input1, bool owning1,
           const DigitalInput * input2, bool owning2)
    : input1(input1), input2(input2)
    , owning1(owning1), owning2(owning2)
  {}

public:
  AndInput(const DigitalInput & input1, const DigitalInput & input2)
    : input1(&input1), input2(&input2)
    , owning1(false), owning2(false)
  {
  }

  AndInput(const DigitalInput && input1, const DigitalInput & input2)
    : input1(input1.move_clone()), input2(&input2)
    , owning1(true), owning2(false)
  {
  }

  AndInput(const DigitalInput & input1, const DigitalInput && input2)
    : input1(&input1), input2(input2.move_clone())
    , owning1(false), owning2(true)
  {
  }

  AndInput(const DigitalInput && input1, const DigitalInput && input2)
    : input1(input1.move_clone()), input2(input2.move_clone())
    , owning1(true), owning2(true)
  {
  }

  ~AndInput()
  {
    if (owning1)
      delete input1;
    if (owning2)
      delete input2;
  }

  virtual AndInput * move_clone() const
  {
    return new AndInput(owning1 ? input1->move_clone() : input1, owning1,
                        owning2 ? input2->move_clone() : input2, owning2);
  }

  virtual bool get() const
  {
    return input1->get() && input2->get();
  }
};

inline AndInput operator&&(const DigitalInput & input1, const DigitalInput & input2)
{
  return AndInput(input1, input2);
}

inline AndInput operator&&(const DigitalInput && input1, const DigitalInput && input2)
{
  return AndInput(mv(input1), mv(input2));
}

#endif
