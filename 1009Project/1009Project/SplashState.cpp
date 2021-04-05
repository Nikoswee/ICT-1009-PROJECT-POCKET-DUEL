#include <sstream>
#include <iostream>
#include "DEFINITIONS.h"
#include "SplashState.h"
#include "MainMenuState.h"

SplashState::SplashState(GameDataRef data) : _data(data)
{}

void SplashState::Init()
{
	this->_data->assets.LoadTexture("Splash State Background", SPLASH_SCENE_BACKGROUND_FILEPATH);

	_background.setTexture(this->_data->assets.GetTexture("Splash State Background"));

}

void SplashState::HandleInput()
{
	sf::Event event;
	
	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();
		}
	}
}

void SplashState::update(float dt)
{
	if (this->_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
	{
		//Switch over to main menu
		std::cout << "Go to Main Menu" << std::endl;
		this->_data->machine.AddState(StateRef(new MainMenuState(_data)), true);

	}

}

void SplashState::draw(float dt)
{
	this->_data->window.clear(sf::Color::Black);
	this->_data->window.draw(this->_background);
	this->_data->window.display();
}