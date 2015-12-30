#include <lib/card.h>


Card::Card(Suit aSuit, Effect& aEffect)
  : iSuit(aSuit)
  , iEffect(aEffect)
{

}

Card::~Card()
{

}

Suit Card::GetSuit()
{
  return iSuit;
}

Effect& Card::GetEffect()
{
  return iEffect;
}
