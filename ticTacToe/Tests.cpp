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
		g.getPlayerOne()->play(4);

		for (int i = 0; i < 9; i++) {
			marker symbol = g.getBoard()->getSpace(i);
			CHECK_EQUAL(targetGameboard[i], symbol);
		}
	}

	SUITE(winCheck) {
		TEST(horizontalWin) //Check for three in a row horinzontally
		{
			Game g1;
			g1.getPlayerOne()->play(0);
			CHECK_EQUAL(empt, g1.winner());
			g1.getPlayerOne()->play(1);
			CHECK_EQUAL(empt, g1.winner());
			g1.getPlayerOne()->play(2);
			CHECK_EQUAL(cross, g1.winner());

			Game g2;
			g2.getPlayerOne()->play(3);
			CHECK_EQUAL(empt, g2.winner());
			g2.getPlayerOne()->play(4);
			CHECK_EQUAL(empt, g2.winner());
			g2.getPlayerOne()->play(5);
			CHECK_EQUAL(cross, g2.winner());

			Game g3;
			g3.getPlayerOne()->play(6);
			CHECK_EQUAL(empt, g3.winner());
			g3.getPlayerOne()->play(7);
			CHECK_EQUAL(empt, g3.winner());
			g3.getPlayerOne()->play(8);
			CHECK_EQUAL(cross, g3.winner());
		}

		TEST(verticalWin) // Check for three in a row vertically
		{
			Game g1;
			g1.getPlayerOne()->play(0);
			CHECK_EQUAL(empt, g1.winner());
			g1.getPlayerOne()->play(3);
			CHECK_EQUAL(empt, g1.winner());
			g1.getPlayerOne()->play(6);
			CHECK_EQUAL(cross, g1.winner());

			Game g2;
			g2.getPlayerOne()->play(7);
			CHECK_EQUAL(empt, g2.winner());
			g2.getPlayerOne()->play(1);
			CHECK_EQUAL(empt, g2.winner());
			g2.getPlayerOne()->play(4);
			CHECK_EQUAL(cross, g2.winner());

			Game g3;
			g3.getPlayerOne()->play(2);
			CHECK_EQUAL(empt, g3.winner());
			g3.getPlayerOne()->play(5);
			CHECK_EQUAL(empt, g3.winner());
			g3.getPlayerOne()->play(8);
			CHECK_EQUAL(cross, g3.winner());
		}

		TEST(diagonalWin) //Check for three in a row diagonally
		{
			Game g1;
			g1.getPlayerOne()->play(0);
			CHECK_EQUAL(empt, g1.winner());
			g1.getPlayerOne()->play(4);
			CHECK_EQUAL(empt, g1.winner());
			g1.getPlayerOne()->play(8);
			CHECK_EQUAL(cross, g1.winner());

			Game g2;
			g2.getPlayerOne()->play(2);
			CHECK_EQUAL(empt, g2.winner());
			g2.getPlayerOne()->play(4);
			CHECK_EQUAL(empt, g2.winner());
			g2.getPlayerOne()->play(6);
			CHECK_EQUAL(cross, g2.winner());
		}
	}
}