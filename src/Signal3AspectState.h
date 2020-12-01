#include "Light.h"
#include "DistanceInput.h"

class Signal3AspectState
{
  const DistanceInput & distanceInput;
  Light & greenLight;
  Light & redLight;
  Light & yellowLight;
  unsigned int state;

public:
  Signal3AspectState(const DistanceInput & distanceInput,
         Light & greenLight,
         Light & redLight,
         Light & yellowLight, unsigned int s)
    : distanceInput(distanceInput)
    , greenLight(greenLight)
    , redLight(redLight)
    , yellowLight(yellowLight)
    , state(s)
  {
  }
  void update()
  {
    switch (distanceInput.freeBlocks())
    {
    case 0:
      //Serial.println("state=RED");
      redLight.set(true);
      greenLight.set(false);
      yellowLight.set(false);
      state = 0;
      break;

    case 1:
      //Serial.println("state=YELLOW");        
      yellowLight.set(true);
      greenLight.set(false);
      redLight.set(false);
      state = 1;
      break;

    default:
      //Serial.println("state=GREEN");
      greenLight.set(true);
      redLight.set(false);
      yellowLight.set(false);
      state = 2;
      break;
    }
    greenLight.update();
    redLight.update();
    yellowLight.update();
  }
  void update_state(unsigned int st)
  {
    unsigned int sw;
    if (distanceInput.freeBlocks()== 0) { sw = 0; }
    else { sw = st; }
    switch (sw)
    {
    case 0:
      //Serial.println("state=RED");
      redLight.set(true);
      greenLight.set(false);
      yellowLight.set(false);
      state = 0;
      break;

    case 1:
      //Serial.println("state=YELLOW");        
      yellowLight.set(true);
      greenLight.set(false);
      redLight.set(false);
      state = 1;
      break;

    default:
      //Serial.println("state=GREEN");
      greenLight.set(true);
      redLight.set(false);
      yellowLight.set(false);
      state = 2;
      break;
    }
    greenLight.update();
    redLight.update();
    yellowLight.update();
  }

  unsigned int get_state() { return state; }
  void set_state(unsigned int s) { state = s; }
};
