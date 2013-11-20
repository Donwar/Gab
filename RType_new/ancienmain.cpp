#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Ship.h"
#include "Enemy.h"
#include <iostream>


void left(sf::Event event, Ship ship)
{
	
	if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
		{
			if (ship.getSprite().getPosition().x + ship.getSprite().getGlobalBounds().width < 800)
			{
				//std::cout << ship.getSprite().getPosition().x << std::endl;
				ship.getSprite().move(-7, 0.f);
				ship.getSprite().setColor(sf::Color(0, 255, 0));
			}
		}
}

int main()
{
	bool gameOver = false;

	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	//create Ship
	Ship ship(0,300.f, 50, 150);

	Bullet bullet(0, 400.f);

	Enemy enemy(0, 500.f);
	enemy.setLocation(50, 450);
	//create a an array of enemys
	//Enemy enemyS[5];
	//for(int i=0; i<5; i++)
	//{
	//	Enemy enemy(i, 400.f);
	//	//enemy.setLocation(i*100+50, enemy.getSprite().getGlobalBounds().height/2);
	//	enemy.setLocation((i*100)+50, 150);
	//	enemyS[i] = enemy;
	//}

	//create background
	sf::Sprite back;
	sf::Texture star;

	// Load background to display
	if(!star.loadFromFile("stars.png"))
		return EXIT_FAILURE;
	//create sprite and scale
	back.setTexture(star);


	//select the framerate
	window.setFramerateLimit(60);

	// Start the game loop
	while (window.isOpen())
	{
		
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}

			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
			{	
					if(!bullet.isAlive() && !gameOver)
				{
					bullet.spawn(true);
					bullet.setLocation(ship.getSprite().getPosition().x-100, ship.getSprite().getPosition().y+40);
				}
			}
		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(back);

		//check for movement of ship
		left(event, ship);

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right)
		{
			if(ship.getSprite().getPosition().x > 0.f)
			{
				ship.getSprite().move(7, 0.f);
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Up)
		{
			if(ship.getSprite().getPosition().y > 0.f)
			{
				ship.getSprite().move( 0.f,-7);
			}
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down)
		{
			if(ship.getSprite().getPosition().y + ship.getSprite().getGlobalBounds().height < 600)
			{
				ship.getSprite().move(0.f, 7);
			}
		}

		//move enemy
		if(enemy.isAlive())
		{
			enemy.draw(window);
			enemy.getSprite().move(0, 400.f);
		}

		//move bullet
		if(bullet.isAlive() && !gameOver)
		{
			//draw bullet
			bullet.draw(window);
			//move bullet
			bullet.getSprite().move(10, 0);
		}
		std::cout << bullet.getSprite().getPosition().x << std::endl;

		//collision with bullet and boundary
		if(bullet.getSprite().getPosition().x > 800)
			bullet.kill();

		if(ship.isAlive())
		{
			//draw ship
			ship.draw(window);
		}

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;

}
