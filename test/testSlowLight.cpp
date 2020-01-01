#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "SlowLight.h"

#include "testSlowLight.h"

const int greenPin = 2;

void testSlowSignal_Off_Start()
{
  test();
  clearArduinoValues();
  SlowLight light(greenPin, false);

  // First, set it to ON and let it take effect
  light.set(true);
  addMillis(transitionInterval + 1);
  light.update();
  
  // Then set to OFF
  light.set(false);
  light.update();

  //should not yet be off.
  assertEquals(255, getAnalogWrite(greenPin));
}

void testSlowSignal_Off_End()
{
  test();
  clearArduinoValues();
  SlowLight light(greenPin, false);
  light.set(false);
  addMillis(transitionInterval + 1);

  light.update();

  assertEquals(0, getAnalogWrite(greenPin));
}

void testSlowSignal_On_Start()
{
  test();
  clearArduinoValues();
  SlowLight light(greenPin, false);

  // First, set it to OFF and let it take effect
  light.set(false);
  addMillis(transitionInterval + 1);
  light.update();
  
  // Then set to ON
  light.set(true);
  light.update();

  // should not yet be lit up.
  assertEquals(0, getAnalogWrite(greenPin));
}

void testSlowSignal_On_End()
{
  test();
  clearArduinoValues();
  SlowLight light(greenPin, false);
  light.set(true);
  addMillis(transitionInterval + 1);

  light.update();

  assertEquals(255, getAnalogWrite(greenPin));
}

void testSlowSignal_ChangeWhileChanging()
{
  test();
  clearArduinoValues();
  SlowLight light(greenPin, false);

  // First, set it to OFF and let it take effect
  light.set(false);
  addMillis(transitionInterval + 1);
  light.update();
  
  // Then set to ON and wait half-way.
  light.set(true);
  addMillis(transitionInterval / 2);
  light.update();
  assertEquals(127, getAnalogWrite(greenPin));

  // Finally set it to OFF again and it should soon have effect.
  light.set(false);
  addMillis(transitionInterval / 2);
  light.update();
  assertEquals(0, getAnalogWrite(greenPin));
}

void testSlowLight()
{
  testSlowSignal_Off_Start();
  testSlowSignal_Off_End();
  testSlowSignal_On_Start();
  testSlowSignal_On_End();
  testSlowSignal_ChangeWhileChanging();
}
