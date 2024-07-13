#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "Signal3Aspect.h"
#include "DistanceTimer.h"
#include "SlowLight.h"

#include "testSignal3Aspect.h"

const int triggerPin = 1;
const int greenPin = 2;
const int redPin = 3;
const int yellowPin = 4;

void testInitialState()
{
  test();
  clearArduinoValues();
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  signal.begin();

  assertEquals(PinMode::OUTPUT, getPinMode(greenPin));
  assertEquals(PinMode::OUTPUT, getPinMode(redPin));
  assertEquals(PinMode::OUTPUT, getPinMode(yellowPin));
  assertEquals(PinMode::INPUT_PULLUP, getPinMode(triggerPin));

  distanceTimer.update();
  signal.update();

  assertEquals(255, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testUpdate_Initial_NoChange()
{
  test();
  clearArduinoValues();
  setDigitalRead(triggerPin, HIGH);
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());

  distanceTimer.update();
  signal.update();

  assertEquals(255, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testUpdate_Initial_ToRed()
{
  test();
  clearArduinoValues();
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());

  setDigitalRead(triggerPin, LOW);
  distanceTimer.update();
  signal.update();

  // Still at beginning of interval so lights have not changed yet.
  assertEquals(255, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testUpdate_Initial_ToRedAtEnd()
{
  test();
  clearArduinoValues();
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());

  setDigitalRead(triggerPin, LOW);
  distanceTimer.update();
  signal.update(); // Transitions to TO_RED, lights have not yet changed.

  assertEquals(255, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));

  addMillis(defaultTransitionInterval);
  setDigitalRead(triggerPin, HIGH);
  distanceTimer.update();
  signal.update(); // End of TO_RED. Lights have changed.
  
  assertEquals(0, getAnalogWrite(greenPin));
  assertEquals(255, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testUpdate_ToRed_Red()
{
  test();
  clearArduinoValues();
  setDigitalRead(triggerPin, HIGH);
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());
  distanceTimer.update();
  signal.update();

  addMillis(defaultTransitionInterval + 1);
  distanceTimer.update();
  signal.update();

  assertEquals(0, getAnalogWrite(greenPin));
  assertEquals(255, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testUpdate_Red_ToYellow()
{
  test();
  clearArduinoValues();
  setDigitalRead(triggerPin, HIGH);
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());
  distanceTimer.update();
  signal.update();

  addMillis(interval + 1);
  distanceTimer.update();
  signal.update();

  // Still at beginning of interval so lights have not changed yet.
  assertEquals(0, getAnalogWrite(greenPin));
  assertEquals(255, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testUpdate_ToYellowAtEnd()
{
  test();
  clearArduinoValues();
  setDigitalRead(triggerPin, HIGH);
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());
  distanceTimer.update();
  signal.update();

  // Transition to beginning of Yellow, but lights have not changed yet.
  addMillis(interval + 1);
  distanceTimer.update();
  signal.update();

  // Transition to end of light change. Lights have changed to Yellow.
  addMillis(defaultTransitionInterval + 1);
  distanceTimer.update();
  signal.update();
  
  assertEquals(0, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(255, getAnalogWrite(yellowPin));
}

void testUpdate_Yellow_ToGreen()
{
  test();
  clearArduinoValues();
  setDigitalRead(triggerPin, HIGH);
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());
  distanceTimer.update();
  signal.update();

  // Transition to beginning of Yellow, but lights have not changed yet.
  addMillis(interval + 1);
  distanceTimer.update();
  signal.update();

  // Transition to end of light change. Lights have changed to Yellow.
  addMillis(defaultTransitionInterval + 1);
  distanceTimer.update();
  signal.update();
  
  // Transition to beginning of Green, but lights have not changed yet.
  addMillis(2 * interval + 1);
  distanceTimer.update();
  signal.update();

  // Still at beginning of interval so lights have not changed yet.
  assertEquals(0, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(255, getAnalogWrite(yellowPin));
}

void testUpdate_ToGreenAtEnd()
{
  test();
  clearArduinoValues();
  setDigitalRead(triggerPin, HIGH);
  DistanceTimer distanceTimer(triggerPin);
  SlowLight greenLight(greenPin, true);
  SlowLight redLight(redPin, false);
  SlowLight yellowLight(yellowPin, false);
  Signal3Aspect signal(distanceTimer, greenLight, redLight, yellowLight);
  distanceTimer.setTimer(millis());
  distanceTimer.update();
  signal.update();

  // Transition to beginning of Green, but lights have not changed yet.
  addMillis(2 * interval + 1);
  distanceTimer.update();
  signal.update();

  // Transition to end of light change. Lights have changed to Green.
  addMillis(defaultTransitionInterval + 1);
  distanceTimer.update();
  signal.update();
  
  assertEquals(255, getAnalogWrite(greenPin));
  assertEquals(0, getAnalogWrite(redPin));
  assertEquals(0, getAnalogWrite(yellowPin));
}

void testSignal3Aspect()
{
  testInitialState();
  testUpdate_Initial_NoChange();
  testUpdate_Initial_ToRed();
  testUpdate_Initial_ToRedAtEnd();
  testUpdate_ToRed_Red();
  testUpdate_Red_ToYellow();
  testUpdate_ToYellowAtEnd();
  testUpdate_Yellow_ToGreen();
  testUpdate_ToGreenAtEnd();
}
