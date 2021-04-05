#pragma once

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include "InputManager.h"


struct GameData
{
	StateMachine machine;
	sf::RenderWindow window;
	AssetManager assets;
	InputManager input;
	
};

typedef std::shared_ptr<GameData> GameDataRef;

class game {

private:
	const float dt = 1.0f / 60.0f; //frame rate
	sf::Clock _clock; //handle frame rate
	GameDataRef _data = std::make_shared<GameData>();

	void Run();

public:
	game(int width, int height, std::string title);
	


};

