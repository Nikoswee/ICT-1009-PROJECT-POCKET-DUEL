#pragma once

#include <SFML/Graphics.hpp>
#include "State.h"
#include "game.h"

class MainMenuState : public State
{

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _playButton;

	sf::Text uiMenuTitle;

public:
	MainMenuState(GameDataRef data);
	void Init();
	void InitText();

	void updateText();
	void drawText(sf::RenderTarget& target);

	void HandleInput();
	void update(float dt);
	void draw(float dt);
};