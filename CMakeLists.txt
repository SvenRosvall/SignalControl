cmake_minimum_required(VERSION 3.26)
project(SignalControl CXX)

set(CMAKE_CXX_STANDARD 11)

include_directories(examples)
include_directories(examples/Signal2AspectWithButton)
include_directories(examples/Signal3AspectWithBlockDistanceInput)
include_directories(examples/Signal3AspectWithDistanceTimer)
include_directories(examples/TwoIndependentSignal3Aspect)
include_directories(examples/TwoSignal3AspectJoiningPoint)
include_directories(src)
include_directories(Arduino)

add_library(core_library OBJECT
        src/AndInput.h
        src/BlinkingLight.h
        src/BlockDistanceInput.h
        src/DigitalInput.h
        src/DistanceChoice.h
        src/DistanceInput.h
        src/DistanceTimer.h
        src/DistanceToDigitalInput.h
        src/DistanceWithCondition.h
        src/FastLight.h
        src/InvertInput.h
        src/Light.h
        src/mv.h
        src/PinInput.h
        src/SettableInput.h
        src/Signal2Aspect.h
        src/Signal3Aspect.h
        src/Signal4Aspect.h
        src/SignalFyrSken.h
        src/SlowLight.h
        src/TwoPinInput.h
)
set_target_properties(core_library PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(core_library PUBLIC)

add_executable(testAll
        $<TARGET_OBJECTS:core_library>
        
        test/Arduino.hpp
        test/ArduinoMock.cpp
        test/ArduinoMock.hpp
        test/MockDistanceInput.h
        test/MockInput.h
        test/testAll.cpp
        test/testAndInput.cpp
        test/testAndInput.h
        test/testArduino.cpp
        test/testArduino.hpp
        test/testBlinkingLight.cpp
        test/testBlinkingLight.h
        test/testBlockDistanceInput.cpp
        test/testBlockDistanceInput.h
        test/testBlockTopologies.cpp
        test/testBlockTopologies.h
        test/testDistanceChoice.cpp
        test/testDistanceChoice.h
        test/testDistanceTimer.cpp
        test/testDistanceTimer.h
        test/testDistanceToDigitalInput.cpp
        test/testDistanceToDigitalInput.h
        test/testDistanceWithCondition.cpp
        test/testDistanceWithCondition.h
        test/testFastLight.cpp
        test/testFastLight.h
        test/testInvertInput.cpp
        test/testInvertInput.h
        test/testPinInput.cpp
        test/testPinInput.h
        test/testSettableInput.cpp
        test/testSettableInput.h
        test/testSignal2Aspect.cpp
        test/testSignal2Aspect.h
        test/testSignal3Aspect.cpp
        test/testSignal3Aspect.h
        test/testSignal4Aspect.cpp
        test/testSignal4Aspect.h
        test/testSignalUnitTest.cpp
        test/testSignalUnitTest.h
        test/testSlowLight.cpp
        test/testSlowLight.h
        test/testTemporaries.cpp
        test/testTemporaries.h
        test/testTwoPinInput.cpp
        test/testTwoPinInput.h
        test/TestTools.cpp
        test/TestTools.hpp)

add_library(sketches OBJECT
        test/sketchSignal2AspectWithButton.cpp
        test/sketchSignal3AspectWithDistanceTimer.cpp
        test/sketchSignal3AspectWithBlockDistanceInput.cpp
        test/sketchTwoIndependentSignal3Aspect.cpp
        test/sketchTwoSignal3AspectJoiningPoint.cpp
)