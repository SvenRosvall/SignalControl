#include "Signal2Aspect.h"
#include "PinInput.h"
#include "SlowLight.h"

PinInput button(2);

SlowLight greenLight(3);
SlowLight redLight(5);
Signal2Aspect signal(button, greenLight, redLight);

void setup()
{
  signal.begin();
}

void loop()
{
  signal.update();
}
