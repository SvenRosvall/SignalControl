#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "InvertInput.h"
#include "testInvertInput.h"

#include "MockInput.h"

void testInvertInput_FromFalse()
{
  test();
  clearArduinoValues();
  MockInput mockInput;
  InvertInput invertInput(mockInput);

  mockInput.set(false);
  assertEquals(true, invertInput.get());
}

void testInvertInput_FromTrue()
{
  test();
  clearArduinoValues();
  MockInput mockInput;
  InvertInput invertInput(mockInput);

  mockInput.set(true);
  assertEquals(false, invertInput.get());
}

void testInvertInput()
{
  testInvertInput_FromFalse();
  testInvertInput_FromTrue();
}
