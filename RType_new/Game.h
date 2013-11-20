#include "Player.h"

class Game
{
private:
	bool _gameStatus;
	Player *_player;

public:


	//getters;
	bool getGameStatus();


	//setters;
	void start();
	Game(void);
	~Game(void);
};
