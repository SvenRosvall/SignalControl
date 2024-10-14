# Release Notes

## In Progress
Rename TwoBinInput to [BistableInput](Design.md#bistableinput) and allow any input type.

## 2.2.0
Support signals that are wired with a common anode.

## 2.1.0
Add TwoPinInput class.

## 2.0.0
`pinMode()` shall be called only when running the `setup()` function.
Changed objects to use a `begin()` method that must be called from `setup()`.

As this is a breaking change the major release number is updated.

## 1.4.0
Support for more complex topologies where signals may depend
on routes through points/turnouts.

Also allow for describing rules with operators '&&' and '!'.

## 1.3.0
Minor improvements. No backwards compatibility breaks.

The improvements facilitate controlling block occupancy programmatically
rather than from input pins. 
This enables block occupancy input via CBUS events. 
### Improvements
* BlockDistanceInput and DistanceTimer can be constructed with 
  DigitalInput objects.
* Introduce SettableInput.
### Bug fixes
* Lifetime issues with temporary objects that could cause crashes.

## 1.2.0
Minor improvements. No backwards compatibility breaks.
### Improvements
* Light on flag is not off by default. No need to specify this.
* BlinkingLight can be configured with blink interval.
* SlowLight can be configured with transition interval.
* Remove debug print-out.
### Bug fixes
* Fix bug where SlowLight is lit on start.

## 1.1.0
Initial release