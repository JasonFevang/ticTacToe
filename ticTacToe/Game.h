#ifndef GAME_H
#define GAME_H

#include "All.h"

class Game
{
private:
	Board board;
public:
	Game();

	Board getBoard(); //returns pointer to the game board
};

#endif //GAME_H