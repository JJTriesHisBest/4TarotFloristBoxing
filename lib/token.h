#pragma once
#include <map>


enum class Token
{
  eRed,
  eBlue,
  eGreen
};

class ITokenCounter
{
public:
  virtual ~ITokenCounter() {}
public:
  virtual const uint GetToken(Token aColour) const = 0;
  virtual void SetToken(Token aColour, uint aCount) const = 0;

};

class RBGTokenCounter : public ITokenCounter
{
public:
  RBGTokenCounter();
  ~RBGTokenCounter();
public: //ITokenCounter
  const uint GetToken(Token aColour) const override;
  void SetToken(Token aColour, uint aCount) const override;
private:
  std::map<Token, uint> iTokens;
};
