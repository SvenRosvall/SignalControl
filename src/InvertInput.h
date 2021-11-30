#ifndef InvertInput_H
#define InvertInput_H

#include "DigitalInput.h"
#include "mv.h"

class InvertInput : public DigitalInput
{
  DigitalInput * input;
  bool owning;

private:
  InvertInput(DigitalInput * input, bool owning)
    : input(input), owning(owning)
  {
  }
public:
  InvertInput(DigitalInput & input)
    : input(&input), owning(false)
  {
  }

  InvertInput(DigitalInput && input)
    : input(input.move_clone()), owning(true)
  {
  }

  // TODO?? I don't understand why this copy constructor is needed.
  // Why isn't the ctors from DigitalInput enough?
  // And yet it doesn't work as it is elided.
  InvertInput(InvertInput & input)
    : input(&input), owning(false)
  {
  }

  InvertInput(InvertInput && input)
    : input(input.move_clone()), owning(true)
  {
  }

  ~InvertInput()
  {
    if (owning)
      delete input;
  }

  virtual InvertInput * move_clone()
  {
    return new InvertInput(owning ? input->move_clone() : input, owning);
  }

  virtual bool get() const
  {
    return !input->get();
  }
};


inline InvertInput operator!(DigitalInput & input)
{
  return InvertInput(input);
}

inline InvertInput operator!(DigitalInput && input)
{
  return InvertInput(mv(input));
}
#endif
