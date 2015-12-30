#include <lib/card.h>

Card::Card(Suit aSuit, Effect& aEffect)
  : iSuit(aSuit)
  , iEffect(aEffect)
{

}

Card::~Card()
{

}

Suit Card::Suit()
{
  return iSuit;
}

Effect& Card::Effect()
{
  return iEffect;
}
