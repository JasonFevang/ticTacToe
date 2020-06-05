#include "All.h"


//public constructor, instantiates board and player, order of turns in AI game, and which player is AI-controlled
Game::Game(int AIs, int order)
{
	board = new Board;
	if (AIs == 1)
	{
		if (order == 1)
		{
			playerOne = new Player(board, cross);
			playerTwo = new Player(board, knot, true);
		}
		else
		{
			playerOne = new Player(board, cross, true);
			playerTwo = new Player(board, knot);
		}
	}
	else if (AIs == 2)
	{
		playerOne = new Player(board, cross, true);
		playerTwo = new Player(board, knot, true);
	}
	else
	{
		playerOne = new Player(board, cross);
		playerTwo = new Player(board, knot);
	}
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

	// Check AI status of both players and store in a variable
	bool p1isAI = playerOne->isAIPlayer();
	bool p2isAI = playerTwo->isAIPlayer();

	marker winner = this->winner();

	//cout << p1isAI << endl;
	//cout << p2isAI << endl;

	while (turns < 10 && winner == empt)
	{

		// Clear screen before printing board to clean up terminal/console window, works only on Windows
		system("cls");
		getBoard()->printBoard();
		cout << endl;

		// Process turns for player 1
		if (turns % 2 != 0 && turns < 10) {

			// AI check for player 1
			if (p1isAI != true)
			{
				cout << "Turn: " << turns << endl;
				cout << "Player One, what square would you like to play on? (1-9): ";
				int choice = playerOne->choice();
				if (board->getSpace(choice - 1) != empt) {
					playGame(turns);
				}
				else
				{
					marker symbol = playerOne->getSymbol();
					board->playSquare(choice - 1, symbol);
					winner = this->winner();
					if (winner != empt)
					{
						break;
					}
					turns++;
				}
			}
			else
			{
				int choice = playerOne->randomAI();
				if (board->getSpace(choice) != empt)
				{
					playGame(turns);
				}
				else
				{
					marker symbol = playerOne->getSymbol();
					board->playSquare(choice, symbol);
					winner = this->winner();
					if (winner != empt)
					{
						break;
					}
					turns++;
				}
			}
		}

		// Process turns for player 2
		else if (turns % 2 == 0 && turns < 10)
		{
			// AI check for player 2
			if (p2isAI != true)
			{
				cout << "Turn: " << turns << endl;
				cout << "Player Two, what square would you like to play on? (1-9): ";
				int choice = playerTwo->choice();
				if (board->getSpace(choice - 1) != empt)
				{
					playGame(turns);
				}
				else
				{
					marker symbol = playerTwo->getSymbol();
					board->playSquare(choice - 1, symbol);
					winner = this->winner();
					if (winner != empt)
					{
						break;
					}
					turns++;
				}
			}
			else
			{
				int choice = playerTwo->randomAI();
				if (board->getSpace(choice) != empt)
				{
					playGame(turns);
				}
				else
				{
					marker symbol = playerTwo->getSymbol();
					board->playSquare(choice, symbol);
					winner = this->winner();
					if (winner != empt)
					{
						break;
					}
					turns++;
				}
			}
		}
		else
		{
			break;
		}
	}

	// Declare tie if three in a row has not been achieved
 	if (turns == 10 && winner == empt)
	{
		cout << "Tie. Game over. Turn " << turns << endl;
		getBoard()->printBoard();
		playerOne->~Player();
		playerTwo->~Player();
		system("pause");//Prompts for "press any key to continue..."
	}
	else if (winner != empt)
	{
		cout << "Winner: Player " << winner << " Turns: " << turns << endl;
		getBoard()->printBoard();
		playerOne->~Player();
		playerTwo->~Player();
		system("pause");//Prompts for "press any key to continue..."
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