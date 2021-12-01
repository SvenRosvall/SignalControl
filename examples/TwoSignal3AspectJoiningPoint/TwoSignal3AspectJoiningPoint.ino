#include "Signal3Aspect.h"
#include "DistanceTimer.h"
#include "DistanceWithCondition.h"
#include "SlowLight.h"
#include "PinInput.h"
#include "InvertInput.h"

DistanceTimer distanceTimer(2);
PinInput pointInput(8);
DistanceWithCondition distanceTrack1(distanceTimer, !pointInput);
DistanceWithCondition distanceTrack2(distanceTimer, pointInput);

// 3,5,6,9,10,11 can be used for PWM output.
SlowLight greenLight1(3);
SlowLight redLight1(5, true);
SlowLight yellowLight1(6);
Signal3Aspect signal1(distanceTrack1, greenLight1, redLight1, yellowLight1);

SlowLight greenLight2(9);
SlowLight redLight2(10, true);
SlowLight yellowLight2(11);
Signal3Aspect signal2(distanceTrack2, greenLight2, redLight2, yellowLight2);

void setup() 
{}

void loop() 
{
  distanceTimer.update();
  signal1.update();
  signal2.update();
}

