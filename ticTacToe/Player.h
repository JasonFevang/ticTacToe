#ifndef PLAYER_H
#define PLAYER_H

#include "All.h"

class Player
{
private:
	Board *pboard; //Pointer to the current board
	marker symbol;
public:
	Player(Board *board, marker symbol);
	~Player();

	void play(int square); //Plays a cross on the specified square 1-9
};

#endif //PLAYER_H