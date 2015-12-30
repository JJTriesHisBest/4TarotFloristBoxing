#pragma once
#include <lib/player.h>
class Game;
class Player;
class IMission
{
public:
	virtual bool Check(Game& aGame, Player& aEvaluatedPlayer) = 0;
	virtual ~IMission() {}
};



class Mission : public IMission
{
public:
	Mission();
	~Mission();
public: //IMission
	bool Check(Game& aGame, Player& aEvaluatedPlayer) override;

};
