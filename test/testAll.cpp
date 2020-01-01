#include <map>
#include "testArduino.hpp"
#include "testSignalUnitTest.h"
#include "testSignal4Aspect.h"
#include "testSignal3Aspect.h"
#include "testSignal2Aspect.h"
#include "testSlowLight.h"
#include "testFastLight.h"
#include "testBlinkingLight.h"
#include "testDistanceTimer.h"
#include "testDistanceWithCondition.h"
#include "testPinInput.h"

std::map<std::string, void (*)()> suites = {
  {"Arduino", testArduino},
  {"SignalUnitTest", testSignalUnitTest},
  {"Signal4Aspect", testSignal4Aspect},
  {"Signal3Aspect", testSignal3Aspect},
  {"Signal2Aspect", testSignal3Aspect},
  {"DistanceTimer", testDistanceTimer},
  {"DistanceWithCondition", testDistanceWithCondition},
  {"SlowLight", testSlowLight},
  {"FastLight", testFastLight},
  {"BlinkingLight", testBlinkingLight},
  {"PinInput", testPinInput}
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
