#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "SettableInput.h"
#include "testSettableInput.h"

void testSettableInput_InitDefault()
{
  test();
  clearArduinoValues();
  SettableInput settableInput;

  assertEquals(false, settableInput.get());
}

void testSettableInput_InitFalse()
{
  test();
  clearArduinoValues();
  SettableInput settableInput(false);

  assertEquals(false, settableInput.get());
}

void testSettableInput_InitTrue()
{
  test();
  clearArduinoValues();
  SettableInput settableInput(true);

  assertEquals(true, settableInput.get());
}

void testSettableInput_FromFalse()
{
  test();
  clearArduinoValues();
  SettableInput settableInput;

  settableInput.set(false);
  assertEquals(false, settableInput.get());
}

void testSettableInput_FromTrue()
{
  test();
  clearArduinoValues();
  SettableInput settableInput;

  settableInput.set(true);
  assertEquals(true, settableInput.get());
}

void testSettableInput()
{
  testSettableInput_InitDefault();
  testSettableInput_InitFalse();
  testSettableInput_InitTrue();
  testSettableInput_FromFalse();
  testSettableInput_FromTrue();
}
