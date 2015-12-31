#include <lib/arbitrator.h>
#include <lib/game.h>
#include <lib/dealer.h>
#include <lib/deck.h>
#include <lib/renderer.h>
#include <iostream>

using namespace std;

int main()
{
	Game game;
	game.AddPlayer(new Player("tim"));
	game.AddPlayer(new Player("jj"));

	Dealer dealer(new DeckRand(), new EffectFactoryNull());

	for (auto& player : game.Players())
	{
		dealer.Deal(*player, 4);
	}

	Arbitrator arbitrator;
	RendererConsole renderer;

	bool playing = true;

	while (playing)
	{
		renderer.Render(game);

		// get each players input
		std::vector<RoundEntry> round;
		for (auto& player : game.Players())
		{
			int n;
			cout << player->Name() << ", please choose a card to play:";
			cin >> n;
			// extract card
			auto card = player->Cards().extract(n-1);
			round.emplace_back(*player.get(), std::move(card));
		}

		// arbitrate
		auto& winningEntry = arbitrator.Arbitrate(round);

		// run effects
		for (auto& effect : winningEntry.second->Effects())
		{
			//effect->Apply(winningEntry.first, game);
			effect->Apply(game);
		}

		// check missions
		for (auto& mission : winningEntry.first.Missions())
		{
			if (mission->Check(game, winningEntry.first))
			{
				cout << winningEntry.first.Name() << " won!" << endl;
				playing = false;
			}
		}

		for (auto& player : game.Players())
		{
			dealer.Deal(*player, 1);
		}
	}
}
