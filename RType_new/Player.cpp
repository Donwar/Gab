#include "Player.h"


Player::Player(float x, float y)
{
	_playerPosX = x;
	_playerPosX = x;
}

Player::~Player(void)
{
}

void Player::init()
{
    // Load a Ship to display
    if(!texture.loadFromFile("medium_ship.png"))
       exit(0);
    
    //create sprite and set texture so we know its size
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.5,0.5));
	sprite.rotate(90);
	sprite.setPosition(_playerPosX, _playerPosY);
}

void Player::print(sf::RenderWindow &win)
{
    sprite.setTexture(texture);
    win.draw(sprite);
}

int Player::getPlayerPosX()
{
	return _playerPosX;
}

int Player::getPlayerPosY()
{
	return _playerPosY;
}

float Player::getSpeed()
{
	return _speed;
}