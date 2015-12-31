#include <lib/arbitrator.h>

const std::pair<bool, const RoundEntry&> Arbitrator2player::Arbitrate(const std::vector<RoundEntry>& aRoundEntries)
{
	// Only consider the first 2 entries ... :/

	int i = 0;
	bool winner = false;

	Card& card0 = *aRoundEntries[0].second;
	Card& card1 = *aRoundEntries[1].second;

	if (card0 != card1)
	{
		winner = true;
		if (card1 > card0)
			i = 1;
	}

	return std::pair<bool, const RoundEntry&>(winner, aRoundEntries[i]);
}

