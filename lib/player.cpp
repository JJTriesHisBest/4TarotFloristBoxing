#include <lib/player.h>

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

