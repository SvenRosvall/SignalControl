#include "Light.h"
//#include "BlinkingLight.h"
#include "DistanceInput.h"

class SignalFyrSken
{
  const DistanceInput & distanceInput;
  Light & greenLight;
  Light & redLight;
  Light & greenLight2;
  Light & whiteLight;

public:
  SignalFyrSken(const DistanceInput & distanceInput,
         Light & greenLight,
         Light & redLight,
         Light & greenLight2,
         Light & whiteLight)
    : distanceInput(distanceInput)
    , greenLight(greenLight)
    , redLight(redLight)
    , greenLight2(greenLight2)
    , whiteLight(whiteLight)
  {
  }

  void begin()
  {
    greenLight.begin();
    redLight.begin();
    greenLight2.begin();
    whiteLight.begin();
  }

  void update()
  {
    switch (distanceInput.freeBlocks())
    {
    case 0:
      redLight.set(true);
      greenLight.set(false);
      greenLight2.set(false);
      whiteLight.set(false);
      break;

    case 1:
      greenLight.set(true);
      greenLight2.set(true);
      whiteLight.set(false);
      redLight.set(false);
      break;

    default:
      greenLight.set(true);
      whiteLight.set(true);
      redLight.set(false);
      greenLight2.set(false);
      break;
    }
    greenLight.update();
    redLight.update();
    greenLight2.update();
    whiteLight.update();
  }
};
