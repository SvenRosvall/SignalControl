# Testing for SignalControl

This directory contains a set of test files for the SignalControl Arduino library.
It is an ad-hoc test framework to support unit tests and compile time testing
of the example sketches.
It is provided to make it easier to develop the library without having to
upload the code to an actual Arduino unit.

This test framework is provided as is. 
Please contact me (sven@rosvall.ie) if you are interested in learning more about it.

## Running the tests
This test framework uses G++ and Makefile. 
You need to have these installed. 
They are standard tools for Linux platforms and available 
in [Cygwin](https://www.cygwin.com/) on Windows.

To run all tests run the following command line:

`make test`

This compiles all files and runs them.
This creates temporary object files and execution files.
These temporary files can be removed with:

`make clean`

The test suite contains two sets of tests:

1. Unit tests. These are contained in files starting with `test`.
2. Integration tests. This compiles the example files provided in the `examples` directory.
This is useful to ensure that the example sketches are correct and that all Arduino library
calls are covered by this test framework.

## Unit Test Framework
The Unit Test Framework is made from a few files:

[TestTools.hpp](TestTools.hpp)
: This header file contains the functions for tests. 
It contains a function `test()` that prints out the test name at the start of the test,
and `assertEquals()` for verifying test results.

[Arduino.hpp](Arduino.hpp)
: This file contains all the functions in the Arduino library that are supported by
this test framework. 
These functions have mock implementations that emulates the Arduino hardware.
This file must be included by all test files.

[ArduinoMock.hpp](ArduinoMock.hpp)
: The functions defined here control the behaviour of the mock implementation of the 
Arduino library functions.

[ArduinoMock.cpp](ArduinoMock.cpp)
: This file contains the implementation of the mocked Arduino library and the mock
control functions.
