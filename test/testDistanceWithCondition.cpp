#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "DistanceWithCondition.h"

#include "testDistanceWithCondition.h"
#include "MockDistanceInput.h"
#include "MockInput.h"

namespace
{
  void testNear()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistance;
    MockInput mockInput;
    DistanceWithCondition distanceTimer(mockDistance, mockInput);

    // Set to a known state.
    mockDistance.setFreeBlocks(0);
    mockInput.set(false);

    assertEquals(0, distanceTimer.freeBlocks());
  }
 
  void testOneBlockAway()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistance;
    MockInput mockInput;
    DistanceWithCondition distanceTimer(mockDistance, mockInput);

    // Set to a known state.
    mockDistance.setFreeBlocks(1);
    mockInput.set(false);

    assertEquals(1, distanceTimer.freeBlocks());
  }
 
  void testTwoBlockAway()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistance;
    MockInput mockInput;
    DistanceWithCondition distanceTimer(mockDistance, mockInput);

    // Set to a known state.
    mockDistance.setFreeBlocks(2);
    mockInput.set(false);

    assertEquals(2, distanceTimer.freeBlocks());
  }
 
  void testThreeBlockAway()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistance;
    MockInput mockInput;
    DistanceWithCondition distanceTimer(mockDistance, mockInput);

    // Set to a known state.
    mockDistance.setFreeBlocks(3);
    mockInput.set(false);

    assertEquals(3, distanceTimer.freeBlocks());
  }
 
  void testBlocked()
  {
    test();
    clearArduinoValues();
    MockDistanceInput mockDistance;
    MockInput mockInput;
    DistanceWithCondition distanceTimer(mockDistance, mockInput);

    // Set to a known state.
    mockDistance.setFreeBlocks(2);
    mockInput.set(true);

    assertEquals(0, distanceTimer.freeBlocks());
  }
}

void testDistanceWithCondition()
{
  testNear();
  testOneBlockAway();
  testTwoBlockAway();
  testThreeBlockAway();
  testBlocked();
}
