#ifndef Light_H
#define Light_H

class Light
{
public:
  virtual void set(bool lightOn) = 0;
  virtual void update() = 0;
};

#endif
