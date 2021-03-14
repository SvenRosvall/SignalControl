#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "BlockDistanceInput.h"

namespace
{
  const int block1Pin = 1;
  const int block2Pin = 2;

  void testInitialState()
  {
    test();
    clearArduinoValues();
    BlockDistanceInput distanceInput(block1Pin, block2Pin);

    assertEquals(0, distanceInput.freeBlocks());
  }

  void testFirstBlockOccupied()
  {
    test();
    clearArduinoValues();
    BlockDistanceInput distanceInput(block1Pin, block2Pin);
    setDigitalRead(block1Pin, LOW);
    setDigitalRead(block2Pin, HIGH);

    distanceInput.update();
    
    assertEquals(0, distanceInput.freeBlocks());
  }

  void testOneBlockAway()
  {
    test();
    clearArduinoValues();
    BlockDistanceInput distanceInput(block1Pin, block2Pin);

    setDigitalRead(block1Pin, HIGH);
    setDigitalRead(block2Pin, LOW);
    distanceInput.update();

    assertEquals(1, distanceInput.freeBlocks());
  }

  void testManyBlockAway()
  {
    test();
    clearArduinoValues();
    BlockDistanceInput distanceInput(block1Pin, block2Pin);

    setDigitalRead(block1Pin, HIGH);
    setDigitalRead(block2Pin, HIGH);
    distanceInput.update();

    assertEquals(99, distanceInput.freeBlocks());
  }
}

void testBlockDistanceInput()
{
  testInitialState();
  testFirstBlockOccupied();
  testOneBlockAway();
  testManyBlockAway();
}
