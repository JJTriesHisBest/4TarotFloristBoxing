#include <lib/effect.h>
#include <string.h>

EffectTest::EffectTest(std::string aMessage)
  : iMessage(aMessage)
{

}

EffectTest::~EffectTest()
{

}

EffectTest::Apply(Game& /*aGame*/)
{
  cout << iMessage;
}
