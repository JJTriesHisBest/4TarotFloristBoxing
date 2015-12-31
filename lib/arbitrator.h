#pragma once

#include <lib/player.h>
#include <lib/card.h>

typedef std::pair<Player&, std::unique_ptr<Card>> RoundEntry;

class IArbitrator 
{
public:
	virtual const std::pair<bool, const RoundEntry&> Arbitrate(const std::vector<RoundEntry>& aRoundEntries) = 0;
	virtual ~IArbitrator() {}
};

class Arbitrator2player
	: public IArbitrator
{
public: // IArbitrator
	const std::pair<bool, const RoundEntry&> Arbitrate(const std::vector<RoundEntry>& aRoundEntries) override;
};

