#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "game.h"

class SplashState : public State
{
private:
	GameDataRef _data;
	sf::Clock _clock;
	sf::Sprite _background;

public:
	SplashState(GameDataRef data);
	void Init();
	void HandleInput();
	void update(float dt);
	void draw(float dt);
	
};