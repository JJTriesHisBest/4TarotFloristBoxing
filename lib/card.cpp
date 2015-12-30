#include <lib/card.h>


Card::Card(Suit aSuit)
	: iSuit(aSuit)
{
}

void Card::AddEffect(IEffect* aEffect)
{
	iEffects.emplace_back(aEffect);
}

<<<<<<< HEAD
Suit Card::GetSuit()
=======
Suit Card::GetSuit() const
>>>>>>> da3ce5b72f510ac6c47f465373f7a7fd927bb9a7
{
	return iSuit;
}

<<<<<<< HEAD
Effect& Card::GetEffect()
=======
vu<IEffect>& Card::Effects()
>>>>>>> da3ce5b72f510ac6c47f465373f7a7fd927bb9a7
{
	return iEffects;
}
