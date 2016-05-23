//This is a test file to make sure that we are able to collaborate changes with the code.
//Pull this file, make a small change to it, make a commit, then push your changes
//to the repo. I'll pull it, then try and run it as well.
#include <iostream>
#include "Board.h"
using namespace std;

int main() {

	cout << "This will be a tic-tac-toe game" << endl;
	Board board;
	for (int i = 0; i < 9; i++) {
		cout << *(board.getSpaces() + i);
		if ((i+1) % 3 == 0)
			cout << endl;
		else
			cout << " ";
	}
	system("pause");//Prompts for "press any key to continue..."
	return 0;
}