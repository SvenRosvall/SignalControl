#include "Light.h"

const long defaultBlinkingInterval = 1000;

class BlinkingLight : public Light
{
  Light & light;
  bool lightOn;
  long blinkingInterval;

public:
  BlinkingLight(Light & light, bool lightOn = false)
    : BlinkingLight(light, defaultBlinkingInterval, lightOn)
  {
  }

  BlinkingLight(Light & light, long blinkingInterval, bool lightOn = false)
    : light(light)
    , lightOn(lightOn)
    , blinkingInterval(blinkingInterval)
  {
    this->light.set(lightOn);
  }

  virtual void set(bool lightOn) override
  {
    this->lightOn = lightOn;
  }

  virtual void begin() override
  {
    light.begin();
  }

  virtual void update() override
  {
    if (lightOn && ((millis() / blinkingInterval) % 2) == 1)
    {
      light.set(true);
    }
    else
    {
      light.set(false);
    }
    light.update();
  }
};
