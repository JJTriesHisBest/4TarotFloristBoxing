#include <lib/effect.h>
#include <iostream>
#include <sstream>
#include <random>
EffectNull::EffectNull()
	: iDescription("Does nothing.")
{}

const std::string& EffectNull::Description() const
{
	return iDescription;
}

void EffectNull::Apply(Game&, Player&)
{
}

IEffect* EffectFactoryNull::CreateEffect()
{
	return new EffectNull;
}

EffectReceive::EffectReceive(int aReceived, Token aColour)
  : iReceived(aReceived)
	, iToken(aColour)
{
  std::ostringstream buf;
  buf << (aReceived > 0 ? "Increase " : "Decrease ");

  switch(iToken)
	{
    case Token::eRed:
      buf << "red by ";
      break;
    case Token::eBlue:
      buf << "blue by ";
      break;
    case Token::eGreen:
      buf << "green by ";
      break;
  }
  buf << iReceived;
  iDescription = buf.str();
}

EffectReceive::~EffectReceive()
{

}

const std::string& EffectReceive::Description() const
{

}

void EffectReceive::Apply(Game& aGame, Player& aCurrentPlayer)
{
	uint newtokens = aCurrentPlayer.Tokens().GetToken(iToken) + iReceived;
	aCurrentPlayer.Tokens().SetToken(iToken, newtokens);
}

EffectReceiveFactory::EffectReceiveFactory(uint aPlayers)
{
  iMaxReceive = aPlayers + 2;
}

EffectReceiveFactory::~EffectReceiveFactory()
{

}

IEffect* EffectReceiveFactory::CreateEffect()
{
  int minReceive = -(iMaxReceive);
  std::random_device rd;
  std::mt19937 eng(rd());
  std::uniform_int_distribution<> eff(minReceive, iMaxReceive);
  std::uniform_int_distribution<> tok(1,3);

  return new EffectReceive(eff(eng), static_cast<Token>(tok(eng)));
}
