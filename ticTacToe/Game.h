#ifndef GAME_H
#define GAME_H

#include "All.h"

class Game
{
private:
	Board *board;
	Player *player; //pointer to the player
public:
	Game();
	Player* getPlayer(); //returns pointer to player
	Board* getBoard(); //returns game board
};

#endif //GAME_H