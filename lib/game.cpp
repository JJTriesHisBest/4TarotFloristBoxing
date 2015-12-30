#include <lib/game.h>

void Game::AddPlayer(Player* aPlayer)
{
	iPlayers.emplace_back(aPlayer);
}

vu<Player>& Game::Players()
{
	return iPlayers;
}

