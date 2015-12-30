#include <lib/game.h>
#include <lib/deck.h>
#include <lib/renderer.h>

int main()
{
	Game game;
	game.AddPlayer(new Player("tim"));
	game.AddPlayer(new Player("jj"));

	Deck deck;
	EffectFactoryNull effectFactory;

	for (auto& player : game.Players())
	{
		auto card = deck.CreateCard();
		card->AddEffect(effectFactory.CreateEffect());
		player->AddCard(card);
	}

	RendererConsole renderer;
	renderer.Render(game);
}

