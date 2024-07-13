#include "Signal3Aspect.h"
#include "DistanceTimer.h"
#include "SlowLight.h"

DistanceTimer distanceTimer1(2);
DistanceTimer distanceTimer2(8);

// 3,5,6,9,10,11 can be used for PWM output.
SlowLight greenLight1(3);
SlowLight redLight1(5, true);
SlowLight yellowLight1(6);
Signal3Aspect signal1(distanceTimer1, greenLight1, redLight1, yellowLight1);

SlowLight greenLight2(9);
SlowLight redLight2(10, true);
SlowLight yellowLight2(11);
Signal3Aspect signal2(distanceTimer2, greenLight2, redLight2, yellowLight2);

void setup() 
{
  signal1.begin();
  signal2.begin();
}

void loop() 
{
  distanceTimer1.update();
  distanceTimer2.update();
  signal1.update();
  signal2.update();
}
