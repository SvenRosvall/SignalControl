#include "Light.h"

class FastLight : public Light
{
  int lightPin;
  bool lightOn;

public:
  FastLight(int lightPin, bool lightOn)
    : lightPin(lightPin)
    , lightOn(lightOn)
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
