#include "Light.h"
#include <Adafruit_PWMServoDriver.h>

class FastPWMLight : public Light
{
  Adafruit_PWMServoDriver &pwm;
  uint8_t lightPin;
  bool lightOn;

public:
  FastPWMLight(Adafruit_PWMServoDriver &pwm,uint8_t lightPin,   bool lightOn)
    : pwm(pwm)
    , lightPin(lightPin)
    , lightOn(lightOn)
  {
    // NO action in constructor as the pwm will not yet be on.
    //update();
    //pinMode(lightPin, OUTPUT);
  }

  void set(bool lightOn)
  {
    this->lightOn = lightOn;
  }

  void update()
  {
   if(lightOn) {
     pwm.setPWM(lightPin,4096,0);  // pwm.setPin(pwmnum,0)
   } else {
     pwm.setPWM(lightPin,0,4096);  // pwm.setPin(pwmnum,4096)
   }
  }
};
