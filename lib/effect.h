#include <string.h>


class IEffect
{
public:
  ~IEffect {};
public:
  virtual void Apply(Game& aGame) = 0;
};


class EffectTest
{
public:
  Effect(std::string aMessage);
  ~Effect();
public:
  void Apply(Game& aGame) override;
private:
  std::string iMessage;

}
