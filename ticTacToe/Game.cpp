#include "All.h"


//public constructor, instantiates board and player
Game::Game(){
	board = new Board;
	player = new Player(board, cross);
}


//returns pointer to game board
Board* Game::getBoard() {
	return board;
}
//returns pointer to player
Player* Game::getPlayer() {
	return player;
}
