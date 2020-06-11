#include "Light.h"
#include "DigitalInput.h"
#include "DistanceInput.h"
#include "DistanceToDigitalInput.h"

class Signal2Aspect
{
  const DigitalInput & input;
  Light & greenLight;
  Light & redLight;

public:
  Signal2Aspect(const DigitalInput & input,
         Light & greenLight,
         Light & redLight)
    : input(input)
    , greenLight(greenLight)
    , redLight(redLight)
  {
  }

  Signal2Aspect(const DistanceInput & distanceInput,
         Light & greenLight,
         Light & redLight)
    : Signal2Aspect(DistanceToDigitalInput(distanceInput)
           , greenLight
           , redLight)
  {
  }

  void update()
  {
    if (input.get())
    {
      greenLight.set(true);
      redLight.set(false);
    }
    else
    {
      redLight.set(true);
      greenLight.set(false);
    }
    greenLight.update();
    redLight.update();
  }
};
