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

//returns the marker of who won the game that turn. Empty means no one
marker Game::winner() {
	///horizontal///
	//check top horizontal
	if ((board->getSpace(0) != empt && board->getSpace(0) == board->getSpace(1) && board->getSpace(0) == board->getSpace(2)))
		return board->getSpace(0);
	//check middle horizontal
	if ((board->getSpace(3) != empt && board->getSpace(3) == board->getSpace(4) && board->getSpace(3) == board->getSpace(5)))
		return board->getSpace(3);
	//check bottom horizontal
	if ((board->getSpace(6) != empt && board->getSpace(6) == board->getSpace(7) && board->getSpace(6) == board->getSpace(8)))
		return board->getSpace(6);

	///vertical///
	//check left vertical
	if ((board->getSpace(0) != empt && board->getSpace(0) == board->getSpace(3) && board->getSpace(0) == board->getSpace(6)))
		return board->getSpace(0);
	//check middle vertical
	if ((board->getSpace(1) != empt && board->getSpace(1) == board->getSpace(4) && board->getSpace(1) == board->getSpace(7)))
		return board->getSpace(1);
	//check right vertical
	if ((board->getSpace(2) != empt && board->getSpace(2) == board->getSpace(5) && board->getSpace(2) == board->getSpace(8)))
		return board->getSpace(2);

	///check diagonals////
	//check forward slash vertical
	if (board->getSpace(0) == board->getSpace(4) && board->getSpace(0) == board->getSpace(8))
		return board->getSpace(1);
	//check right vertical
	if (board->getSpace(2) == board->getSpace(5) && board->getSpace(2) == board->getSpace(8))
		return board->getSpace(2);
}