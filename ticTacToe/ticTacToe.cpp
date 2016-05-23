//This is a test file to make sure that we are able to collaborate changes with the code.
//Pull this file, make a small change to it, make a commit, then push your changes
//to the repo. I'll pull it, then try and run it as well.
#include "All.h"


int main() {
	return UnitTest::RunAllTests();
	cout << "This will be a tic-tac-toe game" << endl;
	Board newBoard;
	newBoard.printBoard();
	system("pause");//Prompts for "press any key to continue..."
	return 0;
}