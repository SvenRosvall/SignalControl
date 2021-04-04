# Feature requests and bugs.

## Review Signal responsibilities.
Signals should only be concerned with how to display an aspect.
Move the knowledge of number of free blocks into a "translator" object.

## Support 2 aperture, 4 aspect signals.
Modern 4 aspect signals have only two apertures (lights) where the lower
one can show green, red or yellow.

This can be implemented with NeoPixels.
See discussion in https://www.merg.org.uk/forum/viewtopic.php?f=120&t=12963&p=145040#p145040

Keep the design with signals that know how to show a particular aspect.
New `Light` class that interacts with a NeoPixel object that controls 
the LED. 
There may be several `Light` objects connected to a single NeoPixel object.
E.g. the signal has one red light, one green light and one yellow light.
Each of these interact with one NeoPixel. 
Question is who has the reference to the other.
Assume that the signal will only turn on one of these `Light` objects at
any time.

## Need more flexibility for obstacles anywhere.
Currently, cannot describe an obstacle such as a trailing point beyond
a block.

Suggest redesigning BlockDistanceInput to only take one block input
and another DistanceInput. 
Then these can be chained to produce any number of blocks.
Within the chain we can now insert DistanceWithCondition objects at any point.

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
