#include <map>
#include <Arduino.h>
#include <Streaming.h>
#include <iostream>
#include "Arduino.hpp"
#include "ArduinoMock.hpp"

/* Mocking implementation */

std::map<int, int> analogReadValues;
void setAnalogRead(int pin, int value)
{
        analogReadValues[pin] = value;
}

std::map<int, PinState> digitalReadValues;
void setDigitalRead(int pin, PinState value)
{
        digitalReadValues[pin] = value;
}

std::map<int, int> analogWrittenValues;
int getAnalogWrite(int pin)
{
        return analogWrittenValues[pin];
}

std::map<int, PinState> digitalWrittenValues;
PinState getDigitalWrite(int pin)
{
        return digitalWrittenValues[pin];
}

unsigned long nextMillis;
void addMillis(unsigned long newMillis)
{
        nextMillis += newMillis;
}

void clearArduinoValues()
{
        digitalReadValues.clear();
        analogWrittenValues.clear();
        nextMillis = 0L;
}

/* Arduino methods */

void analogWrite(int pin, int value)
{
        analogWrittenValues[pin] = value;
}
int analogRead(int pin)
{
        return analogReadValues[pin];
}
void digitalWrite(int pin, PinState value)
{
	digitalWrittenValues[pin] = value;
}
byte digitalRead(int pin)
{
        return digitalReadValues[pin];
}
void pinMode(int pin, PinMode mode)
{
}

unsigned long millis()
{
        return nextMillis;
}
void delay(unsigned int delayMillis)
{
  nextMillis += delayMillis;
}

int map(int value, int fromLower, int fromUpper, int toLower, int toUpper)
{
        return (value - fromLower) * (toUpper - toLower) / (fromUpper - fromLower) + toLower;
}

byte highByte(unsigned int i)
{
  return i >> 8;
}
byte lowByte(unsigned int i)
{
  return i & 0xFF;
}

void Serial_T::begin(int baudRate)
{
}

bool Serial_T::available()
{
  return true;
}

char Serial_T::read()
{
  return ' ';
}

void Serial_T::println(const char *)
{
}

void Serial_T::flush()
{
}

Serial_T & operator<<(Serial_T & s, int i)
{
  std::cout << i;
  return s;
}
Serial_T & operator<<(Serial_T & s, unsigned int i)
{
  std::cout << i;
  return s;
}
Serial_T & operator<<(Serial_T & s, long i)
{
  std::cout << i;
  return s;
}
Serial_T & operator<<(Serial_T & s, unsigned long i)
{
  std::cout << i;
  return s;
}
Serial_T & operator<<(Serial_T & s, const char * i)
{
  std::cout << i;
  return s;
}
Serial_T & operator<<(Serial_T & s, const ENDL_T & e)
{
  std::cout << std::endl;
  return s;
}
ENDL_T endl;
Serial_T Serial;
//template <typename T> T _HEX(T);
