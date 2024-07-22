#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "DistanceToDigitalInput.h"
#include "MockDistanceInput.h"
#include "InvertInput.h"

namespace
{
  void testDistanceToDigitalInput_Create()
  {
    test();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);
    input.begin();

    assertEquals(true, mockDistanceInput.wasBeginCalled());
  }

  void testDistanceToDigitalInput_Moved()
  {
    test();
    MockDistanceInput mockDistanceInput;
    InvertInput invertInput = InvertInput(DistanceToDigitalInput(mockDistanceInput));
    invertInput.begin();
  
    assertEquals(true, mockDistanceInput.wasBeginCalled());
  }

  void testDistance0()
  {
    test();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);
    input.begin();

    assertEquals(false, input.get());
  }

  void testDistance1()
  {
    test();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);
    input.begin();

    assertEquals(false, input.get());
  }
  
  void testDistance2()
  {
    test();
    MockDistanceInput mockDistanceInput;
    DistanceToDigitalInput input(mockDistanceInput);
    input.begin();

    assertEquals(false, input.get());
  }
}

void testDistanceToDigitalInput()
{
  testDistanceToDigitalInput_Create();
  testDistanceToDigitalInput_Moved();
  testDistance0();
  testDistance1();
  testDistance2();
}
