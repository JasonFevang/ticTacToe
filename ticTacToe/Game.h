#ifndef GAME_H
#define GAME_H

#include "All.h"

class Game
{
private:
	Board *board; //pointer to the board being played on
	Player *player; //pointer to the player
public:
	Game();//public constructor, instantiates board and player

	Player* getPlayer(); //returns pointer to player
	Board* getBoard(); //returns game board
};

#endif //GAME_H