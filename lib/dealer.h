#pragma once

#include <lib/deck.h>
#include <lib/effect.h>
#include <lib/player.h>

class Dealer
{
public:
	Dealer(IDeck* aDeck, IEffectFactory* aEffectFactory);
	void Deal(Player& aPlayer, int aCount);
private:
	std::unique_ptr<IDeck> iDeck;
	std::unique_ptr<IEffectFactory> iEffectFactory;
};

