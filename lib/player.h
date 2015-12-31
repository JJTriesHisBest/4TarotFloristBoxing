#pragma once

#include <lib/card.h>
#include <lib/mission.h>
#include <lib/vu.h>
#include <lib/token.h>
#include <string>
#include <memory>

class Player
{
public:
	Player(std::string aName);
	const std::string& Name() const;
	void AddCard(Card* aCard);
	void AddMission(IMission* aMission);
	vu<Card>& Cards();
	vu<IMission>& Missions();
	ITokenCounter& Tokens();
private:
	std::string iName;
	vu<Card> iCards;
	vu<IMission> iMissions;
	std::unique_ptr<ITokenCounter> iTokens;
};
