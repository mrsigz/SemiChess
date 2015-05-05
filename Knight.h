#ifndef KNIGHT_H
#define KNIGHT_H
#include "chessPiece.h"

class Knight : public ChessPiece{
public:
    Knight(Board* board, PIECE_COLOR color)
        : ChessPiece(board, color, KNIGHT) { }
    ~Knight() {}
    PIECE_COLOR getColor() { return ChessPiece::getColor(); }
    PIECE_TYPE getType() { return ChessPiece::getType(); }
    char representation() {
        if(getColor() == WHITE) return 'N';
        return 'n';
    }
    void move() {}
protected:
private:
};

#endif // PAWN_H
