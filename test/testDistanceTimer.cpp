#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "DistanceTimer.h"

namespace
{
  const int triggerPin = 1;

  void testInitialState()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);

    assertEquals(0, distanceTimer.freeBlocks());
  }

  void testTrigger()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);
    setDigitalRead(triggerPin, LOW);

    distanceTimer.update();
    
    assertEquals(0, distanceTimer.freeBlocks());
  }

  void testAlmostOneBlockAway()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);

    // Set to a known state.
    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();

    setDigitalRead(triggerPin, HIGH);
    addMillis(interval - 1);
    distanceTimer.update();

    assertEquals(0, distanceTimer.freeBlocks());
  }
  
  void testOneBlockAway()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);

    // Set to a known state.
    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();

    setDigitalRead(triggerPin, HIGH);
    addMillis(interval);
    distanceTimer.update();

    assertEquals(1, distanceTimer.freeBlocks());
  }

  void testTwoBlockAway()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);

    // Set to a known state.
    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();

    setDigitalRead(triggerPin, HIGH);
    addMillis(2 * interval);
    distanceTimer.update();

    assertEquals(2, distanceTimer.freeBlocks());
  }

  void testThreeBlockAway()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);

    // Set to a known state.
    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();

    setDigitalRead(triggerPin, HIGH);
    addMillis(3 * interval);
    distanceTimer.update();

    assertEquals(3, distanceTimer.freeBlocks());
  }

  void testAnotherTrigger()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);

    // Set to a known state.
    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();

    setDigitalRead(triggerPin, HIGH);
    addMillis(3 * interval);
    distanceTimer.update();

    assertEquals(3, distanceTimer.freeBlocks());

    setDigitalRead(triggerPin, LOW);
    addMillis(1);
    distanceTimer.update();

    assertEquals(0, distanceTimer.freeBlocks());
  }
}

void testDistanceTimer()
{
  testInitialState();
  testTrigger();
  testAlmostOneBlockAway();
  testOneBlockAway();
  testTwoBlockAway();
  testThreeBlockAway();
  testAnotherTrigger();
}
