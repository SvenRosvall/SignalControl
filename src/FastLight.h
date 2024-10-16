#include "Light.h"

class FastLight : public Light
{
  int lightPin;
  bool lightOn;

public:
  explicit FastLight(int lightPin, bool lightOn = false)
    : lightPin(lightPin)
    , lightOn(lightOn)
  {
  }

  FastLight(int lightPin, CommonPolarity polarity, bool lightOn = false)
    : Light(polarity)
    , lightPin(lightPin)
    , lightOn(lightOn)
  {
  }

  virtual void begin() override
  {
    pinMode(lightPin, OUTPUT);
  }

  virtual void set(bool lightOn) override
  {
    this->lightOn = lightOn;
  }

  virtual void update() override
  {
    digitalWrite(lightPin, ((commonPolarity == COMMON_CATHODE) == lightOn) ? HIGH : LOW);
  }
};
