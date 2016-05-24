#include "All.h"



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
