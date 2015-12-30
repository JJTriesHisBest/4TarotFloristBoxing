#pragma once
#include <lib/game.h>

class IRenderer
{
public:
	virtual void Render(Game& aGame) = 0;
	~IRenderer() {}
};

class RendererConsole
	: public IRenderer
{
public: // IRenderer
	void Render(Game& aGame) override;
};

