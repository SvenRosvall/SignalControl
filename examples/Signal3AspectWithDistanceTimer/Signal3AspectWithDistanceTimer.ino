#include "Signal3Aspect.h"
#include "DistanceTimer.h"
#include "SlowLight.h"

DistanceTimer distanceTimer(2);

// 3,5,6,9,10,11 can be used for PWM output.

SlowLight greenLight(3);
SlowLight redLight(5, true);
SlowLight yellowLight(6);
Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);

void setup()
{}

void loop()
{
  distanceTimer.update();
  signal.update();
}
