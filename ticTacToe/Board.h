#ifndef BOARD_H
#define BOARD_H

#include "All.h"

enum marker { empt, cross, knot };

class Board {
private: 
	marker spaces[9]; //Stores the nine spaces of the board
	char crossSymbol = 'X';
	char knotSymbol = 'O';

	char symbol(marker); //converts a marker to it's designated symbol
public:
	Board(); //Initialize board values

	marker getSpace(int square); //Returns a given element of spaces from 0-8

	void playSquare(int square, marker symbol); //Changes specified square to that symbol

	void printBoard(); //Prints board to console log
};

#endif //BOARD_H