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

void testInvertInvertInput()
{
  test();
  clearArduinoValues();

  MockInput mockInput;
  InvertInput invertInput1(mockInput);
  InvertInput invertInput2(invertInput1);

  mockInput.set(false);
  assertEquals(true, invertInput1.get());
  assertEquals(false, invertInput2.get());

  mockInput.set(true);
  assertEquals(false, invertInput1.get());
  assertEquals(true, invertInput2.get());
}  

void testInvertInput()
{
  testInvertInput_FromFalse();
  testInvertInput_FromTrue();
  testInvertInvertInput();
}
