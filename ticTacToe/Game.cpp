#include "All.h"


//public constructor, instantiates board and player
Game::Game(){
	board = new Board;
	playerOne = new Player(board, cross);
	playerTwo = new Player(board, knot);
}


//returns pointer to game board
Board* Game::getBoard() {
	return board;
}
//returns pointer to playerOne
Player* Game::getPlayerOne() {
	return playerOne;
}

//returns pointer to playerTwo
Player* Game::getPlayerTwo() {
	return playerTwo;
}

//returns the marker of who won the game that turn. Empty means no one
marker Game::winner() {
	if (checkThree(topHoriz) || checkThree(leftVert)) {
		return board->getSpace(0);
	}
	else if (checkThree(midHoriz) || checkThree(midVert) || checkThree(upDiag) || checkThree(downDiag)) {
		return board->getSpace(4);
	}
	else if (checkThree(botHoriz) || checkThree(rightVert)) {
		return board->getSpace(8);
	}
	else return empt;
}

bool Game::checkThree(const int boardIndexes[]) {
	if (board->getSpace(boardIndexes[0]) != empt && board->getSpace(boardIndexes[1]) != empt && board->getSpace(boardIndexes[2]) != empt) {
		if ((board->getSpace(boardIndexes[0]) == board->getSpace(boardIndexes[1])) && (board->getSpace(boardIndexes[0]) == board->getSpace(boardIndexes[2]))) {
			return true;
		}
	}
	else return false;
}