# Release Notes

## 1.3.0
Minor improvements. No backwards compatibility breaks.
### Improvements
* BlockDistanceInput and DistanceTimer can be constructed with 
  DigitalInput objects.
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