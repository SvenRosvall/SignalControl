#include "Arduino.hpp"
#include "TestTools.hpp"

namespace
{

void testBits()
{
  test();

  assertEquals(1, bitRead(0x33, 4));
  assertEquals(0, bitRead(0x33, 3));
}

void testMap()
{
        test();

        assertEquals(100, map(10, 10, 20, 100, 200));
        assertEquals(200, map(20, 10, 20, 100, 200));
}

}

void testArduino()
{
  testBits();
  testMap();
}
