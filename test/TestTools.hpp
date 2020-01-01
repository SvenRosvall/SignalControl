#define assertEquals(EXPECTED, ACTUAL) \
        doAssertEquals(__FILE__, __LINE__, EXPECTED, ACTUAL, #ACTUAL)

void doAssertEquals(const char * file, int line,
                    int expected, int actual, const char * expression);

#define test() \
        newTest(__FUNCTION__)

void newTest(const char * methodName);
