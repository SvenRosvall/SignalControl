#include "Light.h"

const long blinkingInterval = 1000;

class BlinkingLight : public Light
{
  Light & light;
  bool lightOn;
  unsigned long timer;

public:
  BlinkingLight(Light & light, bool lightOn)
    : light(light)
    , lightOn(lightOn)
    , timer(0)
  {
    this->light.set(lightOn);
  }

  void set(bool lightOn)
  {
    if (this->lightOn == lightOn)
    {
      // No change
      return;
    }

    this->lightOn = lightOn;
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
