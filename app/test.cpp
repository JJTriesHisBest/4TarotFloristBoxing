#include <lib/card.h>
#include <lib/effect.h>
#include <memory>
#define TEST(x) /
if(!(x)) /
{ /
std::cout << "Test failed at line: " << __LINE__ << std::endl; /
} /

////


class EffectTest : public IEffect
{
public:
  Effect(std::string aMessage);
  ~Effect();
public:
  void Apply(Game& aGame) override;
private:
  std::string iMessage;
  bool& iVictory;
};

EffectTest::EffectTest(std::string aMessage, bool& aVictory)
  : iMessage(aMessage)
  , iVictory
{

}

EffectTest::~EffectTest()
{

}

EffectTest::Apply(Game& /*aGame*/)
{
  aVictory = true;
}

////


int main()
{
  bool diamondWins = false;
  bool clubWins = false;
  bool heartWins = false;
  bool spadeWins = false;

  std::unique_ptr<IEffect> effectDiamond(new EffectTest("DiamondWins"), diamondWins);
  std::unique_ptr<IEffect> effectClub(new EffectTest("ClubWins"), clubWins);
  std::unique_ptr<IEffect> effectHeart(new EffectTest("HeartWins"), heartWins);
  std::unique_ptr<IEffect> effectSpade(new EffectTest("SpadeWins"), spadeWins);

  Card cardDiamond(Suit::eDiamond, *effectDiamond);
  Card cardClub(Suit::eClub, *effectClub);
  Card cardHeart(Suit::eHeart, *effectHeart);
  Card cardSpade(Suit::eSpade, *effectSpade);


}
