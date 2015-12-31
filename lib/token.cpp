#include <lib/token.h>

RBGTokenCounter::RBGTokenCounter()
{
  iTokens.insert(std::make_pair(Token::eRed, 0));
  iTokens.insert(std::make_pair(Token::eBlue, 0));
  iTokens.insert(std::make_pair(Token::eGreen, 0));
}

RBGTokenCounter::~RBGTokenCounter()
{

}

unsigned int RBGTokenCounter::GetToken(Token aColour) const
{
  return iTokens.at(aColour);
}
void RBGTokenCounter::SetToken(Token aColour, unsigned int aCount)
{
  iTokens[aColour] = aCount;
}
