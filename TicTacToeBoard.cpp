#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  spaces_available = 9;
  w_l = false;
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X)
  {
    turn = O;
  }
  else if(turn == O)
  {
    turn = X;
  }
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  Piece placed;
  //if(board[row][column] == Blank)
  if(row > 2 || column > 2)
  {
    return Invalid;
  }
  placed = board[row][column];
  if(placed == Blank)
  {
    board[row][column] = turn;
    spaces_available -= 1;
    placed = turn;
    if(board[0][0] == board[0][1] && board [0][0] == board[0][2])
    {
      w_l = true;
      return getWinner();
    }
    else if(board[1][0] == board[1][1] && board[1][0] == board[1][2])
    {
      w_l = true;
      return getWinner();
    }
    else if(board[2][0] == board[2][1] && board[2][0] == board[2][2])
    {
      w_l = true;
      return getWinner();
    }
    else if(board[0][0] == board[1][0] && board[0][0] == board[2][0])
    {
      w_l = true;
      return getWinner(); 
    }
    else if(board[0][1] == board[1][1] && board[0][1] == board[2][1])
    {
      w_l = true;
      return getWinner();
    }
    else if(board[0][2] == board[1][2] && board[0][2] == board[2][2])
    {
      w_l = true;
      return getWinner();
    }
    else if(board[0][0] == board[1][2] && board[0][0] == board[2][2])
    {
      w_l = true;
      return getWinner();
    }
    else if(spaces_available == 0)
    {
      return getWinner(); 
    }
    else
    {
      toggleTurn();
      return placed;
    }  
  }
  else if(placed != Blank)
  {
    return placed; 
  }
  /*else if(row > 2 || column > 2)
  {
    return Invalid;
  }*/
  else 
  {
    return Invalid;
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  Piece a = board[row][column];
  if(row > 2 || column > 2)
  { 
    return Invalid;
  }
  else if(a != Blank)
  {
    return a;
  }
  else
  {
    return Blank;
  }
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if(w_l == true)
  {
    return turn;
  }
  else if(w_l == false)
  {
    return Blank;
  }
  else
  {
    return Invalid; 
  }
}
