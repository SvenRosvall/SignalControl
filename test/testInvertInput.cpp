#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "InvertInput.h"
#include "testInvertInput.h"

#include "MockInput.h"

void testInvertInput_Create()
{
  test();
  MockInput mockInput1;

  InvertInput invertInput {mockInput1};
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
}

void testInvertInput_CreateWithTemporaries()
{
  test();
  MockInput mockInput1;

  // Use InvertInput here to create temporaries.
  InvertInput invertInput {InvertInput(mockInput1)};
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
}

void testInvertInput_CreateWithOperator()
{
  test();
  MockInput mockInput1;

  InvertInput invertInput = !mockInput1;
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
}

void testInvertInput_CreateWithOperatorAndTemporaries()
{
  test();
  MockInput mockInput1;

  InvertInput invertInput = !InvertInput(mockInput1);
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
}

void testInvertInput_Moved()
{
  test();
  MockInput mockInput1;

  InvertInput invertInput = InvertInput(InvertInput(mockInput1));
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
}

void testInvertInput_FromFalse()
{
  test();
  clearArduinoValues();
  MockInput mockInput;
  InvertInput invertInput(mockInput);

  mockInput.set(false);
  assertEquals(true, invertInput.get());
}

void testInvertInput_FromFalseWithOperator()
{
  test();
  clearArduinoValues();
  MockInput mockInput;
  InvertInput invertInput = !mockInput;

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

void testInvertInput_FromTrueWithOperator()
{
  test();
  clearArduinoValues();
  MockInput mockInput;
  InvertInput invertInput = !mockInput;

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

void testInvertInvertInputWithOperator()
{
  test();
  clearArduinoValues();

  MockInput mockInput;
  InvertInput invertInput = !!mockInput;

  mockInput.set(false);
  assertEquals(false, invertInput.get());

  mockInput.set(true);
  assertEquals(true, invertInput.get());
}

void testInvertInput()
{
  testInvertInput_Create();
  testInvertInput_CreateWithTemporaries();
  testInvertInput_CreateWithOperator();
  testInvertInput_CreateWithOperatorAndTemporaries();
  testInvertInput_Moved();
  testInvertInput_FromFalse();
  testInvertInput_FromFalseWithOperator();
  testInvertInput_FromTrue();
  testInvertInput_FromTrueWithOperator();
  testInvertInvertInput();
  testInvertInvertInputWithOperator();
}
