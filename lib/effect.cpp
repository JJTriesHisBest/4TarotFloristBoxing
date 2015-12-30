#include <lib/effect.h>
#include <iostream>

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

