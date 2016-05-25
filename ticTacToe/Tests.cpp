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

	TEST(horizonalWin)
	{
		Game g;
		g.getPlayer()->play(0);
		CHECK_EQUAL(empt, g.winner());
		g.getPlayer()->play(1);
		CHECK_EQUAL(empt, g.winner());
		g.getPlayer()->play(2);
		CHECK_EQUAL(cross, g.winner());
	}
}