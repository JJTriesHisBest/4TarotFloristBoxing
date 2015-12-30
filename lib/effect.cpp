#include <lib/effect.h>
#include <iostream>

EffectTest::EffectTest(std::string aMessage)
  : iMessage(aMessage)
{
}

void EffectTest::Apply(Game& /*aGame*/)
{
  std::cout << iMessage;
}
