#include "All.h"



Player::Player(Board *board, marker symbol, bool isAI){
	pboard = board; //dependancy injection
	this->symbol = symbol;
	this->isAI = isAI; //Sets the player to be an AI or human
}

// Player destructor, deletes memory allocation to pboard
Player::~Player()
{
	delete pboard;
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

// Returns if player is an AI or not
bool Player::isAIPlayer()
{
	return isAI;
}

// Returns a random square
int Player::randomAI()
{
	int rand_num = rand() % 9; // Generates a random number between 1 and 9
	return rand_num;
}
