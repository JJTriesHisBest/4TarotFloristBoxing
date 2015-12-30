#include <lib/card.h>


Card::Card(Suit aSuit)
	: iSuit(aSuit)
{
}

void Card::AddEffect(IEffect* aEffect)
{
	iEffects.emplace_back(aEffect);
}

Suit Card::GetSuit() const
{
	return iSuit;
}

vu<IEffect>& Card::Effects()
{
	return iEffects;
}
