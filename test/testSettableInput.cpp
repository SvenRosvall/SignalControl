#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "SettableInput.h"
#include "testSettableInput.h"
#include "InvertInput.h"

namespace
{
  void testSettableInput_Moved()
  {
    test();
    InvertInput invertInput = InvertInput(SettableInput());
    invertInput.begin();
    // Only testing code coverage.
  }
  
  void testSettableInput_InitDefault()
  {
    test();
    SettableInput settableInput;
    settableInput.begin();
  
    assertEquals(false, settableInput.get());
  }
  
  void testSettableInput_InitFalse()
  {
    test();
    SettableInput settableInput(false);
    settableInput.begin();
  
    assertEquals(false, settableInput.get());
  }
  
  void testSettableInput_InitTrue()
  {
    test();
    SettableInput settableInput(true);
    settableInput.begin();
  
    assertEquals(true, settableInput.get());
  }
  
  void testSettableInput_FromFalse()
  {
    test();
    SettableInput settableInput;
    settableInput.begin();
  
    settableInput.set(false);
    assertEquals(false, settableInput.get());
  }
  
  void testSettableInput_FromTrue()
  {
    test();
    SettableInput settableInput;
    settableInput.begin();
  
    settableInput.set(true);
    assertEquals(true, settableInput.get());
  }
}

void testSettableInput()
{
  testSettableInput_Moved();
  testSettableInput_InitDefault();
  testSettableInput_InitFalse();
  testSettableInput_InitTrue();
  testSettableInput_FromFalse();
  testSettableInput_FromTrue();
}
