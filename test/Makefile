all: test

test: run-testAll signal.ino.o examples
	@: do nothing

run-%: %
	./$<

CC=g++
CPPFLAGS=-I../src -g

testAll : testAll.o \
	testSignalUnitTest.o \
	testSignal4Aspect.o \
	testSignal3Aspect.o \
	testSignal2Aspect.o \
	testSlowLight.o \
	testFastLight.o \
	testBlinkingLight.o \
	testArduino.o \
	testDistanceTimer.o \
	testDistanceWithCondition.o \
	testPinInput.o \
	testInvertInput.o \
	testDistanceToDigitalInput.o \
	ArduinoMock.o \
	TestTools.o

examples: sketchSignal2AspectWithButton.o \
	sketchSignal3AspectWithDistanceTimer.o

depend :
	$(CC) -MM $(CPPFLAGS) *.cpp > dependencies

include dependencies

clean :
	-rm *.o *.exe
