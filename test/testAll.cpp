#include <map>
#include <string>
#include "testArduino.hpp"
#include "testSignalUnitTest.h"
#include "testSignal4Aspect.h"
#include "testSignal3Aspect.h"
#include "testSignal2Aspect.h"
#include "testSlowLight.h"
#include "testFastLight.h"
#include "testBlinkingLight.h"
#include "testDistanceTimer.h"
#include "testBlockDistanceInput.h"
#include "testDistanceWithCondition.h"
#include "testDistanceChoice.h"
#include "testBlockTopologies.h"
#include "testPinInput.h"
#include "testAndInput.h"
#include "testInvertInput.h"
#include "testDistanceToDigitalInput.h"
#include "testSettableInput.h"

std::map<std::string, void (*)()> suites = {
  {"Arduino", testArduino},
  {"SignalUnitTest", testSignalUnitTest},
  {"Signal4Aspect", testSignal4Aspect},
  {"Signal3Aspect", testSignal3Aspect},
  {"Signal2Aspect", testSignal2Aspect},
  {"DistanceTimer", testDistanceTimer},
  {"BlockDistanceInput", testBlockDistanceInput},
  {"DistanceWithCondition", testDistanceWithCondition},
  {"DistanceChoice", testDistanceChoice},
  {"BlockTopologies", testBlockTopologies},
  {"SlowLight", testSlowLight},
  {"FastLight", testFastLight},
  {"BlinkingLight", testBlinkingLight},
  {"PinInput", testPinInput},
  {"AndInput", testAndInput},
  {"InvertInput", testInvertInput},
  {"DistanceToDigitalInput", testDistanceToDigitalInput},
  {"SettableInput", testSettableInput}
};

int main(int argc, const char * const * argv)
{
  if (*++argv == nullptr)
  {
    for (auto const &i : suites)
    {
      i.second();
    }
  }
  else
  {
    while (const char * arg = *argv++)
    {
      suites[arg]();
    }
  }
}
