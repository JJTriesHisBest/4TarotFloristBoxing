#include <lib/game.h>

int main()
{
	Game game;

	auto player = new Player();
	player->AddCard(new Card(Suit::eDiamond));

	game.AddPlayer(new Player());
}

