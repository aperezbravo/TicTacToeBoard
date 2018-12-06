/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

// EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, toggle_X)
{
	TicTacToeBoard b;
	
	Piece outcome = b.toggleTurn();	
	ASSERT_EQ(outcome,O);
}

TEST(TicTacToeBoardTest, toggle_Y)
{
	TicTacToeBoard b;
	
	b.toggleTurn();	
	Piece outcome = b.toggleTurn();	
	ASSERT_EQ(outcome,X);
}


TEST(TicTacToeBoardTest, get_piece)
{
	TicTacToeBoard b;
	b.placePiece(0,1);
	Piece outcome = b.getPiece(0,1);
	ASSERT_EQ(outcome,X);
}

TEST(TicTacToeBoardTest, getPiece_DNE)
{
	TicTacToeBoard b;
	Piece outcome = b.getPiece(5,0);
	ASSERT_EQ(outcome,Invalid);
}




TEST(TicTacToeBoardTest, out_bounds)
{
	TicTacToeBoard b;
        Piece out_bounds = b.placePiece(5,0);
	ASSERT_EQ(out_bounds,Invalid);
}

TEST(TicTacToeBoardTest, winner)
{
	TicTacToeBoard b;
	b.placePiece(0,0);
	b.placePiece(0,1);
	Piece a = b.placePiece(0,2);
	ASSERT_EQ(a,X);
}

TEST(TicTacToeBoardTest, winner2)
{
	TicTacToeBoard b;
	b.placePiece(1,0);
	b.placePiece(1,1);
	Piece a = b.placePiece(1,2);
	ASSERT_EQ(a,X);
}

TEST(TicTacToeBoardTest, win_diagonally)
{
	TicTacToeBoard b;
	b.placePiece(0,0);
	b.placePiece(1,1);
	Piece a = b.placePiece(2,2);
	ASSERT_EQ(a,X);
}



TEST(TicTacToeBoardTest, tie)
{
	TicTacToeBoard b;
	Piece t = b.getWinner();
	ASSERT_EQ(t,Blank);
}

TEST(TicTacToeBoardTest, repeated)
{
	TicTacToeBoard b;
	Piece p1;
	b.placePiece(0,1);
	p1 = b.placePiece(0,1);
	ASSERT_EQ(p1,X);
}

/*
TEST(TicTacToeBoardTest,  )
{
	TicTacToeBoard b;
	Piece p1, p2;
	p1 = b.placePiece(0,1);
	p2 = b.placePiece(0,1);
	ASSERT_EQ(p2,X);
}
*/
