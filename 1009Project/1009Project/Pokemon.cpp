#include "Pokemon.h"
//Load pokemon image
void Pokemon::initTexture()
{

	if (!this->grassTex.loadFromFile("Image/Venusaur.png"))
	{
		std::cout << "ERROR::POKEMON::INITTEXTURE::Failed to load Image!" << "\n";
	}

	if (!this->fireTex.loadFromFile("Image/Charizard.png"))
	{
		std::cout << "ERROR::POKEMON::INITTEXTURE::Failed to load Image!" << "\n";
	}

	if (!this->waterTex.loadFromFile("Image/Blastoise.png"))
	{
		std::cout << "ERROR::POKEMON::INITTEXTURE::Failed to load Image!" << "\n";
	}
}

//Setup the image size
void Pokemon::initSprite()
{
	this->grass.setTexture(this->grassTex);
	this->grass.scale(2.f, 2.f);
	this->grass.setPosition(270.f, 120.f);

	this->fire.setTexture(this->fireTex);
	this->fire.scale(2.f, 2.f);
	this->fire.setPosition(390.f, 120.f);
	
	this->water.setTexture(this->waterTex);
	this->water.scale(2.f, 2.f);
	this->water.setPosition(510.f, 120.f);
}


Pokemon::Pokemon()
{
	this->initTexture();
	this->initSprite();
}

Pokemon::~Pokemon()
{

}

//Draw the image
void Pokemon::render(sf::RenderTarget& target)
{
	target.draw(this->grass);
	target.draw(this->fire);
	target.draw(this->water);
}
