#include "Light.h"
#include "DistanceInput.h"

class Signal4Aspect
{
  const DistanceInput & distanceInput;
  Light & greenLight;
  Light & redLight;
  Light & yellowLight1;
  Light & yellowLight2;

public:
  Signal4Aspect(const DistanceInput & distanceInput,
         Light & greenLight,
         Light & redLight,
         Light & yellowLight1,
         Light & yellowLight2)
    : distanceInput(distanceInput)
    , greenLight(greenLight)
    , redLight(redLight)
    , yellowLight1(yellowLight1)
    , yellowLight2(yellowLight2)
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
      yellowLight1.set(false);
      yellowLight2.set(false);
      break;

    case 1:
      Serial.println("state=YELLOW");        
      yellowLight1.set(true);
      yellowLight2.set(false);
      greenLight.set(false);
      redLight.set(false);
      break;

    case 2:
      Serial.println("state=TWO YELLOW");        
      yellowLight1.set(true);
      yellowLight2.set(true);
      greenLight.set(false);
      redLight.set(false);
      break;

    default:
      Serial.println("state=GREEN");
      greenLight.set(true);
      redLight.set(false);
      yellowLight1.set(false);
      yellowLight2.set(false);
      break;
    }
    greenLight.update();
    redLight.update();
    yellowLight1.update();
    yellowLight2.update();
  }
};
