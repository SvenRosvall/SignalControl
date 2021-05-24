#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "AndInput.h"
#include "testAndInput.h"

#include "MockInput.h"

void testAndInput_BothFalse()
{
  test();
  clearArduinoValues();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput(mockInput1, mockInput2);

  mockInput1.set(false);
  mockInput2.set(false);
  assertEquals(false, andInput.get());
}

void testAndInput_BothTrue()
{
  test();
  clearArduinoValues();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput(mockInput1, mockInput2);

  mockInput1.set(true);
  mockInput2.set(true);
  assertEquals(true, andInput.get());
}

void testAndInput_TrueAndFalse()
{
  test();
  clearArduinoValues();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput(mockInput1, mockInput2);

  mockInput1.set(true);
  mockInput2.set(false);
  assertEquals(false, andInput.get());
}

void testAndInput()
{
  testAndInput_BothFalse();
  testAndInput_BothTrue();
  testAndInput_TrueAndFalse();
}
