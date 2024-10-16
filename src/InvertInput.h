#ifndef InvertInput_H
#define InvertInput_H

#include "DigitalInput.h"
#include "mv.h"

class InvertInput : public DigitalInput
{
  const DigitalInput * input;
  const bool owning;

private:
  InvertInput(const DigitalInput * input, bool owning)
    : input(input), owning(owning)
  {
  }
public:
  explicit InvertInput(const DigitalInput & input)
    : InvertInput(&input, false)
  {
  }

  explicit InvertInput(const DigitalInput && input)
    : InvertInput(input.move_clone(), true)
  {
  }

  // TODO?? I don't understand why this copy constructor is needed.
  // Why isn't the ctors from DigitalInput enough?
  // And yet it doesn't work as it is elided.
  InvertInput(const InvertInput & input)
    : InvertInput(&input, false)
  {
  }

  InvertInput(const InvertInput && input) noexcept
    : InvertInput(input.move_clone(), true)
  {
  }

  ~InvertInput()
  {
    if (owning)
      delete input;
  }

  virtual InvertInput * move_clone() const override
  {
    return new InvertInput(owning ? input->move_clone() : input, owning);
  }

  virtual void begin() const override
  {
    input->begin();
  }

  virtual bool get() const override
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
