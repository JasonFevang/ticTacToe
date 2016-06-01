#include "All.h"



Player::Player(Board *board, marker symbol){
	pboard = board; //dependancy injection
	this->symbol = symbol; //Requires this-> because the symbol class variable is the same name as the constructor parameter
}

//Player destructor, will develop later
Player::~Player()
{
}

//Plays a symbol on the specified square 1-9
void Player::play(int square) {
	pboard->playSquare(square, symbol);
}

//returns the symbol of the current player
marker Player::getSymbol() {
	return symbol;
}

//Gets the Player's square 
int Player::choice() {
	int choice;
	cin >> choice;
	return choice;
}
