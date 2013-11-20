#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#pragma once
class Player
{
private:
	int _playerPosX;
	int _playerPosY;
	float _speed;
	sf::Sprite sprite;
    sf::Texture texture;

public:
	Player(float x, float y);
	~Player(void);

	//getters
	float getSpeed();
	int getPlayerPosX();
	int getPlayerPosY();

	//basic functions
	void Player::init();
	void Player::print(sf::RenderWindow &win);
};

