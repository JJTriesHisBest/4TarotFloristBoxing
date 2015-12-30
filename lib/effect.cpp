#include <lib/effect.h>
#include <iostream>

void EffectTest::Apply(Game& /*aGame*/)
{
  std::cout << iMessage;
}

EffectNull::EffectNull()
	: iDescription("Does nothing.")
{}

const std::string& EffectNull::Description() const
{
	return iDescription;
}

void EffectNull::Apply(Game&)
{
}

IEffect* EffectFactoryNull::CreateEffect()
{
	return new EffectNull;
}

