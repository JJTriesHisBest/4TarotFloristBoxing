#pragma once

class Game;

class IMission
{
public:
	virtual bool Check(Game& aGame) = 0;
	virtual ~IMission() {}
};

