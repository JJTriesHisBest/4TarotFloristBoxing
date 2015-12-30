#include <string>

class Game;

class IEffect
{
public:
  ~IEffect () {};
public:
  virtual void Apply(Game& aGame) = 0;
};
