#ifndef PLAYER_H
#define PLAYER_H

#include "All.h"

class Player
{
private:
	Board *pboard; //Pointer to the current board
	marker symbol; //The symbol this player plays as, either cross or knot
public:
	Player(Board *board, marker symbol);
	~Player();

	marker getSymbol(); //returns the symbol of the current player

	int choice(); //returns the position that the player last played in

	void play(int square); //Plays a cross on the specified square 1-9
};

#endif //PLAYER_H