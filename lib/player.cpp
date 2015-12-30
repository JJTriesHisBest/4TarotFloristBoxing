#include <lib/player.h>

Player::Player(std::string aName)
	: iName(aName)
{}

const std::string& Player::Name() const
{
	return iName;
}

void Player::AddCard(Card* aCard)
{
	iCards.emplace_back(aCard);
}

void Player::AddMission(IMission* aMission)
{
	iMissions.emplace_back(aMission);
}

vu<Card>& Player::Cards()
{
	return iCards;
}

vu<IMission>& Player::Missions()
{
	return iMissions;
}

