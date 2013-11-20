
#ifndef SpriteMove_Ship_h
#define SpriteMove_Ship_h

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include <iostream>
#include <string>

class Ship
{
public:
    //constructor sets ID number, loads sprite
    Ship(const int,float, float, float);
	void Fire();
    sf::Sprite & getSprite();
    void setLocation(float, float);
    void kill();
    bool isAlive();
    void respawn();
    void draw(sf::RenderWindow &win);
private:
    sf::Sprite sprite;
    sf::Texture texture;
    bool alive;
public:
	bool fireb;
};

#endif
