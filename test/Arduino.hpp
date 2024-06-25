#ifndef ARDUINO_HPP
#define ARDUINO_HPP

#include <Arduino.h>

const int A0=20;
const int A1=21;
const int A2=22;
const int A3=23;

void analogWrite(int pin, int value);
int analogRead(int pin);
int map(int value, int fromLower, int fromUpper, int toLower, int toUpper);

#endif
