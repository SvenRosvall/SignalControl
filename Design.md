# Design overview of SignalControl library

The SignalControl library is created with a set of interfaces
that describe its responsibility.
Interfaces are implemented by classes that implement this
responsibility. 
There may be multiple classes that implement the responsibility.

Each interface and its implementing classes is designed to have
only one responsibility. 
Anything indirectly related is delegated to objects defined by
an interface that describes the delegated responsiblities.

Example: The `Light` interface describes the responsibility
to show a single light. This light may be on, off or blinking.
Implementing classes define how this is done for example by 
representing an LED connected to an output pin. 

## Interface DigitalInput
Gets information somewhere and returns a digital answer.

### InvertInput
This inverts the result of a DigitalInput object.

Input:
* DigitalInput - The object to invert the result for.

### DistanceToDigitalInput
This converts the result of a DistanceInput object to
a digital answer. 
The result is true if the DistanceInput object returns at least
one unoccupied track block.

Input:
* DistanceInput - The object that keeps track of how many 
track blocks are free past the signal.

### PinInput
Returns the result of a digital input pin.
The pin is considered to have "Active LOW" logic, i.e. the returned
result is true if the pin is LOW.

Input:
* pin number : Pin to return the result for.

### SettableInput
Returns a state that can be set programmatically.

Input: 
* Initial state (default false)

## Interface DistanceInput
Returns the number of unoccupied track blocks. 
This is used by signals to decide which aspect to show.

Example: If there are no unoccupied track blocks a 0 is returned
telling the signal that it shall show stop/danger.

### DistanceWithCondition
Used when the track in advance of the signal has potential
obstacles such as a point set against the route ahead of the signal.

Inputs:
* DistanceInput - describes the number of unoccupied track blocks in
  advance of the signal in normal cases.
* DigitalInput - when this returns falls, makes the signal set to
  danger/stop.

### DistanceChoice
Used for facing points where the number of free blocks used by
the signal depends on the route selected by the point.

Inputs:
* DigitalInput - conditional input from the facing point.
* DistanceInput - normal route. This is the chosen route when the point
  is set to the normal route, i.e. the conditional input is false.
* DistanceInput - diverging route. This is the chosen route when the point
  is set to the diverging route, i.e. the conditional input is true. 

### BlockDistanceInput
Uses track sensors to determine how many track blocks are available.

Inputs: One of:
* Trigger and a DistanceInput.
  * Trigger is a DigitalInput object for the nearest block.
  * DistanceInput is an object representing the route in advance of
    the nearest block.
* One, two or three triggers. These triggers can be either:
  * pin numbers - number of input pin that is connected to the
    sensor for the each track block in advance of the signal.
  * DigitalInput - input objects for each track block.  

### DistanceTimer
Instead of counting the actual free blocks this class uses
a timer to simulate the number of blocks a passing train would
leave unoccupied as time passes.
This is a cheap solution as only one trigger is required.

Inputs:
* trigger - can be one of
  * DigitalInput - triggers the timer when object returns true.
  * pin - pin number that is connected to a sensor that 
detects a train that passes the signal. 
    Triggers the timer when the pin goes LOW.

## Interface Light
Responsible for handling each light in a signal.

### BlinkingLight
Implements blinking of a delegated `Light` object.

Inputs:
* Light - Another `Light` object that is delegated to.
* blink interval (default=1s)
* start state (default=false)

### FastLight
Implements a simple light that consists of an LED connected to 
an output pin.
The LED can be turned on or off.

Inputs:
* pin number - the pin the LED is connected to.
* on (default false) - should this LED be on at startup?

### SlowLight
Implements a light that consists of an LED connected to an 
output pin.
This implementation changes the LED slowly by using a PWM pin.


Inputs:
* pin number - the pin the LED is connected to.
* transition interval (default 500 ms) - Determines how long 
  it takes for the light to change to on or off.
* on (default false) - should this LED be on at startup?

## Interface Signal
Not implemented yet. 
Signal objects share no interface.

### Signal2Aspect
A 2 aspect signal.
Will show green or red depending on the input object.

Inputs:
* Input object. Can be one of:
  * DigitalInput - Show red if input is false and green if input is true.
  * DistanceInput - Shows red if there are 0 unoccupied tracks and green otherwise.
* green light - A Light object that shows a green light.
* red light - A Light object that shows a red light.

### Signal3Aspect
A 3 aspect signal.
Will show green, red or yellow depending on the DistanceInput
object.

Inputs:
* DistanceInput - Shows red if there are 0 unoccupied tracks and green otherwise.
* green light - A Light object that shows a green light.
* red light - A Light object that shows a red light.
* yellow light - A Light object that shows a yellow light.

### Signal4Aspect
A 4 aspect signal.
Will show green, red, yellow or double yellow depending on the
DistanceInput object.

Inputs:
* DistanceInput - Shows red if there are 0 unoccupied tracks and green otherwise.
* green light - A Light object that shows a green light.
* red light - A Light object that shows a red light.
* yellow light - A Light object that shows a yellow light.
* second yellow light - A Light object that shows a second yellow light.

### SignalFyrSken
Swedish four aspect signal.
Included here for pushing capabilities of the library to
some tricky aspects.
