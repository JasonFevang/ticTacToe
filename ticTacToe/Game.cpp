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





void Game::playGame(int turns) {
	while (turns < 9 && winner() == empt) {

		// Process turns for player 1
		if (turns % 2 != 0) {

			cout << "Player One, what square would you like to play on? (1-9): ";
			int choice = playerOne->choice();
			if (board->getSpace(choice - 1) != empt) {
				cout << "That space is already taken. Please choose an open square" << endl;
				playGame(turns);
			}
			else {
				marker symbol = playerOne->getSymbol();
				board->playSquare(choice - 1, symbol);
				marker winner = this->winner();
				if (winner != empt) {
					cout << "Winner: " << winner << endl;
				}
				turns++;
				playGame(turns);
			}
		}

		// Process turns for player 2
		else if (turns % 2 == 0) {
			cout << "Player Two, what square would you like to play on? (1-9): ";
			int choice = playerTwo->choice();
			if (board->getSpace(choice - 1) != empt) {
				cout << "That space is already taken. Please choose an open square" << endl;
				playGame(turns);
			}
			else {
				marker symbol = playerTwo->getSymbol();
				board->playSquare(choice - 1, symbol);;
				marker winner = this->winner();
				if (winner != empt) {
					cout << "Winner: " << winner << endl;
				}
				turns++;
				playGame(turns);
			}
		}
		getBoard()->printBoard();
	}

	// Declare tie if three in a row has not been achieved
	if (turns >= 9 && winner() == empt) {
		getBoard()->printBoard();
		cout << "Tie. Game over." << endl;
	}
}

// Check if three squares in a row have been marked by one player's symbol to determine winner of game
bool Game::checkThree(const int boardIndexes[]) {
	if (board->getSpace(boardIndexes[0]) != empt && board->getSpace(boardIndexes[1]) != empt && board->getSpace(boardIndexes[2]) != empt) {
		if ((board->getSpace(boardIndexes[0]) == board->getSpace(boardIndexes[1])) && (board->getSpace(boardIndexes[0]) == board->getSpace(boardIndexes[2]))) {
			return true;
		}
	}
	return false;
}