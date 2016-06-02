#ifndef GAME_H
#define GAME_H

#include "All.h"

const int topHoriz[3] = { 0, 1, 2 };
const int midHoriz[3] = { 3, 4, 5 };
const int botHoriz[3] = { 6, 7, 8 };

const int leftVert[3] = { 0, 3, 6 };
const int midVert[3] = { 1, 4, 7 };
const int rightVert[3] = { 2, 5, 8 };

const int downDiag[3] = { 0, 4, 8 };
const int upDiag[3] = { 6, 4, 2 };

class Game
{
private:
	Board *board; //pointer to the board being played on
	Player *playerOne; //pointer to playerOne
	Player *playerTwo; //pointer to playerTwo
	bool playerFirst; //True means player goes first and is crosses

	bool checkThree(const int[]); //Checks three squares on the board to be equal and not empt
public:
	Game();//public constructor, instantiates board and players

	Player* getPlayerOne(); //returns pointer to playerOne
	Player* getPlayerTwo(); //returns pointer to playerTwo

	Board* getBoard(); //returns pointer to game board

	marker winner(); //returns the marker of who won the game that turn. Empty means no one

	void playGame(int turns); //Order of events

};

#endif //GAME_H