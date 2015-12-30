#include <lib/dealer.h>

Dealer::Dealer(IDeck* aDeck, IEffectFactory* aEffectFactory)
	: iDeck(aDeck)
	, iEffectFactory(aEffectFactory)
{}

void Dealer::Deal(Player& aPlayer, int aCount)
{
	for (int i = 0 ; i < aCount ; ++i )
	{
		auto card = iDeck->CreateCard();
		card->AddEffect(iEffectFactory->CreateEffect());
		aPlayer.AddCard(card);
	}
}

