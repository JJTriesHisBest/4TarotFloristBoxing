#pragma once
#include <lib/player.h>
#include <lib/vu.h>

class Game
{
public:
	void AddPlayer(Player* aPlayer);
	vu<Player>& Players();
private:
	vu<Player> iPlayers;
};

