#include "Light.h"

class FastLight : public Light
{
  int lightPin;
  bool lightOn;

public:
  FastLight(int lightPin, bool lightOn = false)
    : lightPin(lightPin)
    , lightOn(lightOn)
  {
  }

  virtual void begin() override
  {
    pinMode(lightPin, OUTPUT);
  }

  void set(bool lightOn)
  {
    this->lightOn = lightOn;
  }

  void update()
  {
    digitalWrite(lightPin, lightOn ? HIGH : LOW);
  }
};
