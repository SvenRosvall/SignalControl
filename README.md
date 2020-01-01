# SignalControl
An Arduino library for controlling LEDs in signals on a model railway.

Key features:
* Manages dimming and blinking LEDs.
* Encapsulate logic for signals.
* Support for interlocking.
* Highly configurable for your model railway layout.

## Overview 

The library is written in C++ but you do not need to understand C++ to use the library.
Good knowledge C++ is helpful if you want to understand or improve the library code.

The library contains a number of classes that represent different types
of signals. 
It also contains classes that represent different LED functionalities such
as blinking LEDs or dimming LEDs that emulate old incandescent bulbs.
There are also classes to help setting up rules for controlling the signals.

## Using SignalControl Library

You need to ```#include``` each class you will use.

Objects are initialized when declared. 
There is no need to set up the objects in the ```setup()``` function.

Collaborative multitasking is used to keep all the objects updated all
the time.
The ```loop()``` function must call the ```update()``` method of each object.

### 2 Aspect Signal Controlled by a Button.

```
#include "Signal.h"
#include "DigitalInput.h"
#include "SlowLight.h"

DigitalInput button(2);

SlowLight greenLight(3);
SlowLight redLight(5);
Signal2Aspect signal(button, greenLight, redLight);

void setup()
{}

void loop()
{
  button.update();
  signal.update();
}
```
Here we have a button connected to pin 2.
This is an input that provides a digital input (on or off).

The green LED is connected to pin 3 and the red LED is connected to pin 5.
These pins are PWM (Pulse Width Modulation) to support dimming of the LEDs.

The signal is declared and set up with the button and the two light objects.

No additional setup is needed and the ```loop()``` function is responsible
for updating the button and signal objects. 
The Light objects do not need to be updated. 
They are updated by the signal object they belong to.

**TODO**

Describe examples:
1) 2 aspect with a button input.
1) 2 aspect with track occupation input.

Note: Need a 2 aspect signal that can take a digital input and a distance input.
Or should we convert between these inputs?

**TODO** 

Get rid of initial state of Light classes. 
Use default if required.