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

	Arbitrator2player arbitrator;
	RendererConsole renderer;

	bool playing = true;

	while (playing)
	{
		cout << "=========================================================================" << endl;
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
		auto winningEntry = arbitrator.Arbitrate(round);

		if (winningEntry.first) // was there a winner?
		{
			auto& player = winningEntry.second.first;
			auto& missions = winningEntry.second.first.Missions();
			auto& effects = winningEntry.second.second->Effects();

			cout << player.Name() << " won this round..." << endl;

			// run effects
			for (auto& effect : effects)
			{
				effect->Apply(game);
			}

			// check missions
			for (auto& mission : missions)
			{
				if (mission->Check(game, player))
				{
					cout << player.Name() << " won!" << endl;
					playing = false;
				}
			}
		}
		else
		{
			cout << "It was a draw." << endl;
		}

		for (auto& player : game.Players())
		{
			dealer.Deal(*player, 1);
		}
	}
}
