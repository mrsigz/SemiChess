#ifndef KING_H
#define KING_H
#include "chessPiece.h"

class King : public ChessPiece{
public:
    King(Board* board, PIECE_COLOR color)
        : ChessPiece(board, color, KING) { }
    ~King() {}
    PIECE_COLOR getColor() { return ChessPiece::getColor(); }
    PIECE_TYPE getType() { return ChessPiece::getType(); }
    char representation() {
        if(getColor() == WHITE) return 'K';
        return 'k';
    }
    vector<Move> getLegalMoves(const Board& board, vector<Move>& moves, int x, int y);
protected:
private:
};

#endif // PAWN_H
