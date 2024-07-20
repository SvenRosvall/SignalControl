#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "AndInput.h"
#include "testAndInput.h"

#include "MockInput.h"
#include "InvertInput.h"

void testAndInput_Create()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  
  AndInput andInput {mockInput1, mockInput2};
  andInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testAndInput_CreateWithTemporaries()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  // Use InvertInput here to create temporaries.
  AndInput andInput {InvertInput(mockInput1), InvertInput(mockInput2)};
  andInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testAndInput_CreateWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  AndInput andInput = mockInput1 && mockInput2;
  andInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testAndInput_CreateWithOperatorAndTemporaries()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  AndInput andInput = InvertInput(mockInput1) && InvertInput(mockInput2);
  andInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testAndInput_Moved()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  InvertInput invertInput = InvertInput(AndInput(mockInput1, mockInput2));
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testAndInput_BothFalse()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput(mockInput1, mockInput2);

  mockInput1.set(false);
  mockInput2.set(false);
  assertEquals(false, andInput.get());
}

void testAndInput_BothFalseWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput = mockInput1 && mockInput2;

  mockInput1.set(false);
  mockInput2.set(false);
  assertEquals(false, andInput.get());
}

void testAndInput_BothTrue()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput(mockInput1, mockInput2);

  mockInput1.set(true);
  mockInput2.set(true);
  assertEquals(true, andInput.get());
}

void testAndInput_BothTrueWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput = mockInput1 && mockInput2;

  mockInput1.set(true);
  mockInput2.set(true);
  assertEquals(true, andInput.get());
}

void testAndInput_TrueAndFalse()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput(mockInput1, mockInput2);

  mockInput1.set(true);
  mockInput2.set(false);
  assertEquals(false, andInput.get());
}

void testAndInput_TrueAndFalseWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  AndInput andInput = mockInput1 && mockInput2;

  mockInput1.set(true);
  mockInput2.set(false);
  assertEquals(false, andInput.get());
}

void testAndInput()
{
  testAndInput_Create();
  testAndInput_CreateWithTemporaries();
  testAndInput_CreateWithOperator();
  testAndInput_CreateWithOperatorAndTemporaries();
  testAndInput_Moved();
  testAndInput_BothFalse();
  testAndInput_BothFalseWithOperator();
  testAndInput_BothTrue();
  testAndInput_BothTrueWithOperator();
  testAndInput_TrueAndFalse();
  testAndInput_TrueAndFalseWithOperator();
}
