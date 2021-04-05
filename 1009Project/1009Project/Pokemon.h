#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
/*
* Class to display pokemon images
*/
class Pokemon
{
private:
	sf::Sprite grass;
	sf::Sprite fire;
	sf::Sprite water;

	sf::Texture grassTex;
	sf::Texture fireTex;
	sf::Texture waterTex;

	void initTexture();
	void initSprite();


public:
	Pokemon();
	virtual ~Pokemon();
	void render(sf::RenderTarget& target);
};

