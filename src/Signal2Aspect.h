#include "Light.h"
#include "DistanceInput.h"

class Signal2Aspect
{
  const DistanceInput & distanceInput;
  Light & greenLight;
  Light & redLight;

public:
  Signal2Aspect(const DistanceInput & distanceInput,
         Light & greenLight,
         Light & redLight)
    : distanceInput(distanceInput)
    , greenLight(greenLight)
    , redLight(redLight)
  {
  }

  void update()
  {
    switch (distanceInput.freeBlocks())
    {
    case 0:
      Serial.println("state=RED");
      redLight.set(true);
      greenLight.set(false);
      break;

    default:
      Serial.println("state=GREEN");
      greenLight.set(true);
      redLight.set(false);
      break;
    }
    greenLight.update();
    redLight.update();
  }
};
