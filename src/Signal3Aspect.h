#include "Light.h"
#include "DistanceInput.h"

class Signal3Aspect
{
  const DistanceInput & distanceInput;
  Light & greenLight;
  Light & redLight;
  Light & yellowLight;

public:
  Signal3Aspect(const DistanceInput & distanceInput,
         Light & greenLight,
         Light & redLight,
         Light & yellowLight)
    : distanceInput(distanceInput)
    , greenLight(greenLight)
    , redLight(redLight)
    , yellowLight(yellowLight)
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
      yellowLight.set(false);
      break;

    case 1:
      Serial.println("state=YELLOW");        
      yellowLight.set(true);
      greenLight.set(false);
      redLight.set(false);
      break;

    default:
      Serial.println("state=GREEN");
      greenLight.set(true);
      redLight.set(false);
      yellowLight.set(false);
      break;
    }
    greenLight.update();
    redLight.update();
    yellowLight.update();
  }
};
