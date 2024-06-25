#include <string>

#define assertEquals(EXPECTED, ACTUAL) \
        doAssertEquals(__FILE__, __LINE__, EXPECTED, ACTUAL, #ACTUAL)

void doAssertEquals(const char * file, int line,
                    int expected, int actual, const char * expression);

void doAssertEquals(const char * file, int line,
                    const char * expected, const char * actual, const char * expression);

void doAssertEquals(const char * file, int line,
                    const void * expected, const void * actual, const char * expression);

#define test() \
        newTest(__FUNCTION__, __FILE__)

void newTest(const char * methodName, const char * fileName);

void suite(const std::string &name);

void fail();

int failures();
