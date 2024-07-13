//
// Created by sven on 13/07/2024.
//

#pragma once

#include "Light.h"

class MockLight : public Light
{
  bool lightOn;

public:
  virtual void begin() override
  {}

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
