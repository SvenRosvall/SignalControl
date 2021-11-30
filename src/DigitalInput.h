#ifndef DigitalInput_H
#define DigitalInput_H

class DigitalInput
{
public:
  virtual ~DigitalInput() {}
  virtual DigitalInput * move_clone() = 0;
  virtual bool get() const = 0;
};

#endif
