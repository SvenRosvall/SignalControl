# Feature requests and bugs.

## Don't use pin number directly.
Objects such as BlockDistanceInput should use PinInput
instead.
This helps abstracting away how sensor information is
arriving. 

This is necessary to replace pin input with CBUS events.

## Resetting DistanceTimer.
Currently triggered by a pin.
Should have a method to trigger the timer which can
be called from CBUS event handler.

Possibly follow the item above and use a DigitalInput
which can be a PinInput or an object that the event handler
can work with.

## Review Signal responsibilities.
Signals should only be concerned with how to display an aspect.
Move the knowledge of number of free blocks into a "translator" object.
