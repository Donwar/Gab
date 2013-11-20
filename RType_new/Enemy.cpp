#include "Enemy.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Enemy::Enemy(const int id,float sp)
{
    alive = true;

    if(!texture.loadFromFile("enemy.png"))
        throw invalid_argument("Enemy not loaded!");

    sprite.setTexture(texture);
    sprite.scale(sf::Vector2f(0.5,0.5));
}

sf::Sprite & Enemy::getSprite()
{
    return sprite;
}

void Enemy::setLocation(float xpos, float ypos)
{
    sprite.setPosition(xpos,ypos);
}

void Enemy::kill()
{
    alive = false;
}

bool Enemy::isAlive()
{
    return alive;
}

void Enemy::draw(sf::RenderWindow &win)
{
    sprite.setTexture(texture);
    win.draw(sprite);
}

float Enemy::getSpeed() const
{
    return speed;
}