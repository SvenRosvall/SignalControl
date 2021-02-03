#include <map>
#include "Arduino.hpp"
#include "ArduinoMock.hpp"

/* Mocking implementation */

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
        return 0;
}
void digitalWrite(int pin, PinState value)
{
	digitalWrittenValues[pin] = value;
}
int digitalRead(int pin)
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

int map(int value, int fromLower, int fromUpper, int toLower, int toUpper)
{
        return (value - fromLower) * (toUpper - toLower) / (fromUpper - fromLower) + toLower;
}


void Serial::begin(int baudRate)
{
}
void Serial::println(const char *)
{
}

struct Serial Serial;
