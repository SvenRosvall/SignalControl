#include "Light.h"
#include "DistanceInput.h"

class LinkedSignal3Aspect
{
  const DistanceInput & distanceInput;
  Light & greenLight1;
  Light & redLight1;
  Light & yellowLight1;
  Light & greenLight2;
  Light & redLight2;
  Light & yellowLight2;


public:
  LinkedSignal3Aspect(const DistanceInput & distanceInput,
         Light & greenLight1,
         Light & redLight1,
         Light & yellowLight1,
         Light & greenLight2,
         Light & redLight2,
         Light & yellowLight2)
    : distanceInput(distanceInput)
    , greenLight1(greenLight1)
    , redLight1(redLight1)
    , yellowLight1(yellowLight1) 
    , greenLight2(greenLight2)
    , redLight2(redLight2)
    , yellowLight2(yellowLight2)

  {
  }

  void update()
  {
    switch (distanceInput.freeBlocks())
    {
    case 0:
      //Serial.println("state=GREEN1 RED2");
      redLight1.set(false);
      greenLight1.set(true);
      yellowLight1.set(false);
      redLight2.set(true);
      greenLight2.set(false);
      yellowLight2.set(false);
       break;

    case 1:
      //Serial.println("state=RED1 YELLOW2");        
      redLight1.set(true);
      greenLight1.set(false);
      yellowLight1.set(false);
      greenLight2.set(false);
      redLight2.set(false);
      yellowLight2.set(true);
      break;

    default:
      //Serial.println("state=GREEN GREEN");
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
