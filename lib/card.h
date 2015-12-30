#pragma once
#include <lib/effect.h>
#include <lib/vu.h>

enum class Suit
{
	eDiamond,
	eClub,
	eHeart,
	eSpade
};

class Card
{
public:
	Card(Suit aSuit);
	void AddEffect(IEffect* aEffect);
	Suit GetSuit() const;
	vu<IEffect>& Effects();
private:
	Suit iSuit;
	vu<IEffect> iEffects;
};

