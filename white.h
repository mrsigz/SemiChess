#ifndef WHITE_H
#define WHITE_H

#include "chessPiece.h"


class White : public ChessPiece{
public:
    White(Board* board, PIECE_TYPE type, int x, int y);
    ~White();
    //returns the color of this piece
    virtual PIECE_COLOR getColor();

    //returns the type of this chess piece
    virtual PIECE_TYPE getType();

    //move the piece to a random, legal position
    virtual void move();

    //returns the character representation of the piece
    virtual char representation();
protected:
private:
};

#endif // WHITE_H
