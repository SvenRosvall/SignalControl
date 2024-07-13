#ifndef Light_H
#define Light_H

class Light
{
public:
  virtual void set(bool lightOn) = 0;
  virtual void begin() = 0; /// Called from setup() to set up hardware things.
  virtual void update() = 0;
};

#endif
