#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include "move.h"
#include "board.h"
#include "Constants.h"

//Forward declarations
class Board;

class ChessPiece{
protected:
    //a pointer to the board this piece belongs to
    Board* m_board;
    PIECE_COLOR m_color;
    PIECE_TYPE m_type;
public:
    //Creates the chess piece at the given position
    ChessPiece(Board* board, PIECE_COLOR color, PIECE_TYPE type)
                : m_board(board), m_color(color), m_type(type) {}
    virtual ~ChessPiece(){}

    //returns the color of this piece
    virtual PIECE_COLOR getColor() { return m_color; }

    //returns the type of this chess piece
    virtual PIECE_TYPE getType() { return m_type; }

    //returns a vector of legal moves for a given chess piece
    virtual vector<Move> getLegalMoves(Board* board, vector<Move>& moves) = 0;

    //returns the character representation of the piece
    virtual char representation() = 0;
};

#endif // CHESSPIECE_H
