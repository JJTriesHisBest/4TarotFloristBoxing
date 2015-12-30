#include <lib/renderer.h>
#include <iostream>

using namespace std;

void RendererConsole::Render(Game& aGame)
{
	cout << "Game state:" << endl;
	for (auto& player : aGame.Players())
	{
		cout << "[" << player->Name() << "]" << endl;
		for (auto& card : player->Cards())
		{
			switch (card->GetSuit()) {
			case Suit::eDiamond:
				cout << "Diamond";
				break;
			case Suit::eSpade:
				cout << "Spade";
				break;
			case Suit::eClub:
				cout << "Club";
				break;
			case Suit::eHeart:
				cout << "Heart";
				break;
			};

			if (card->Effects().size())
			{
				cout << " ... ";

				for (auto& effect : card->Effects())
				{
					cout << effect->Description() << " ";
				}

				cout << endl;
			}
		}
	}
}

