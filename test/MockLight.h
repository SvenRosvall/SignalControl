//
// Created by sven on 13/07/2024.
//

#pragma once

#include "Light.h"

class MockLight : public Light
{
  bool lightOn = false;
  mutable bool beginCalled = false;

public:
  virtual void begin() override
  {
    beginCalled = true;
  }

  bool wasBeginCalled() const
  {
    return beginCalled;
  }

  virtual void set(bool lightOn) override
  {
    this->lightOn = lightOn;
  }

  virtual void update() override
  {
  }

  bool isLightOn() const
  {
    return lightOn;
  }
};
