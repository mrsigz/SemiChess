#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include "move.h"

enum PIECE_COLOR {WHITE, BLACK};

//Forward declaration
class Board;

class ChessPiece{
protected:
    //a pointer to the board this piece belongs to
    Board* board;

    //the position of the piece on the board
    string position;

    //maintains a vector of legal moves for this piece
    vector<Move> moves;
public:
    //Creates the chess piece at the given position
    ChessPiece(Board* board, string position);
    virtual ~ChessPiece(){}

    //move the piece to a random, legal position
    virtual void move() = 0;

    virtual

    //returns the character representation of the piece
    virtual char representation() = 0;

    //returns true if piece has been killed
    virtual bool isDead() const;
};

#endif // CHESSPIECE_H
