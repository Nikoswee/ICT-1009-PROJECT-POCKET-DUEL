
#include<iostream>
#include <sstream>
#include "GameState.h"
#include "DEFINITIONS.h"


GameState::GameState(GameDataRef data) : _data(data)
{
   
}

void GameState::Init()
{

	this->_data->assets.LoadTexture("Background", GAME_BACKGROUND_FILEPATH);
   // this->_data->assets.LoadTexture("Sound Button", GAME_BACKGROUND_FILEPATH);
	//this->_data->assets.LoadTexture("Home Button", GAME_HOME_BUTTON);

	this->_background.setTexture(this->_data->assets.GetTexture("Background"));
    //this->_soundButton.setTexture(this->_data->assets.GetTexture("Sound Button"));
	//this->_homeButton.setTexture(this->_data->assets.GetTexture("Home Button"));

	
	//this->_homeButton.setPosition(870.f, 10.f);

    //Set Sound button top right
    this->_soundButton.setPosition(870.f, 10.f);

  
    this->InitText();
    this->InitPokemon();
    this->InitPlayer();
    this->InitMusic();

}

//display pokemon
void GameState::InitPokemon()
{
    this->pokemon = new Pokemon();
}

//Trainer (To be remove)
void GameState::InitPlayer()
{
    this->player = new Player();
}


void GameState::InitText()
{

    this->_data->assets.LoadFont("Dosis Light", DOSIS_LIGHT_FONT);

    this->uiGameTitle.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiGameTitle.setCharacterSize(30);
    this->uiGameTitle.setFillColor(sf::Color::Black);
    this->uiGameTitle.setPosition(390.f, 20.f);
    this->uiGameTitle.setString("NONE");

    this->uiTextInstruction.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextInstruction.setCharacterSize(30);
    this->uiTextInstruction.setFillColor(sf::Color::Black);
    this->uiTextInstruction.setPosition(190.f, 50.f);
    this->uiTextInstruction.setString("NONE");

    this->uiTextButtonChangeBG.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextButtonChangeBG.setCharacterSize(30);
    this->uiTextButtonChangeBG.setFillColor(sf::Color::Black);
    this->uiTextButtonChangeBG.setPosition(250.f, 80.f);

    this->uiTextGrass.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextGrass.setCharacterSize(30);
    this->uiTextGrass.setFillColor(sf::Color::Black);
    this->uiTextGrass.setPosition(300.f, 240.f);
    this->uiTextGrass.setString("NONE");

    this->uiTextFire.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextFire.setCharacterSize(30);
    this->uiTextFire.setFillColor(sf::Color::Black);
    this->uiTextFire.setPosition(420.f, 240.f);
    this->uiTextFire.setString("NONE");

    this->uiTextWater.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextWater.setCharacterSize(30);
    this->uiTextWater.setFillColor(sf::Color::Black);
    this->uiTextWater.setPosition(540.f, 240.f);
    this->uiTextWater.setString("NONE");

    this->uiTextPlayerChoice.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextPlayerChoice.setCharacterSize(30);
    this->uiTextPlayerChoice.setFillColor(sf::Color::Black);
    this->uiTextPlayerChoice.setPosition(340.f, 300.f);

    this->uiTextAIChoice.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextAIChoice.setCharacterSize(30);
    this->uiTextAIChoice.setFillColor(sf::Color::Black);
    this->uiTextAIChoice.setPosition(340.f, 350.f);

    this->uiTextWinner.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextWinner.setCharacterSize(30);
    this->uiTextWinner.setFillColor(sf::Color::Black);
    this->uiTextWinner.setPosition(340.f, 400.f);

    this->uiTextScoreboard.setFont(this->_data->assets.GetFont("Dosis Light"));
    this->uiTextScoreboard.setCharacterSize(30);
    this->uiTextScoreboard.setFillColor(sf::Color::Black);
    this->uiTextScoreboard.setPosition(265.f, 500.f);

}

//Load music
void GameState::InitMusic()
{
    if (!music.openFromFile("Music/Pokemon.wav"))
    {
        std::cout << "ERROR::GAME::COULD NOT LOAD MUSIC" << "\n";
    }

    music.setVolume(50);
    music.play();

}

