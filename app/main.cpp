#include <lib/game.h>
#include <lib/dealer.h>
#include <lib/deck.h>
#include <lib/renderer.h>

int main()
{
	Game game;
	game.AddPlayer(new Player("tim"));
	game.AddPlayer(new Player("jj"));

	Dealer dealer(new Deck(), new EffectFactoryNull());

	for (auto& player : game.Players())
	{
		dealer.Deal(*player, 4);
	}

	RendererConsole renderer;
	renderer.Render(game);
}

