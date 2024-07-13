#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "Signal3Aspect.h"
#include "DistanceInput.h"
#include "Light.h"

#include "MockDistanceInput.h"
#include "MockLight.h"

namespace
{
  void test0FreeBlocks()
  {
    test();
    MockDistanceInput distanceInput;
    distanceInput.setFreeBlocks(0);
    MockLight greenLight;
    MockLight redLight;
    MockLight yellowLight;
    Signal3Aspect signal(distanceInput, greenLight, redLight, yellowLight);
    signal.begin();

    signal.update();

    assertEquals(false, greenLight.isLightOn());
    assertEquals(true, redLight.isLightOn());
    assertEquals(false, yellowLight.isLightOn());
  }

  void test1FreeBlocks()
  {
    test();
    MockDistanceInput distanceInput;
    distanceInput.setFreeBlocks(1);
    MockLight greenLight;
    MockLight redLight;
    MockLight yellowLight;
    Signal3Aspect signal(distanceInput, greenLight, redLight, yellowLight);
    signal.begin();

    signal.update();

    assertEquals(false, greenLight.isLightOn());
    assertEquals(false, redLight.isLightOn());
    assertEquals(true, yellowLight.isLightOn());
  }

  void test2FreeBlocks()
  {
    test();
    MockDistanceInput distanceInput;
    distanceInput.setFreeBlocks(2);
    MockLight greenLight;
    MockLight redLight;
    MockLight yellowLight;
    Signal3Aspect signal(distanceInput, greenLight, redLight, yellowLight);
    signal.begin();

    signal.update();

    assertEquals(true, greenLight.isLightOn());
    assertEquals(false, redLight.isLightOn());
    assertEquals(false, yellowLight.isLightOn());
  }
}

void testSignalUnitTest()
{
  test0FreeBlocks();
  test1FreeBlocks();
  test2FreeBlocks();
}

