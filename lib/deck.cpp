#include <lib/deck.h>
#include <cstdlib>

DeckRand::DeckRand()
{
	iSuits = {
		Suit::eDiamond,
		Suit::eClub,
		Suit::eHeart,
		Suit::eSpade };
}

Card* DeckRand::CreateCard()
{
	auto r = rand() % iSuits.size();
	return new Card(iSuits[r]);
}

