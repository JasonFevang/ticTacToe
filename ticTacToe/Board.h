#ifndef BOARD_H
#define BOARD_H

enum marker { empty, cross, knot };

class Board {
	marker spaces[9];
public:
	Board(); //Initialize board values

	marker* getSpaces(); //Returns an array storing the board
};

#endif //BOARD_H