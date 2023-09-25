# Feature requests and bugs.

## Review Signal responsibilities.
Signals should only be concerned with how to display an aspect.
Move the knowledge of number of free blocks into a "translator" object.

## Feathers
Indicates diverging routes.

Should light up when the signal is not red and a specified point
is set to a diverging route.

A signal can have several feathers.

How to make it easy to add a feather to any signal without having
to create permutations of all combinations? 

## Review CANSIG design for ideas
CANSIG uses a set of flags that control the signal.
If any flags in the red set is set, signal shows red.
Otherwise, if any flags in the yellow set is set, signal shows yellow.
Otherwise, if any flags in the double yellow set is set, signal shows double yellow.
Otherwise, signal shows green.

Looks very flexible, but is it easy to use? 
Review a few examples.
Maybe a DistanceInput implementation could use this logic?

## Direct setting aspect
This is useful for usage by JMRI which calculates the distance itself.

This requires the separation of responsibilities above.

Suggestion is to create pure signal classes.
They implement one or more interfaces that describe infos (real-world statuses
such as clear/caution/stop and diverging-route and short-route)
of the signal (but not what to display them).
The signal then know how to display these infos.

We need a SignalTranslator class that translates e.g. DistanceInput into 
infos that the signals consume.

## Synchronized Flashing
Synchronized flashing of several signals that are in view of the train driver is 
important to reduce the risk of mistaking flashing lights for steady lights.
Signals connected to the same Arduino will have synchronized flashing lights in current version.

Flashing lights between multiple Arduinos can be synchronized by running a wire between them.
One Arduino is designated the controller and it emits the flash syncronization pulses. 
The other Arduinos will listen to these flash syncronization pulses and use them instead
of the internal clock to decide when to turn a flashing light on or off.

For implementations using a layout control bus (such as CBUS) it would be possible to 
replace this wire with a message that controls the flashing lights.

## Allow lights to be on / blinking / off
This requires the set() method to take an enum { ON, OFF, BLINK }. 
Only BlinkingLight will implement all three states. 

There are some cases where a light needs to be able to show any of these three states.
* New Zealand signalling uses fixed yellow for caution and blinking yellow for advanced caution.
* Swedish signalling uses a second green light that is fixed on for "go 40", and blinking 
  for "stop ahead".
* British signalling also uses flashing yellow for diverging route ahead.
