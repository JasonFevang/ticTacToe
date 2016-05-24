#include "All.h"

SUITE(ticTacToeGame)
{
	TEST(createGame)
	{
		Game g;
		marker* firstSpace = g.getBoard()->getSpaces();
		for (int i = 0; i < 9; i++) {
			if (firstSpace+i == NULL)
				cout << "failure!";
			
			CHECK_EQUAL(0, *(firstSpace + i));
		}
	}

	TEST(playMiddle)
	{
		Game g;
		g.getPlayer()->play(4);
		marker* firstSpace = g.getBoard()->getSpaces();
		CHECK_EQUAL(1, *(firstSpace + 4));
	}
}