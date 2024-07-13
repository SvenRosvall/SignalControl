#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "Signal4Aspect.h"
#include "DistanceInput.h"
#include "Light.h"

#include "MockDistanceInput.h"

class MockLight : public Light
{
  bool isLightOn;

public:
  virtual void begin() override
  {
  }

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
    MockLight yellowLight1;
    MockLight yellowLight2;
    Signal4Aspect signal(distanceInput, greenLight, redLight, yellowLight1, yellowLight2);
    signal.begin();

    signal.update();

    assertEquals(false, greenLight.getLight());
    assertEquals(true, redLight.getLight());
    assertEquals(false, yellowLight1.getLight());
    assertEquals(false, yellowLight2.getLight());
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

    assertEquals(false, greenLight.getLight());
    assertEquals(false, redLight.getLight());
    assertEquals(true, yellowLight1.getLight());
    assertEquals(false, yellowLight2.getLight());
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

    assertEquals(false, greenLight.getLight());
    assertEquals(false, redLight.getLight());
    assertEquals(true, yellowLight1.getLight());
    assertEquals(true, yellowLight2.getLight());
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

    assertEquals(true, greenLight.getLight());
    assertEquals(false, redLight.getLight());
    assertEquals(false, yellowLight1.getLight());
    assertEquals(false, yellowLight2.getLight());
  }
}

void testSignal4Aspect()
{
  test0FreeBlocks();
  test1FreeBlocks();
  test2FreeBlocks();
  test3FreeBlocks();
}
