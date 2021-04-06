#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "SettableInput.h"
#include "InvertInput.h"
#include "BlockDistanceInput.h"
#include "DistanceWithCondition.h"
#include "DistanceChoice.h"

// This tests various track layouts where the number of free blocks depends on trailing and facing blocks.
// This tests combinations of DistanceInput objects.

// S1      T1       T2
// ---B1---+---B2---+---B3----
//        /          \        .
// S2    /            \       .
// --B4-+-----B5-------+--B6--
//      T4             T5
namespace
{
  SettableInput block1;
  SettableInput block2;
  SettableInput block3;
  SettableInput block4;
  SettableInput block5;
  SettableInput block6;
  SettableInput turnout1;
  SettableInput turnout2;
  SettableInput turnout4;
  SettableInput turnout5;

  BlockDistanceInput route3(block3);
  BlockDistanceInput route6(block6);

  InvertInput turnout5i(turnout5);
  DistanceWithCondition cond5i(route6, turnout5i);
  DistanceChoice choice2(turnout2, route3, cond5i);
  BlockDistanceInput route2(block2, choice2);
  DistanceWithCondition cond5(route6, turnout5);
  BlockDistanceInput route5(block5, cond5);

  DistanceWithCondition cond1(route2, turnout1);
  BlockDistanceInput route1(block1, cond1);
  InvertInput turnout1i(turnout1);
  DistanceWithCondition cond1i(route2, turnout1i);
  DistanceChoice choice4(turnout4, route5, cond1i);
  BlockDistanceInput route4(block4, choice4);

  void clearInputs()
  {
    block1.set(false);
    block2.set(false);
    block3.set(false);
    block4.set(false);
    block5.set(false);
    block6.set(false);
    turnout1.set(false);
    turnout2.set(false);
    turnout4.set(false);
    turnout5.set(false);
  }

  void updateRoutes()
  {
    route3.update();
    route6.update();
    route2.update();
    route5.update();
    route1.update();
    route4.update();
  }

  void testAllClear()
  {
    test();
    clearArduinoValues();
    clearInputs();

    updateRoutes();
    assertEquals(99, route1.freeBlocks());
    assertEquals(99, route4.freeBlocks());
  }

  void testStopAtFirst()
  {
    test();
    clearArduinoValues();
    clearInputs();

    block1.set(true);
    block4.set(true);

    updateRoutes();
    assertEquals(0, route1.freeBlocks());
    assertEquals(0, route4.freeBlocks());
  }

  void testStopAtSecond()
  {
    test();
    clearArduinoValues();
    clearInputs();

    block2.set(true);
    block5.set(true);

    updateRoutes();
    assertEquals(1, route1.freeBlocks());
    assertEquals(1, route4.freeBlocks());
  }

  void testStopAtThird()
  {
    test();
    clearArduinoValues();
    clearInputs();

    block3.set(true);
    block6.set(true);

    updateRoutes();
    assertEquals(2, route1.freeBlocks());
    assertEquals(2, route4.freeBlocks());
  }

  void testCrossoverLeft()
  {
    test();
    clearArduinoValues();
    clearInputs();

    turnout1.set(true);
    turnout4.set(true);

    updateRoutes();
    assertEquals(1, route1.freeBlocks());
    assertEquals(99, route4.freeBlocks());
  }

  void testCrossoverLeftStopAtThird()
  {
    test();
    clearArduinoValues();
    clearInputs();

    turnout1.set(true);
    turnout4.set(true);
    block3.set(true);

    updateRoutes();
    assertEquals(1, route1.freeBlocks());
    assertEquals(2, route4.freeBlocks());
  }

  void testCrossoverRight()
  {
    test();
    clearArduinoValues();
    clearInputs();

    turnout2.set(true);
    turnout5.set(true);

    updateRoutes();
    assertEquals(99, route1.freeBlocks());
    assertEquals(2, route4.freeBlocks());
  }

  void testCrossoverRightStopAtThird()
  {
    test();
    clearArduinoValues();
    clearInputs();

    turnout2.set(true);
    turnout5.set(true);
    block6.set(true);

    updateRoutes();
    assertEquals(2, route1.freeBlocks());
    assertEquals(2, route4.freeBlocks());
  }

}

void testBlockTopologies()
{
  testAllClear();
  testStopAtFirst();
  testStopAtSecond();
  testStopAtThird();
  testCrossoverLeft();
  testCrossoverLeftStopAtThird();
  testCrossoverRight();
  testCrossoverRightStopAtThird();
}
