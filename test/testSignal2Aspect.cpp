#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "Signal2Aspect.h"
#include "DistanceTimer.h"
#include "SlowLight.h"

#include "testSignal2Aspect.h"

namespace
{
  const int triggerPin = 1;
  const int greenPin = 2;
  const int redPin = 3;

  void testInitialState()
  {
    test();
    clearArduinoValues();
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(DistanceTimer(triggerPin), greenLight, redLight);

    assertEquals(PinMode::OUTPUT, getPinMode(greenPin));
    assertEquals(PinMode::OUTPUT, getPinMode(redPin));
    assertEquals(PinMode::INPUT_PULLUP, getPinMode(triggerPin));

    signal.update();

    assertEquals(255, getAnalogWrite(greenPin));
    assertEquals(0, getAnalogWrite(redPin));
  }

  void testUpdate_Initial_NoChange()
  {
    test();
    clearArduinoValues();
    setDigitalRead(triggerPin, HIGH);
    DistanceTimer distanceTimer(triggerPin);
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(distanceTimer, greenLight, redLight);
    distanceTimer.setTimer(millis());

    distanceTimer.update();
    signal.update();

    assertEquals(255, getAnalogWrite(greenPin));
    assertEquals(0, getAnalogWrite(redPin));
  }

  void testUpdate_Initial_ToRed()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(distanceTimer, greenLight, redLight);
    distanceTimer.setTimer(millis());

    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();
    signal.update();

    // Still at beginning of interval so lights have not changed yet.
    assertEquals(255, getAnalogWrite(greenPin));
    assertEquals(0, getAnalogWrite(redPin));
  }

  void testUpdate_Initial_ToRedAtEnd()
  {
    test();
    clearArduinoValues();
    DistanceTimer distanceTimer(triggerPin);
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(distanceTimer, greenLight, redLight);
    distanceTimer.setTimer(millis());

    setDigitalRead(triggerPin, LOW);
    distanceTimer.update();
    signal.update(); // Transitions to TO_RED, lights have not yet changed.

    assertEquals(255, getAnalogWrite(greenPin));
    assertEquals(0, getAnalogWrite(redPin));

    addMillis(defaultTransitionInterval);
    setDigitalRead(triggerPin, HIGH);
    distanceTimer.update();
    signal.update(); // End of TO_RED. Lights have changed.

    assertEquals(0, getAnalogWrite(greenPin));
    assertEquals(255, getAnalogWrite(redPin));
  }

  void testUpdate_ToRed_Red()
  {
    test();
    clearArduinoValues();
    setDigitalRead(triggerPin, HIGH);
    DistanceTimer distanceTimer(triggerPin);
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(distanceTimer, greenLight, redLight);
    distanceTimer.setTimer(millis());
    distanceTimer.update();
    signal.update();

    addMillis(defaultTransitionInterval + 1);
    distanceTimer.update();
    signal.update();

    assertEquals(0, getAnalogWrite(greenPin));
    assertEquals(255, getAnalogWrite(redPin));
  }

  void testUpdate_Red_ToGreen()
  {
    test();
    clearArduinoValues();
    setDigitalRead(triggerPin, HIGH);
    DistanceTimer distanceTimer(triggerPin);
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(distanceTimer, greenLight, redLight);
    distanceTimer.setTimer(millis());
    distanceTimer.update();
    signal.update();

    addMillis(interval + 1);
    distanceTimer.update();
    signal.update();

    // Still at beginning of interval so lights have not changed yet.
    assertEquals(0, getAnalogWrite(greenPin));
    assertEquals(255, getAnalogWrite(redPin));
  }

  void testUpdate_ToGreenAtEnd()
  {
    test();
    clearArduinoValues();
    setDigitalRead(triggerPin, HIGH);
    DistanceTimer distanceTimer(triggerPin);
    SlowLight greenLight(greenPin, true);
    SlowLight redLight(redPin, false);
    Signal2Aspect signal(distanceTimer, greenLight, redLight);
    distanceTimer.setTimer(millis());
    distanceTimer.update();
    signal.update();

    // Transition to beginning of Green, but lights have not changed yet.
    addMillis(interval + 1);
    distanceTimer.update();
    signal.update();

    // Transition to end of light change. Lights have changed to Green.
    addMillis(defaultTransitionInterval + 1);
    distanceTimer.update();
    signal.update();

    assertEquals(255, getAnalogWrite(greenPin));
    assertEquals(0, getAnalogWrite(redPin));
  }
}

void testSignal2Aspect()
{
  testInitialState();
  testUpdate_Initial_NoChange();
  testUpdate_Initial_ToRed();
  testUpdate_Initial_ToRedAtEnd();
  testUpdate_ToRed_Red();
  testUpdate_Red_ToGreen();
  testUpdate_ToGreenAtEnd();
}
