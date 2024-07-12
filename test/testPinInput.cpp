#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "PinInput.h"

#include "testPinInput.h"

const int inputPin = 3;

void testPinInput_setup()
{
  test();
  clearArduinoValues();
  PinInput pinInput(inputPin);
  
  assertEquals(PinMode::INPUT_PULLUP, getPinMode(inputPin));
}

void testPinInput_HIGH()
{
  test();
  clearArduinoValues();
  PinInput pinInput(inputPin);

  setDigitalRead(inputPin, HIGH);
  assertEquals(false, pinInput.get());
}

void testPinInput_LOW()
{
  test();
  clearArduinoValues();
  PinInput pinInput(inputPin);

  setDigitalRead(inputPin, LOW);
  assertEquals(true, pinInput.get());
}

void testPinInput()
{
  testPinInput_setup();
  testPinInput_HIGH();
  testPinInput_LOW();
}
