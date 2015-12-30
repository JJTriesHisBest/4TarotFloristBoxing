#pragma once

#include <lib/player.h>
#include <lib/card.h>

typedef std::pair<Player&, std::unique_ptr<Card>> RoundEntry;

class Arbitrator
{
public:
	const RoundEntry& Arbitrate(const std::vector<RoundEntry>& aRoundEntries);
};

