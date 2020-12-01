#include "Light.h"
#include <Adafruit_PWMServoDriver.h>

const long transitionInterval = 500;

class SlowPWMLight : public Light
{
  Adafruit_PWMServoDriver &pwm;
  int lightPin;
  bool lightOn;
  unsigned long timer;

public:
  SlowPWMLight(Adafruit_PWMServoDriver &pwm,int lightPin,
               bool lightOn = false)
    : lightPin(lightPin)
    , lightOn(lightOn)
    , timer(0)
  {
    //pinMode(lightPin, OUTPUT);
  }

  void set(bool lightOn)
  {
    if (this->lightOn == lightOn)
    {
      // No change
      return;
    }

    this->lightOn = lightOn;

    unsigned long now = millis();
    if (now > timer + transitionInterval)
    {
      // Previous setting was fully achieved. Start timer from now.
      this->timer = now;
    }
    else
    {
      // Previous setting was not fully achieved. Fix timer to make transition
      // smooth.
      this->timer = now + (now - timer) - transitionInterval;
    }
  }

  void update()
  {
    unsigned long now = millis();
    int intensity;
    if (now > timer + transitionInterval)
    { // Fully on or fully off.
      if(lightOn == HIGH) {
         pwm.setPWM(lightPin,4096,0);
      } else {
         pwm.setPWM(lightPin,0,4096);  
      }
    } else {
       if (lightOn)
       {
         intensity = map(now - timer, 0, transitionInterval, 0,    4095);
       } else {
          intensity = map(now - timer, 0, transitionInterval, 4095, 0);
       }
      pwm.setPWM(lightPin,0,intensity);  
    }
  }
};
