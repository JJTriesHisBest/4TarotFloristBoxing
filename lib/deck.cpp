#include <lib/deck.h>

Deck::Deck()
	: iSuits(
	{	Suit::eDiamond,
		Suit::eClub,
		Suit::eHeart,
		Suit::eSpade })
{}

Card* Deck::CreateCard()
{
		
	return new Card(Suit::eDiamond);
}

