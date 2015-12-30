#include <string>

class Game;

class IEffect
{
public:
  ~IEffect () {};
public:
  virtual void Apply(Game& aGame) = 0;
};


class EffectTest
	: public IEffect
{
public:
  EffectTest(std::string aMessage);
public: // IEffect
  void Apply(Game& aGame) override;
private:
  std::string iMessage;
};
