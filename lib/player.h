#pragma once

#include <lib/card.h>
class Card {};
#include <lib/mission.h>
#include <lib/vu.h>


class Player
{
public:
	void AddCard(Card* aCard);
	void AddMission(IMission* aMission);
	vu<Card>& Cards();
	vu<IMission>& Missions();
private:
	vu<Card> iCards;
	vu<IMission> iMissions;
};


