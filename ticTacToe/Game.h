#ifndef GAME_H
#define GAME_H

#include "All.h"

class Game
{
private:
	Board *board; //pointer to the board being played on
	Player *player; //pointer to the player
	bool playerFirst; //True means player goes first and is crosses
public:
	Game();//public constructor, instantiates board and player

	Player* getPlayer(); //returns pointer to player
	Board* getBoard(); //returns game board

	marker winner(); //returns the marker of who won the game that turn. Empty means no one
};

#endif //GAME_H