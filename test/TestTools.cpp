#include <stdio.h>
#include "TestTools.hpp"

void doAssertEquals(const char * file, int line,
                    int expected, int actual, const char * expression)
{
        if (expected != actual)
        {
                printf("%s:%d: '%s' is %d, but expected %d\n",
                       file, line,
                       expression, actual, expected);
        }
}

void newTest(const char * methodName)
{
        printf("Running test %s\n", methodName);
}
