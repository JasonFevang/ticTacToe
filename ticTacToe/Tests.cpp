#include "All.h"

SUITE(ticTacToeGame)
{
	TEST(createGame)
	{
		marker targetGameboard[9] = { empt, empt, empt, empt, empt, empt, empt, empt, empt };
		Game g;
		
		for (int i = 0; i < 9; i++) {
			marker symbol = g.getBoard()->getSpace(i);
			CHECK_EQUAL(targetGameboard[i], symbol);
		}
	}

	TEST(playMiddle)
	{
		marker targetGameboard[9] = { empt, empt, empt, empt, cross, empt, empt, empt, empt };
		Game g;
		g.getPlayer()->play(4);

		for (int i = 0; i < 9; i++) {
			marker symbol = g.getBoard()->getSpace(i);
			CHECK_EQUAL(targetGameboard[i], symbol);
		}
	}
}