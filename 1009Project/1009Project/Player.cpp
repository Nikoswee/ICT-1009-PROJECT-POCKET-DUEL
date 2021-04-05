#include "Player.h"

void Player::initTexture()
{
	if (!this->texture.loadFromFile("Image/Trainer.png"))
	{
		std::cout << "ERROR::PLAYER::INITTexture::Failed to load image!" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);

	this->sprite.scale(1.f, 1.f);
}

Player::Player()
{
	this->movementSpeed = 1.f;

	this->initTexture();
	this->initSprite();
}

Player::~Player()
{

}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
