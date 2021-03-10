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

For details see [design overview](Design.md).

For requested bug fixes and feature requests see [TODO](TODO.md).

## Using SignalControl Library

You need to ```#include``` each class you will use.

Objects are initialized when declared. 
There is no need to set up the objects in the ```setup()``` function.

Collaborative multitasking is used to keep all the objects updated all
the time.
The ```loop()``` function must call the ```update()``` method of each object.

### 2 Aspect Signal Controlled by a Button.

This first example shows a 2 aspect signal (only a red and a green light)
that is controlled by a push button connected to pin 2. 
Press the push button to change the aspect of the signal.
This uses the ```SlowLight``` class that changes the LED on and off 
softly by dimming the light.

The button can be replaced with a sensor on the layout that indicates
if the next block of track after the signal is free to enter, or
that a point (turnout) is set against the track with the signal. 

```
#include "Signal2Aspect.h"
#include "PinInput.h"
#include "SlowLight.h"

PinInput button(2);

SlowLight greenLight(3);
SlowLight redLight(5);
Signal2Aspect signal(button, greenLight, redLight);

void setup()
{}

void loop()
{
  signal.update();
}
```
The green LED is connected to pin 3 and the red LED is connected to pin 5.
These pins are PWM (Pulse Width Modulation) to support dimming of the LEDs.

The signal is declared and set up with the button and the two light objects.

No additional setup is needed and the ```loop()``` function is only
responsible for updating the button and signal objects. 
The Light objects do not need to be updated. 
They are updated by the signal object they belong to.

[Example Code](examples/Signal2AspectWithButton/Signal2AspectWithButton.ino)

## 3 Aspect Signal controlled by BlockDistanceInput.

Here we use a signal with 3 aspects (Red, Yellow, Green) that show oncoming
trains if
 * the next track block is occupied, in which case the signal shows red.
 * the next track block is free, but the following block is occupied.
   In this case the signal shows yellow.
 * the next two track blocks are free, in which case the signal shows green.
 
[Example Code](examples/Signal3AspectWithBlockDistanceInput/Signal3AspectWithBlockDistanceInput.ino)

## 3 Aspect Signal controlled by a DistanceTimer

Here we use a signal with 3 aspects and we introduce
a DistanceTimer class that is triggered by a track occupancy sensor on pin 2
and uses a timer to decide how far away the train is, and thus what 
colour the signal shall show.
 
[Example Code](examples/Signal3AspectWithDistanceTimer/Signal3AspectWithDistanceTimer.ino)

## Two independent 3 Aspect Signals

This example shows how a single Arduino can control two signals independently.
Here we use the Signal3Aspect class with the DistanceTimer as above.

[Example Code](examples/TwoIndependentSignal3Aspect/TwoIndependentSignal3Aspect.ino)

## Two 3 Aspect Signals controlling tracks that join a point (turnout)

Here we have two tracks that join at a point (turnout). 
The two signals control the approach to the point, which means that the
signal on the track that the point is set against must show red (danger).
We have one input from the point that indicates which way it is set.

We also have a track occupancy detector on the other side of point that
is used by the DistanceTimer.

[Example Code](examples/TwoSignal3AspectJoiningPoint/TwoSignal3AspectJoiningPoint.ino)
