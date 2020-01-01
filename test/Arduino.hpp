#ifndef ARDUINO_HPP
#define ARDUINO_HPP

const int A0=20;
const int A1=21;
const int A2=22;
const int A3=23;

enum PinMode {
        OUTPUT,
        INPUT,
        INPUT_PULLUP
};
enum PinState {
        LOW,
        HIGH
};

void analogWrite(int pin, int value);
int analogRead(int pin);
void digitalWrite(int pin, PinState value);
int digitalRead(int pin);
int map(int value, int fromLower, int fromUpper, int toLower, int toUpper);
void pinMode(int pin, PinMode mode);
unsigned long millis();
void delay(int millis);

struct Serial
{
        void begin(int baudRate);
        void println(const char *);
};
extern struct Serial Serial;

#endif
