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

void newTest(const char * methodName, const char * fileName)
{
        printf("Running test %s in %s\n",
               methodName, fileName);
}
