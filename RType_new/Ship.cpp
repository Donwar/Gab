//
//  Ship.cpp
//

#include "Ship.h"
#include <iostream>
#include <stdexcept>

using namespace std;

//constructor sets ID number, loads sprite
Ship::Ship(const int id,float speed, float x, float y)
{
    alive=true;
    
    // Load a Ship to display
    if(!texture.loadFromFile("medium_ship.png"))
       exit(0);
    
    //create sprite and set texture so we know its size
    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.5,0.5));
	sprite.rotate(90);
	sprite.setPosition(x,y);
}

void Ship::Fire()
{
	Bullet *bullet = new Bullet(0, 400.f);
	if(!bullet->isAlive() )
    {
        bullet->spawn(true);
		bullet->setLocation(sprite.getPosition().x/2, sprite.getPosition().y*2);
    }
}

void Ship::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos,ypos);
}

sf::Sprite & Ship::getSprite()
{
    return sprite;
}

void Ship::kill()
{
    alive = false;
}

bool Ship::isAlive()
{
    return alive;
}

void Ship::draw(sf::RenderWindow &win)
{
    //set texture
    sprite.setTexture(texture);
    win.draw(sprite);
}

void Ship::respawn()
{
    alive=true;
}