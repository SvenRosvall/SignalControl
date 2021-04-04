#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "DistanceChoice.h"

#include "testDistanceChoice.h"
#include "MockDistanceInput.h"
#include "MockInput.h"

namespace
{
  void testRoute1()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistanceRoute1;
    MockDistanceInput mockDistanceRoute2;
    MockInput mockInput;
    DistanceChoice testedDistance(mockInput, mockDistanceRoute1, mockDistanceRoute2);

    // Set to a known state.
    mockDistanceRoute1.setFreeBlocks(1);
    mockDistanceRoute2.setFreeBlocks(2);
    mockInput.set(false);

    assertEquals(1, testedDistance.freeBlocks());
  }

  void testRoute2()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistanceRoute1;
    MockDistanceInput mockDistanceRoute2;
    MockInput mockInput;
    DistanceChoice testedDistance(mockInput, mockDistanceRoute1, mockDistanceRoute2);

    // Set to a known state.
    mockDistanceRoute1.setFreeBlocks(1);
    mockDistanceRoute2.setFreeBlocks(2);
    mockInput.set(true);

    assertEquals(2, testedDistance.freeBlocks());
  }
}

void testDistanceChoice()
{
  testRoute1();
  testRoute2();
}
