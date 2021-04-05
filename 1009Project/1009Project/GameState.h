#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "State.h"
#include "game.h"
#include "Pokemon.h"
#include "Player.h"

class GameState : public State
{

private:
	GameDataRef _data;
	sf::Sprite _background;
	sf::Sprite _homeButton;
	sf::Sprite _soundButton;

	//Pokemon image
	Pokemon* pokemon;

	//Trainer
	Player* player;

	//Text
	sf::Text uiGameTitle;
	sf::Text uiTextInstruction;

	sf::Text uiTextGrass;
	sf::Text uiTextFire;
	sf::Text uiTextWater;

	sf::Text uiTextPlayerChoice;
	sf::Text uiTextButtonChangeBG;

	//Music
	sf::Music music;

	//For the game logic
	//Set each choices as an integer 
	const int Empty = 0;
	const int Grass = 1;
	const int Fire = 2;
	const int Water = 3;

	//Player and AI move
	int playerchoice = 0;
	int AIchoice = 0;

	//Player and AI score
	int playerWins = 0;
	int aiWins = 0;
	int tie = 0;

	//Conditon output
	std::string PlayerWinString = "Player Wins: ";
	std::string AiWinString = " Ai Wins: ";
	std::string tieString = " Ties: ";

	//Game text
	sf::Text uiTextAIChoice;
	sf::Text uiTextWinner;

	//Scoreboard
	sf::Text uiTextScoreboard;



public:
	GameState(GameDataRef data);

	//Initialization
	void Init();
	void InitPokemon();
	void InitPlayer();
	void InitText();
	void InitMusic();

	//Game logic
	void getAiChoice();
	void getWinner();

	//Events
	void HandleInput();
	void updateText();
	void drawText(sf::RenderTarget& target);
	void update(float dt);
	void draw(float dt);

};