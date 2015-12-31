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

bool Card::operator==(const Card& aRhs) const
{
	return iSuit == aRhs.iSuit;
}

bool Card::operator!=(const Card& aRhs) const
{
	return !(*this == aRhs);
}

bool Card::operator>(const Card& aRhs) const
{
	return ((iSuit > aRhs.iSuit)
		&& !(iSuit == Suit::eSpade && aRhs.iSuit == Suit::eDiamond));
}
