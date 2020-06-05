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

	// Instantiates a game with two human players
	if (choice == 1) 
	{
		Game game;
		game.playGame(1);
	}

	// Instantiates a game object with one AI
	else if (choice == 2)
	{
		int order;
		cout << "Would you like to go first or second? (1 or 2): ";
		cin >> order;
		// Makes the player go second, and is by default a Knot
		if (order == 2)
		{
			Game game(1, 2);
			game.playGame(1);
		}
		// Makes the player go first, and gives default symbol of Cross
		else
		{
			Game game(1);
			game.playGame(1);
		}
	}

	// Lets person watch two AIs play a game against each other 
	else if (choice == 3)
	{
		Game game(2);
	}
	else
	{
		cout << "Not a valid choice." << endl;
	}
	
system		("pause");//Prompts for "press any key to continue..."
	return 0;
}