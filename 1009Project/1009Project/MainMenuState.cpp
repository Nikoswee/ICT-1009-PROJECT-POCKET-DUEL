
#include<iostream>
#include <sstream>
#include "MainMenuState.h"
#include "DEFINITIONS.h"
#include "GameState.h"


MainMenuState::MainMenuState(GameDataRef data) : _data(data)
{

}

void MainMenuState::Init()
{
	this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
	this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON);

	this->_background.setTexture(this->_data->assets.GetTexture("Background"));
	this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));

	// setting play button to middle of window
	this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));

	this->InitText();
}


void MainMenuState::InitText()
{
	this->_data->assets.LoadFont("Dosis Light", DOSIS_LIGHT_FONT);

	this->uiMenuTitle.setFont(this->_data->assets.GetFont("Dosis Light"));
	this->uiMenuTitle.setCharacterSize(60);
	this->uiMenuTitle.setFillColor(sf::Color::Black);
	this->uiMenuTitle.setPosition(320.f, 100.f);
	this->uiMenuTitle.setString("NONE");

}


void MainMenuState::drawText(sf::RenderTarget& target)
{
	target.draw(this->uiMenuTitle);

}

void MainMenuState::updateText()
{
	this->uiMenuTitle.setString("CLICK TO PLAY!!");
}


void MainMenuState::HandleInput()
{
	sf::Event event;
	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();

		}

		if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Left, this->_data->window))
		{
			std::cout << "Go to Game Screen" << std::endl;
			this->_data->machine.AddState(StateRef(new GameState(_data)), true);
		}

	}
}

void MainMenuState::update(float dt)
{
	this->updateText();
}

void MainMenuState::draw(float dt)
{
	this->_data->window.clear();
	this->_data->window.draw(this->_background);
	this->_data->window.draw(this->_playButton);
	this->drawText(this->_data->window);

	this->_data->window.display();
}

