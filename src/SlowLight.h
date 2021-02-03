#include "Light.h"

const long defaultTransitionInterval = 500;

class SlowLight : public Light
{
  int lightPin;
  long transitionInterval;
  bool lightOn;
  unsigned long timer;

public:
  SlowLight(int lightPin, bool lightOn = false)
    : SlowLight(lightPin, defaultTransitionInterval, lightOn)
  {
  }

  SlowLight(int lightPin, long transitionInterval, bool lightOn = false)
    : lightPin(lightPin)
    , transitionInterval(transitionInterval)
    , lightOn(lightOn)
    , timer(-transitionInterval)
  {
    pinMode(lightPin, OUTPUT);
  }

  void set(bool lightOn)
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

  void update()
  {
    unsigned long now = millis();
    int intensity;
    if (now > timer + transitionInterval)
    {
      intensity = lightOn ? 255 : 0;
    }
    else if (lightOn)
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
