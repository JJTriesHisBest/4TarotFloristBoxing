#include <lib/card.h>
#include <lib/effect.h>
#include <memory>
#include <lib/vu.h>
#define TEST(x) \
if(!(x)) \
{ \
std::cout << "Test failed at line: " << __LINE__ << std::endl; \
} \

////


class EffectTest : public IEffect
{
public:
  EffectTest(std::string aMessage, bool& aVictory);
  ~EffectTest();
public:
  void Apply(Game& aGame) override;
private:
  std::string iMessage;
  bool& iVictory;
};

EffectTest::EffectTest(std::string aMessage, bool& aVictory)
  : iMessage(aMessage)
  , iVictory(aVictory)
{

}

EffectTest::~EffectTest()
{

}

void EffectTest::Apply(Game& /*aGame*/)
{
  iVictory = true;
}

////


int main()
{
  bool diamondWins = false;
  bool clubWins = false;
  bool heartWins = false;
  bool spadeWins = false;

  vu<IEffect> effectDiamond;
  effectDiamond.emplace_back(new EffectTest("DiamondWins", diamondWins));
  vu<IEffect> effectClub;
  effectClub.emplace_back(new EffectTest("ClubWins", clubWins));
  vu<IEffect> effectHeart;
  effectHeart.emplace_back(new EffectTest("HeartWins", heartWins));
  vu<IEffect> effectSpade;
  effectSpade.emplace_back(new EffectTest("SpadeWins", spadeWins));

  Card cardDiamond(Suit::eDiamond);
  Card cardClub(Suit::eClub);
  Card cardHeart(Suit::eHeart);
  Card cardSpade(Suit::eSpade);


}
