#include <map>
#include <string>
#include <iostream>

#include "Arduino.hpp"
#include "TestTools.hpp"

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
#include "testTemporaries.h"

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
  {"SettableInput", testSettableInput},
  {"Temporaries", testTemporaries}
};

int main(int argc, const char * const * argv)
{
  int totalFailures = 0;
  if (*++argv == nullptr)
  {
    for (auto const &i : suites)
    {
      suite(i.first);
      i.second();
      totalFailures += failures(); 
    }
  }
  else
  {
    bool needHelp = false;
    while (const char * arg = *argv++)
    {
      auto found = suites.find(arg);
      if (found != suites.end())
      {
        found->second();
        totalFailures += failures();
      }
      else
      {
        std::cout << "Cannot find test suite '" << arg << "'" << std::endl;
        needHelp = true;
    }
  }
    if (needHelp)
    {
      std::cout << "The following test suites are available:" << std::endl;
      for (auto & suite : suites)
      {
        std::cout << "  " << suite.first << std::endl;
      }
    }
  }
  if (totalFailures > 0)
  {
    std::cout << "Completed with totalFailures. " << totalFailures << " test(s) failed." << std::endl;
  }
  return totalFailures;
}
