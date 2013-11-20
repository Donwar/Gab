#include "Game.h"
#include "Player.h"
#include "Window.h"

Game::Game(void)
{
	//Menu menu;
	_player = new Player(50, 150);

	
}

void Game::start()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	_player->init();
	_player->print(window);
	window.setFramerateLimit(60);
	while (window.isOpen()) {
			
	}
}

bool Game::getGameStatus()
{
	return _gameStatus;
}

Game::~Game(void)
{
}
