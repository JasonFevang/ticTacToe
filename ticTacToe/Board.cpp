#include "All.h"

//Initialize board values
Board::Board() {
	for (int i = 0; i < 9; i++) {
		spaces[i] = marker::empt;
	}
}

//Returns an array storing the board
marker Board::getSpace(int square) {
	return spaces[square];
}

//Changes specified square to that symbol
void Board::playSquare(int square, marker symbol) {
	spaces[square] = symbol;
}

//Prints board to console log
void Board::printBoard() {
	string vertDivider = "|";
	string horizDivider = "-------";

	cout << " ";//start with a space to properly space out board
	for (int i = 0; i < 9; i++) { //loop through all nine board spaces
		cout << symbol(spaces[i]);
		if ((i + 1) % 3 == 0) { //If it is the end of a row
			cout << endl;
			if (i != 8) { //Add a dividing row after each row except the last
				cout << horizDivider << endl << " ";
			}
		}
		else {
			cout << vertDivider;
		}
	}
}

//converts a marker to it's designated symbol
char Board::symbol(marker input) {
	if (input == marker::cross)
	{
		return crossSymbol;
	}
	else if (input == marker::knot)
	{
		return knotSymbol;
	}
	else 
	{
		return ' ';
	}
}
