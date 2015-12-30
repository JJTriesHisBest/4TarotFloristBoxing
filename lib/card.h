
enum class Suit
{
  eDiamond,
  eClub,
  eHeart,
  eSpade
};

class Card
{
public:
  Card(Suit aSuit, Effect& aEffect);
  ~Card();
public:
  Suit Suit();
  Effect& Effect();
private:
  Suit iSuit;
  Effect& iEffect;
};
