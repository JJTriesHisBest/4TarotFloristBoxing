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

const uint RBGTokenCounter::GetToken(Token aColour) const
{
  return iTokens[aColour];
}
void RBGTokenCounter::SetToken(Token aColour, uint aCount) const
{
  iTokens[aColour] = aCount;
}
