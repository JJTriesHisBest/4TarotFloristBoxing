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
  virtual unsigned int GetToken(Token aColour) const = 0;
  virtual void SetToken(Token aColour, unsigned int aCount) = 0;

};

class RBGTokenCounter : public ITokenCounter
{
public:
  RBGTokenCounter();
  ~RBGTokenCounter();
public: //ITokenCounter
  unsigned int GetToken(Token aColour) const override;
  void SetToken(Token aColour, unsigned int aCount) override;
private:
  std::map<Token, unsigned int> iTokens;
};
