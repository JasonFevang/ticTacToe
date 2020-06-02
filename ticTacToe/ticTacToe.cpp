//This is a test file to make sure that we are able to collaborate changes with the code.
//Pull this file, make a small change to it, make a commit, then push your changes
//to the repo. I'll pull it, then try and run it as well.
#include "All.h"



int main() {
	int choice;
	cout << "Welcome to Tic-Tac-Toe v 0.9 by Jason Fevang and Kevin Gnanaraj" << endl;
	cout << "Would you like to play against another person or against an AI, or would you like to watch two AIs play each other?:" << endl;
	cout << "1: Play against another person" << endl;
	cout << "2: Play against an AI" << endl;
	cout << "3: Watch two AIs play each other" << endl;
	cin >> choice;
	if (choice == 1) 
	{
		Game game;
		game.playGame(1);
	}
	else if (choice == 2)
	{
		Game game;
		int order;
		cout << "Would you like to go first or second? (1 or 2): ";
		cin >> order;
		if (order == 1)
		{

		}
	}
	else if (choice == 3)
	{

	}
	
system		("pause");//Prompts for "press any key to continue..."
	return 0;
}