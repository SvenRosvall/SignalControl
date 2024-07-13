#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "Signal3Aspect.h"
#include "DistanceInput.h"
#include "Light.h"

#include "MockDistanceInput.h"

class MockLight : public Light
{
  bool isLightOn;

public:
  virtual void begin() override
  {}

  virtual void set(bool lightOn)
  {
    isLightOn = lightOn;
  }

  virtual void update()
  {
  }

  bool getLight() const
  {
    return isLightOn;
  }
};

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

    assertEquals(false, greenLight.getLight());
    assertEquals(true, redLight.getLight());
    assertEquals(false, yellowLight.getLight());
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

    assertEquals(false, greenLight.getLight());
    assertEquals(false, redLight.getLight());
    assertEquals(true, yellowLight.getLight());
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

    assertEquals(true, greenLight.getLight());
    assertEquals(false, redLight.getLight());
    assertEquals(false, yellowLight.getLight());
  }
}

void testSignalUnitTest()
{
  test0FreeBlocks();
  test1FreeBlocks();
  test2FreeBlocks();
}

