#pragma once
#include <lib/card.h>
#include <memory>

class IDeck
{
public:
	virtual Card* CreateCard() = 0;
	~IDeck() {}
};

class Deck
	: public IDeck
{
public:
	Deck();
public:
	Card* CreateCard() override;
private:
	std::vector<Suit> iSuits;
};

