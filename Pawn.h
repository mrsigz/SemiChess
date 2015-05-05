#ifndef PAWN_H
#define PAWN_H
#include "chessPiece.h"

class Pawn : public ChessPiece{
public:
    Pawn(Board* board, PIECE_COLOR color)
        : ChessPiece(board, color, PAWN) { }
    ~Pawn() {}
    PIECE_COLOR getColor() { return ChessPiece::getColor(); }
    PIECE_TYPE getType() { return ChessPiece::getType(); }
    char representation() {
        if(getColor() == WHITE) return 'P';
        return 'p';
    }
    vector<Move> getLegalMoves(const Board& board, vector<Move>& moves, int x, int y);
protected:
private:
};

#endif // PAWN_H
