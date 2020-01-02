#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "DistanceToDigitalInput.h"
#include "MockDistanceInput.h"

namespace
{
  void testDistance0()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);

    assertEquals(false, input.get());
  }

  void testDistance1()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);

    assertEquals(false, input.get());
  }
  
  void testDistance2()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);

    assertEquals(false, input.get());
  }
}

void testDistanceToDigitalInput()
{
  testDistance0();
  testDistance1();
  testDistance2();
}
