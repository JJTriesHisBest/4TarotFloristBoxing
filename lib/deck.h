#pragma once
#include <lib/card.h>
#include <vector>

class IDeck
{
public:
	virtual Card* CreateCard() = 0;
	~IDeck() {}
};

class DeckRand
	: public IDeck
{
public:
	DeckRand();
public:
	Card* CreateCard() override;
private:
	std::vector<Suit> iSuits;
};

