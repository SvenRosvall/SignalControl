#include "Arduino.hpp"
#include "TestTools.hpp"

void testMap()
{
        test();

        assertEquals(100, map(10, 10, 20, 100, 200));
        assertEquals(200, map(20, 10, 20, 100, 200));
}

void testArduino()
{
        testMap();
}
