#include <lib/arbitrator.h>

const RoundEntry& Arbitrator::Arbitrate(const std::vector<RoundEntry>& aRoundEntries)
{
	return aRoundEntries[0];
}

