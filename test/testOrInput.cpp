#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "OrInput.h"
#include "testOrInput.h"

#include "MockInput.h"
#include "InvertInput.h"

void testOrInput_Create()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  
  OrInput orInput {mockInput1, mockInput2};
  orInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testOrInput_CreateWithTemporaries()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  // Use InvertInput here to create temporaries.
  OrInput orInput {InvertInput(mockInput1), InvertInput(mockInput2)};
  orInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testOrInput_CreateWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  OrInput orInput = mockInput1 || mockInput2;
  orInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testOrInput_CreateWithOperatorOrTemporaries()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  OrInput orInput = InvertInput(mockInput1) || InvertInput(mockInput2);
  orInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testOrInput_Moved()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;

  InvertInput invertInput = InvertInput(OrInput(mockInput1, mockInput2));
  invertInput.begin();

  assertEquals(true, mockInput1.wasBeginCalled());
  assertEquals(true, mockInput2.wasBeginCalled());
}

void testOrInput_BothFalse()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  OrInput orInput(mockInput1, mockInput2);

  mockInput1.set(false);
  mockInput2.set(false);
  assertEquals(false, orInput.get());
}

void testOrInput_BothFalseWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  OrInput orInput = mockInput1 || mockInput2;

  mockInput1.set(false);
  mockInput2.set(false);
  assertEquals(false, orInput.get());
}

void testOrInput_BothTrue()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  OrInput orInput(mockInput1, mockInput2);

  mockInput1.set(true);
  mockInput2.set(true);
  assertEquals(true, orInput.get());
}

void testOrInput_BothTrueWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  OrInput orInput = mockInput1 || mockInput2;

  mockInput1.set(true);
  mockInput2.set(true);
  assertEquals(true, orInput.get());
}

void testOrInput_TrueOrFalse()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  OrInput orInput(mockInput1, mockInput2);

  mockInput1.set(true);
  mockInput2.set(false);
  assertEquals(true, orInput.get());
}

void testOrInput_TrueOrFalseWithOperator()
{
  test();
  MockInput mockInput1;
  MockInput mockInput2;
  OrInput orInput = mockInput1 || mockInput2;

  mockInput1.set(true);
  mockInput2.set(false);
  assertEquals(true, orInput.get());
}

void testOrInput()
{
  testOrInput_Create();
  testOrInput_CreateWithTemporaries();
  testOrInput_CreateWithOperator();
  testOrInput_CreateWithOperatorOrTemporaries();
  testOrInput_Moved();
  testOrInput_BothFalse();
  testOrInput_BothFalseWithOperator();
  testOrInput_BothTrue();
  testOrInput_BothTrueWithOperator();
  testOrInput_TrueOrFalse();
  testOrInput_TrueOrFalseWithOperator();
}
