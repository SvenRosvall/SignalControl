// KeypadInput.h

#include "DigitalInput.h"
#include <Keypad.h>

const long interval = 5 * 1000;

// Create KeypadInput
class KeypadInput : public DistanceInput {

  Keypad mykeypad;
  char triggerKey;
  unsigned long timer;
  unsigned int freeBlockCount;

public:
   KeypadInput(Keypad &mykeypad, char triggerKey)
    : mykeypad(mykeypad)
    , triggerKey(triggerKey)
    , timer(0)
    , freeBlockCount(0)
  {
    // Serial.println("Setup KeypadInput");
    //pinMode(triggerPin, INPUT_PULLUP);
  }

  void check()
  {
      Serial.print("Setup KeypadInput for ");
      Serial.println(triggerKey);      
  }
  
  void setTimer(unsigned long timer)
  {
    this->timer = timer;
  }

  void update()
  {
   char key = mykeypad.getKey();
   if (key){ 
       if (key == triggerKey)
       {
          //Serial.print("Detected trigger ");
          //Serial.println(key);
          timer = millis();
       }
   }
   freeBlockCount = (millis() - timer) / interval;
  }
  
  virtual unsigned int freeBlocks() const
  {
    return freeBlockCount;
  }
};