void GameState::getWinner()
{
    if (playerchoice == Grass && AIchoice == Grass)
    {
        this->uiTextWinner.setString("Tie");
        playerchoice = Empty;
        AIchoice = Empty;
        tie += 1;
    }
    else if (playerchoice == Grass && AIchoice == Water)
    {
        this->uiTextWinner.setString("Player Win");
        playerchoice = Empty;
        AIchoice = Empty;
        playerWins += 1;
    }

    else if (playerchoice == Grass && AIchoice == Fire)
    {
        this->uiTextWinner.setString("AI Win");
        playerchoice = Empty;
        AIchoice = Empty;
        aiWins += 1;
    }


    if (playerchoice == Fire && AIchoice == Fire)
    {
        this->uiTextWinner.setString("Tie");
        playerchoice = Empty;
        AIchoice = Empty;
        tie += 1;
    }
    else if (playerchoice == Fire && AIchoice == Grass)
    {
        this->uiTextWinner.setString("Player Win");
        playerchoice = Empty;
        AIchoice = Empty;
        playerWins += 1;
    }

    else if (playerchoice == Fire && AIchoice == Water)
    {
        this->uiTextWinner.setString("AI Win");
        playerchoice = Empty;
        AIchoice = Empty;
        aiWins += 1;
    }

    if (playerchoice == Water && AIchoice == Water)
    {
        this->uiTextWinner.setString("Tie");
        playerchoice = Empty;
        AIchoice = Empty;
        tie += 1;
    }
    else if (playerchoice == Water && AIchoice == Fire)
    {
        this->uiTextWinner.setString("Player Win");
        playerchoice = Empty;
        AIchoice = Empty;
        playerWins += 1;
    }

    else if (playerchoice == Water && AIchoice == Grass)
    {
        this->uiTextWinner.setString("AI Win");
        playerchoice = Empty;
        AIchoice = Empty;
        aiWins += 1;
    }

    if (playerchoice == Empty && AIchoice == Empty)
    {
        tie = tie;
        playerWins = playerWins;
        aiWins = aiWins;
    }

}


void GameState::getAiChoice()
{
    srand(time(NULL));
    int ai = rand() % 3 + 1;

    if (ai == 1)
    {
        this->uiTextAIChoice.setString("AI choose Grass");
        AIchoice = 1;
    }
    else if (ai == 2)
    {
        this->uiTextAIChoice.setString("AI choose Fire");
        AIchoice = 2;
    }
    else
    {
        this->uiTextAIChoice.setString("AI choose Water");
        AIchoice = 3;
    }
}


void GameState::HandleInput()
{
	sf::Event event;
	while (this->_data->window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->window.close();

		}

        if (event.Event::KeyPressed && event.Event::key.code == sf::Keyboard::Escape)
            this->_data->window.close();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        {
            this->uiTextPlayerChoice.setString("You choose Grass");
            this->getAiChoice();
            playerchoice = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
        {
            this->uiTextPlayerChoice.setString("You choose Fire");
            this->getAiChoice();
            playerchoice = 2;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            this->uiTextPlayerChoice.setString("You choose Water");
            this->getAiChoice();
            playerchoice = 3;
        }

	}

    this->getWinner();
    this->uiTextScoreboard.setString(PlayerWinString + std::to_string(playerWins) + AiWinString + std::to_string(aiWins) + tieString + std::to_string(tie));
    //Move Left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        this->player->move(-1.f, 0.f);

    //Move Right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        this->player->move(1.f, 0.f);

    //Move Up
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        this->player->move(0.f, -1.f);

    //Move Down
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        this->player->move(0.f, 1.f);


}

void GameState::drawText(sf::RenderTarget& target)
{
    target.draw(this->uiGameTitle);
    target.draw(this->uiTextInstruction);

    target.draw(this->uiTextGrass);
    target.draw(this->uiTextFire);
    target.draw(this->uiTextWater);

    target.draw(this->uiTextPlayerChoice);

    target.draw(this->uiTextAIChoice);
    target.draw(this->uiTextWinner);
    target.draw(this->uiTextScoreboard);

    target.draw(this->uiTextButtonChangeBG);
}

void GameState::updateText()
{
    this->uiGameTitle.setString("Pocket Duel");

    this->uiTextGrass.setString("Grass");
    this->uiTextFire.setString("Fire");
    this->uiTextWater.setString("Water");

    this->uiTextInstruction.setString("Press Z for Grass, Press X for Fire, Press C for Water");

    this->uiTextButtonChangeBG.setString("Press 1/2/3 to change background");
}


void GameState::update(float dt)
{
    //Get Game Title
    this->updateText();
}

void GameState::draw(float dt)
{
	this->_data->window.clear();
    this->_data->window.draw(this->_background);
    //this->_data->window.draw(this->_soundButton);
    //this->_data->window.draw(this->_homeButton);
    this->drawText(this->_data->window);
    this->pokemon->render(this->_data->window);
    this->player->render(this->_data->window);

	this->_data->window.display();
}

