#ifndef InvertInput_H
#define InvertInput_H

#include "DigitalInput.h"
#include "mv.h"

class InvertInput : public DigitalInput
{
  const DigitalInput * input;
  bool owning;

private:
  InvertInput(const DigitalInput * input, bool owning)
    : input(input), owning(owning)
  {
  }
public:
  InvertInput(const DigitalInput & input)
    : input(&input), owning(false)
  {
  }

  InvertInput(const DigitalInput && input)
    : input(input.move_clone()), owning(true)
  {
  }

  // TODO?? I don't understand why this copy constructor is needed.
  // Why isn't the ctors from DigitalInput enough?
  // And yet it doesn't work as it is elided.
  InvertInput(const InvertInput & input)
    : input(&input), owning(false)
  {
  }

  InvertInput(const InvertInput && input)
    : input(input.move_clone()), owning(true)
  {
  }

  ~InvertInput()
  {
    if (owning)
      delete input;
  }

  virtual InvertInput * move_clone() const
  {
    return new InvertInput(owning ? input->move_clone() : input, owning);
  }

  virtual void begin() const override
  {
    input->begin();
  }

  virtual bool get() const
  {
    return !input->get();
  }
};


inline InvertInput operator!(const DigitalInput & input)
{
  return InvertInput(input);
}

inline InvertInput operator!(const DigitalInput && input)
{
  return InvertInput(mv(input));
}
#endif
