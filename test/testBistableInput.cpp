#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"
#include "MockInput.h"

#include "BistableInput.h"

#include "testBistableInput.h"

namespace
{

MockInput mockOnInput;
MockInput mockOffInput;

BistableInput createBistableInput()
{
  mockOnInput.set(false);
  mockOffInput.set(false);
  BistableInput pinInput(mockOnInput, mockOffInput);
  pinInput.begin();

  return pinInput;
}

void testBistableInput_PinInput_setup()
{
  static const int inputOnPin = 3;
  static const int inputOffPin = 4;

  test();
  clearArduinoValues();
  BistableInput pinInput(inputOnPin, inputOffPin);
  pinInput.begin();
  // Set default pin states
  setDigitalRead(inputOnPin, HIGH);
  setDigitalRead(inputOffPin, HIGH);

  assertEquals(PinMode::INPUT_PULLUP, getPinMode(inputOnPin));
  assertEquals(PinMode::INPUT_PULLUP, getPinMode(inputOffPin));

  assertEquals(false, pinInput.get());
}

void testBistableInput_setOn()
{
  test();
  clearArduinoValues();
  BistableInput pinInput = createBistableInput();

  mockOnInput.set(true);
  assertEquals(true, pinInput.get());

  // remains on when on-pin is inactive
  mockOnInput.set(false);
  assertEquals(true, pinInput.get());
}

void testBistableInput_setOff()
{
  test();
  clearArduinoValues();
  BistableInput pinInput = createBistableInput();

  // Force state to on
  mockOnInput.set(true);
  assertEquals(true, pinInput.get());

  // remains on when on-pin is inactive
  mockOnInput.set(false);
  assertEquals(true, pinInput.get());

  // set off
  mockOffInput.set(true);
  assertEquals(false, pinInput.get());

  // remains on when on-pin is inactive
  mockOffInput.set(false);
  assertEquals(false, pinInput.get());
}

}

void testBistableInput()
{
  testBistableInput_PinInput_setup();
  testBistableInput_setOn();
  testBistableInput_setOff();
}
