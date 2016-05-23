#include "Board.h"
//Returns an array storing the board
marker* Board::getSpaces() {
	return &spaces[0];
}

//Initialize board values
Board::Board() {
	for (int i = 0; i < 9; i++) {
		spaces[i] = marker::empty;
	}
}