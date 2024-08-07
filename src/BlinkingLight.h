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

  void set(bool lightOn)
  {
    this->lightOn = lightOn;
  }

  virtual void begin() override
  {
    light.begin();
  }

  void update()
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
