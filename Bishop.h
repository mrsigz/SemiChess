#ifndef BISHOP_H
#define BISHOP_H
#include "chessPiece.h"

class Bishop : public ChessPiece{
public:
    Bishop() : ChessPiece() {}
    Bishop(Board* board, PIECE_COLOR color)
        : ChessPiece(board, color, BISHOP) { }
    ~Bishop() {}
    PIECE_COLOR getColor() { return ChessPiece::getColor(); }
    PIECE_TYPE getType() { return ChessPiece::getType(); }
    char representation() {
        if(getColor() == WHITE) return 'B';
        return 'b';
    }
    vector<Move> getLegalMoves(const Board& board, vector<Move>& moves, int x, int y);
protected:
private:
};

#endif // PAWN_H
