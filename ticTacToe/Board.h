#ifndef BOARD_H
#define BOARD_H

#include "All.h"

enum marker { empty, cross, knot };

class Board {
private:
	marker spaces[9];
	char crossSymbol = 'X';
	char knotSymbol = 'O';

	char symbol(marker); //converts a marker to it's designated symbol
public:
	Board(); //Initialize board values

	marker* getSpaces(); //Returns a pointer to the first element of spaces

	void printBoard(); //Prints board to console log
};

#endif //BOARD_H