#include <stdio.h>
#include <string.h>
#include <string>

#include "TestTools.hpp"
#include "ArduinoMock.hpp"

void doAssertEquals(const char * file, int line,
                    int expected, int actual, const char * expression)
{
  if (expected != actual)
  {
    printf("%s:%d: '%s' is %d, but expected %d\n",
           file, line,
           expression, actual, expected);
    fflush(stdout);
    fail();
  }
}

void doAssertEquals(const char * file, int line,
                    const char * expected, const char * actual, const char * expression)
{
  if (strcmp(expected, actual) != 0)
  {
    printf("%s:%d: '%s' is '%s', but expected '%s'\n",
           file, line,
           expression, actual, expected);
    fail();
  }
}

void doAssertEquals(const char * file, int line,
                    const void * expected, const void * actual, const char * expression)
{
  if (expected != actual)
  {
    printf("%s:%d: '%s' is %0x, but expected %0x\n",
           file, line,
           expression, actual, expected);
    fflush(stdout);
    fail();
  }
}

void newTest(const char * methodName, const char * fileName)
{
  printf("Running test %s in %s\n",
         methodName, fileName);
  clearArduinoValues();
}

static int suiteFailures;

void suite(const std::string &name)
{
  printf("Running suite %s\n", name.c_str());
  suiteFailures = 0;
}

void fail()
{
  suiteFailures++;
}

int failures()
{
  return suiteFailures;
}
