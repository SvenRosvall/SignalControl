#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "FastLight.h"

#include "testFastLight.h"

const int greenPin = 2;

void testFastSignal_Off()
{
  test();
  clearArduinoValues();
  FastLight light(greenPin, false);

  // First, set it to ON and let it take effect
  light.set(true);
  light.update();
  
  // Then set to OFF
  light.set(false);
  light.update();

  //should be off.
  assertEquals(LOW, getDigitalWrite(greenPin));
}

void testFastSignal_On()
{
  test();
  clearArduinoValues();
  FastLight light(greenPin, false);

  // First, set it to OFF and let it take effect
  light.set(false);
  light.update();
  
  // Then set to ON
  light.set(true);
  light.update();

  // should be lit up.
  assertEquals(HIGH, getDigitalWrite(greenPin));
}

void testFastLight()
{
  testFastSignal_Off();
  testFastSignal_On();
}
