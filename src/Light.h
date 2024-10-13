#ifndef Light_H
#define Light_H

enum CommonPolarity
{
  COMMON_CATHODE,
  COMMON_ANODE
};
class Light
{
protected:
  CommonPolarity commonPolarity;

public:
  explicit Light(CommonPolarity polarity = COMMON_CATHODE)
    : commonPolarity(polarity)
  {}
  virtual void set(bool lightOn) = 0;
  virtual void begin() = 0; /// Called from setup() to set up hardware things.
  virtual void update() = 0;
};

#endif
