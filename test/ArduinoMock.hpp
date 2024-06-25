#include "Arduino.hpp"

void setAnalogRead(int pin, int value);
void setDigitalRead(int pin, PinState value);
int getAnalogWrite(int pin);
PinState getDigitalWrite(int pin);

void addMillis(unsigned long millis);

void clearArduinoValues();
