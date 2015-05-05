#ifndef QUEEN_H
#define QUEEN_H
#include "chessPiece.h"

class Queen : public ChessPiece{
public:
    Queen(Board* board, PIECE_COLOR color)
        : ChessPiece(board, color, QUEEN) { }
    ~Queen() {}
    PIECE_COLOR getColor() { return ChessPiece::getColor(); }
    PIECE_TYPE getType() { return ChessPiece::getType(); }
    char representation() {
        if(getColor() == WHITE) return 'Q';
        return 'q';
    }
    void move(){}
protected:
private:
};

#endif // PAWN_H
