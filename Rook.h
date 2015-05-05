#ifndef ROOK_H
#define ROOK_H
#include "chessPiece.h"

class Rook : public ChessPiece{
public:
    Rook(Board* board, PIECE_COLOR color)
        : ChessPiece(board, color, ROOK) { }
    ~Rook() {}
    PIECE_COLOR getColor() { return ChessPiece::getColor(); }
    PIECE_TYPE getType() { return ChessPiece::getType(); }
    char representation() {
        if(getColor() == WHITE) return 'R';
        return 'r';
    }
    void move(){}
protected:
private:
};

#endif // PAWN_H
