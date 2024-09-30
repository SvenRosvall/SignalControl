#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "TwoPinInput.h"

#include "testTwoPinInput.h"

static const int inputOnPin = 3;
static const int inputOffPin = 4;

TwoPinInput createTwoPinInput()
{
  TwoPinInput pinInput(inputOnPin, inputOffPin);
  pinInput.begin();
  // Set default pin states
  setDigitalRead(inputOnPin, HIGH);
  setDigitalRead(inputOffPin, HIGH);
  return pinInput;
}

void testTwoPinInput_setup()
{
  test();
  clearArduinoValues();
  TwoPinInput pinInput = createTwoPinInput();

  assertEquals(PinMode::INPUT_PULLUP, getPinMode(inputOnPin));
  assertEquals(PinMode::INPUT_PULLUP, getPinMode(inputOffPin));

  assertEquals(false, pinInput.get());
}

void testTwoPinInput_setOn()
{
  test();
  clearArduinoValues();
  TwoPinInput pinInput = createTwoPinInput();

  setDigitalRead(inputOnPin, LOW);
  assertEquals(true, pinInput.get());

  // remains on when on-pin is inactive
  setDigitalRead(inputOnPin, HIGH);
  assertEquals(true, pinInput.get());
}

void testTwoPinInput_setOff()
{
  test();
  clearArduinoValues();
  TwoPinInput pinInput = createTwoPinInput();

  // Force state to on
  setDigitalRead(inputOnPin, LOW);
  assertEquals(true, pinInput.get());

  // remains on when on-pin is inactive
  setDigitalRead(inputOnPin, HIGH);
  assertEquals(true, pinInput.get());
  
  // set off
  setDigitalRead(inputOffPin, LOW);
  assertEquals(false, pinInput.get());

  // remains on when on-pin is inactive
  setDigitalRead(inputOffPin, HIGH);
  assertEquals(false, pinInput.get());
}

void testTwoPinInput()
{
  testTwoPinInput_setup();
  testTwoPinInput_setOn();
  testTwoPinInput_setOff();
}
