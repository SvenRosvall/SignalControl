#include "Signal3Aspect.h"
#include "BlockDistanceInput.h"
#include "SlowLight.h"

BlockDistanceInput distanceinput(7, 8);

// 3,5,6,9,10,11 can be used for PWM output.

SlowLight greenLight(3);
SlowLight redLight(5, true);
SlowLight yellowLight(6);
Signal3Aspect signal(distanceinput, greenLight, redLight, yellowLight);

void setup()
{}

void loop()
{
  signal.update();
}
