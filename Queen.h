#ifndef QUEEN_H
#define QUEEN_H
#include "chessPiece.h"
#include "Rook.h"
#include "Bishop.h"

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
    vector<Move> getLegalMoves(const Board& board, vector<Move>& moves, int x, int y){
        moves = m_rook.getLegalMoves(board, moves, x, y);
        vector<Move> tmp;
        tmp = m_bishop.getLegalMoves(board, moves, x, y);
        moves.insert(moves.end(), tmp.begin(), tmp.end());
        return moves;
    }
protected:
private:
    Rook m_rook;
    Bishop m_bishop;
};

#endif // PAWN_H
