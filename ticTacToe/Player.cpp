#include "All.h"



Player::Player(Board *board, marker symbol){
	pboard = board; //dependancy injection
	this->symbol = symbol;
}


Player::~Player()
{
}

//Plays a symbol on the specified square 1-9
void Player::play(int square) {
	cout << symbol << endl;
	pboard->playSquare(square, symbol);
}