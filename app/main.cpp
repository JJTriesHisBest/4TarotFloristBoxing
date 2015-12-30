#include <lib/game.h>

int main()
{
	Game game;

	auto player = new Player();
	player->AddCard(new Card());
	player->AddCard(new Card());
	player->AddCard(new Card());

	game.AddPlayer(new Player());
}

