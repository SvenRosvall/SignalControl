#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "Signal4Aspect.h"
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
    MockLight yellowLight1;
    MockLight yellowLight2;
    Signal4Aspect signal(distanceInput, greenLight, redLight, yellowLight1, yellowLight2);
    signal.begin();

    signal.update();

    assertEquals(false, greenLight.isLightOn());
    assertEquals(true, redLight.isLightOn());
    assertEquals(false, yellowLight1.isLightOn());
    assertEquals(false, yellowLight2.isLightOn());
  }

  void test1FreeBlocks()
  {
    test();
    MockDistanceInput distanceInput;
    distanceInput.setFreeBlocks(1);
    MockLight greenLight;
    MockLight redLight;
    MockLight yellowLight1;
    MockLight yellowLight2;
    Signal4Aspect signal(distanceInput, greenLight, redLight, yellowLight1, yellowLight2);

    signal.update();

    assertEquals(false, greenLight.isLightOn());
    assertEquals(false, redLight.isLightOn());
    assertEquals(true, yellowLight1.isLightOn());
    assertEquals(false, yellowLight2.isLightOn());
  }

  void test2FreeBlocks()
  {
    test();
    MockDistanceInput distanceInput;
    distanceInput.setFreeBlocks(2);
    MockLight greenLight;
    MockLight redLight;
    MockLight yellowLight1;
    MockLight yellowLight2;
    Signal4Aspect signal(distanceInput, greenLight, redLight, yellowLight1, yellowLight2);

    signal.update();

    assertEquals(false, greenLight.isLightOn());
    assertEquals(false, redLight.isLightOn());
    assertEquals(true, yellowLight1.isLightOn());
    assertEquals(true, yellowLight2.isLightOn());
  }
  
  void test3FreeBlocks()
  {
    test();
    MockDistanceInput distanceInput;
    distanceInput.setFreeBlocks(3);
    MockLight greenLight;
    MockLight redLight;
    MockLight yellowLight1;
    MockLight yellowLight2;
    Signal4Aspect signal(distanceInput, greenLight, redLight, yellowLight1, yellowLight2);

    signal.update();

    assertEquals(true, greenLight.isLightOn());
    assertEquals(false, redLight.isLightOn());
    assertEquals(false, yellowLight1.isLightOn());
    assertEquals(false, yellowLight2.isLightOn());
  }
}

void testSignal4Aspect()
{
  test0FreeBlocks();
  test1FreeBlocks();
  test2FreeBlocks();
  test3FreeBlocks();
}
