#include "Arduino.hpp"
#include "ArduinoMock.hpp"
#include "TestTools.hpp"

#include "BlinkingLight.h"
#include "testBlinkingLight.h"

class MockLight : public Light
{
  bool lightOn;

public:
  void set(bool lightOn)
  {
    this->lightOn = lightOn;
  }
  void update()
  {
  }
  bool isLightOn()
  {
    return lightOn;
  }
};

void testBlinkingSignal_Off_Start()
{
  test();
  clearArduinoValues();
  MockLight mockLight;
  BlinkingLight light(mockLight, false);

  // First, set it to ON and let it take effect
  light.set(true);
  addMillis(blinkingInterval + 1);
  light.update();
  
  // Then set to OFF
  light.set(false);
  light.update();

  //should not yet be off.
  assertEquals(false, mockLight.isLightOn());
}

void testBlinkingSignal_Off_End()
{
  test();
  clearArduinoValues();
  MockLight mockLight;
  BlinkingLight light(mockLight, false);
  light.set(false);
  addMillis(blinkingInterval + 1);

  light.update();

  assertEquals(false, mockLight.isLightOn());
}

void testBlinkingSignal_On_Start()
{
  test();
  clearArduinoValues();
  MockLight mockLight;
  BlinkingLight light(mockLight, false);

  // First, set it to OFF and let it take effect
  light.set(false);
  light.update();
  
  // Then set to ON
  light.set(true);
  light.update();

  // should not yet be lit up.
  assertEquals(false, mockLight.isLightOn());
}

void testBlinkingSignal_On_End()
{
  test();
  clearArduinoValues();
  MockLight mockLight;
  BlinkingLight light(mockLight, false);
  light.set(true);
  addMillis(blinkingInterval + 1);

  light.update();

  assertEquals(true, mockLight.isLightOn());
}

void testBlinkingSignal_ChangeWhileChanging()
{
  test();
  clearArduinoValues();
  MockLight mockLight;
  BlinkingLight light(mockLight, false);

  // First, set it to OFF and let it take effect
  light.set(false);
  light.update();
  
  // Then set to ON and wait half-way.
  light.set(true);
  addMillis(blinkingInterval / 2);
  light.update();
  assertEquals(false, mockLight.isLightOn());

  // Finally set it to OFF again and it should soon have effect.
  light.set(false);
  addMillis(blinkingInterval / 2 + 1);
  light.update();
  assertEquals(false, mockLight.isLightOn());
}

void testBlinkingLight()
{
  testBlinkingSignal_Off_Start();
  testBlinkingSignal_Off_End();
  testBlinkingSignal_On_Start();
  testBlinkingSignal_On_End();
  testBlinkingSignal_ChangeWhileChanging();
}
