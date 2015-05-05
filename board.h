#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <time.h>
#include <cstdlib> //for random
#include "chessPiece.h"
#include "Constants.h"

using namespace std;

//Forward declaration
class ChessPiece;

class Board{
private:
    //The board is initialized to contain chess pieces
    ChessPiece* grid[8][8];
    //turn counter
    int m_turn;
public:
    //Create a fresh chess board, allocating memory for each chess piece
    //and populate the board
    Board();
    ~Board();
    //returns the turn counter
    int getTurn();
    //display the board
    void display() const;
    //returns the piece at position x, y
    ChessPiece* getAt(int x, int y) const;
    //sets the chess piece at given x,y coordinates
    void setAt(ChessPiece* piece, int x, int y);
    //simulates one move for the selected chess piece
    void simulateOneMove(ChessPiece* piece, vector<Move> moves, int x, int y);
    //generates the chess pieces on a new board
    void generateChessPiece(PIECE_COLOR color);
    //increment the turn counter
    void incrementTurn(){ ++m_turn; }
};

#endif // BOARD_H
