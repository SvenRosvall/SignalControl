#pragma once

struct Serial_T
{
  void begin(int baudrate);

  bool available();
  char read();
  void flush();
  unsigned char readBytesUntil(int termChar, char *string, int length);
  void print(const char *);
  void println(const char *);
};
extern struct Serial_T Serial;
struct ENDL_T {};

Serial_T & operator<<(Serial_T &, int);
Serial_T & operator<<(Serial_T &, unsigned int);
Serial_T & operator<<(Serial_T &, long);
Serial_T & operator<<(Serial_T &, unsigned long);
Serial_T & operator<<(Serial_T &, const char *);
Serial_T & operator<<(Serial_T & s, const ENDL_T & e);
extern ENDL_T endl;
template <typename T> T _HEX(T v) { return v;}