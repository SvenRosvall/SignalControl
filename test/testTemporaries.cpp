#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "AndInput.h"
#include "InvertInput.h"
#include "testTemporaries.h"

#include "MockInput.h"

void testInvertAndInputTemporaries()
{
  test();
  clearArduinoValues();

  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput{InvertInput(mockInput1), InvertInput(mockInput2)};

  mockInput1.set(false); mockInput2.set(false);
  assertEquals(true, andInput.get());

  mockInput1.set(false); mockInput2.set(true);
  assertEquals(false, andInput.get());

  mockInput1.set(true); mockInput2.set(false);
  assertEquals(false, andInput.get());

  mockInput1.set(true); mockInput2.set(true);
  assertEquals(false, andInput.get());
}

void testInvertAndOperator()
{
  test();
  clearArduinoValues();

  MockInput mockInput1;
  MockInput mockInput2;
  DigitalInput && andInput = !mockInput1 && !mockInput2;

  mockInput1.set(false); mockInput2.set(false);
  assertEquals(true, andInput.get());

  mockInput1.set(false); mockInput2.set(true);
  assertEquals(false, andInput.get());

  mockInput1.set(true); mockInput2.set(false);
  assertEquals(false, andInput.get());

  mockInput1.set(true); mockInput2.set(true);
  assertEquals(false, andInput.get());
}

void testInvertInvertInputTemporaries()
{
  test();
  clearArduinoValues();

  MockInput mockInput1;
  // Note: Must cast to DigitalInput. Otherwise the InvertInput copy ctor
  // will be used which will be elided.
  InvertInput invertInput{(DigitalInput&&)InvertInput(mockInput1)};

  mockInput1.set(false);
  assertEquals(false, invertInput.get());

  mockInput1.set(true);
  assertEquals(true, invertInput.get());
}

void testInvertInvertOperator()
{
  test();
  clearArduinoValues();

  MockInput mockInput1;
  DigitalInput && invertInput = !!mockInput1;

  mockInput1.set(false);
  assertEquals(false, invertInput.get());

  mockInput1.set(true);
  assertEquals(true, invertInput.get());
}

void testTemporaries()
{
  testInvertAndInputTemporaries();
  testInvertInvertInputTemporaries();
  testInvertAndOperator();
  testInvertInvertOperator();
}
