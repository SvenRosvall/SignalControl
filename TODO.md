# Feature requests and bugs.

## Review Signal responsibilities.
Signals should only be concerned with how to display an aspect.
Move the knowledge of number of free blocks into a "translator" object.

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
