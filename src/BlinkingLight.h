#include "Light.h"

const long blinkingInterval = 1000;

class BlinkingLight : public Light
{
  Light & light;
  bool lightOn;

public:
  BlinkingLight(Light & light, bool lightOn = false)
    : light(light)
    , lightOn(lightOn)
  {
    this->light.set(lightOn);
  }

  void set(bool lightOn)
  {
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
