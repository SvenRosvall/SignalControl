all: test

test: run-testAll examples
	@: do nothing

run-%: %
	./$<

CC=g++
CPPFLAGS=-std=gnu++11 -I../src -g -Wall

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
	testBlockDistanceInput.o \
	testDistanceWithCondition.o \
	testDistanceChoice.o \
	testBlockTopologies.o \
	testPinInput.o \
	testAndInput.o \
	testInvertInput.o \
	testSettableInput.o \
	testDistanceToDigitalInput.o \
	testTemporaries.o \
	ArduinoMock.o \
	TestTools.o

examples: sketchSignal2AspectWithButton.o \
	sketchSignal3AspectWithDistanceTimer.o \
	sketchSignal3AspectWithBlockDistanceInput.o \
	sketchTwoIndependentSignal3Aspect.o \
	sketchTwoSignal3AspectJoiningPoint.o

depend :
	$(CC) -MM $(CPPFLAGS) *.cpp > dependencies

include dependencies

clean :
	-rm *.o *.exe
