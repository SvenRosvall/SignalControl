#ifndef DigitalInput_H
#define DigitalInput_H

class DigitalInput
{
public:
  virtual ~DigitalInput() {}
  virtual DigitalInput * move_clone() const = 0;
  virtual void begin() const = 0;
  virtual bool get() const = 0;
};

#endif
