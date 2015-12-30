#pragma once

#include <string>

class Game;

// IEffect

class IEffect
{
public:
	virtual const std::string& Description() const = 0;
	virtual void Apply(Game& aGame) = 0;
  	~IEffect () {};
};

// IEffectFactory

class IEffectFactory
{
public:
	virtual IEffect* CreateEffect() = 0;
	~IEffectFactory() {}
};

// EffectNull

class EffectNull
	: public IEffect
{
public:
	EffectNull();
public:
	const std::string& Description() const override;
	void Apply(Game& aGame) override;
private:
	std::string iDescription;
};

class EffectFactoryNull
	: public IEffectFactory
{
public: // IEffectFactory
	IEffect* CreateEffect() override;
};
