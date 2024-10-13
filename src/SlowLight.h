#include "Light.h"

const long defaultTransitionInterval = 500;

class SlowLight : public Light
{
  int lightPin;
  long transitionInterval;
  bool lightOn;
  unsigned long timer;

public:
  explicit SlowLight(int lightPin, bool lightOn = false)
    : SlowLight(lightPin, defaultTransitionInterval, COMMON_CATHODE, lightOn)
  {}
  
  SlowLight(int lightPin, CommonPolarity polarity, bool lightOn = false)
    : SlowLight(lightPin, defaultTransitionInterval, polarity, lightOn)
  {}

  SlowLight(int lightPin, long transitionInterval, CommonPolarity polarity = COMMON_CATHODE, bool lightOn = false)
    : Light(polarity)
    , lightPin(lightPin)
    , transitionInterval(transitionInterval)
    , lightOn(lightOn)
    , timer(-transitionInterval)
  {
  }

  virtual void begin() override
  {
    pinMode(lightPin, OUTPUT);
  }

  virtual void set(bool lightOn) override
  {
    if (this->lightOn == lightOn)
    {
      // No change
      return;
    }

    this->lightOn = lightOn;

    unsigned long now = millis();
    if (now > timer + transitionInterval)
    {
      // Previous setting was fully achieved. Start timer from now.
      this->timer = now;
    }
    else
    {
      // Previous setting was not fully achieved. Fix timer to make transition
      // smooth.
      this->timer = now + (now - timer) - transitionInterval;
    }
  }

  virtual void update() override
  {
    unsigned long now = millis();
    int intensity;
    if (now > timer + transitionInterval)
    {
      intensity = ((commonPolarity == COMMON_CATHODE) == lightOn) ? 255 : 0;
    }
    else if ((commonPolarity == COMMON_CATHODE) == lightOn)
    {
      intensity = map(now - timer, 0, transitionInterval, 0, 255);
    }
    else
    {
      intensity = map(now - timer, 0, transitionInterval, 255, 0);
    }
    analogWrite(lightPin, intensity);
  }
};
