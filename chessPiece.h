#ifndef CHESSPIECE_H
#define CHESSPIECE_H
#include "move.h"
#include "board.h"

enum PIECE_COLOR {WHITE, BLACK};
enum PIECE_TYPE {KING, QUEEN, BISHOP, KNIGHT, CASTLE, PAWN};
enum CHAR {a, b, c, d, e, f, g, h};

//Forward declarations
class Board;

class ChessPiece{
protected:
    //a pointer to the board this piece belongs to
    Board* m_board;
    int m_x;
    int m_y;
    PIECE_TYPE m_type;
public:
    //Creates the chess piece at the given position
    ChessPiece(Board* board, PIECE_TYPE type, int x, int y)
                : m_board(board), m_x(x), m_y(y), m_type(type) {}
    ~ChessPiece(){}

    //returns the color of this piece
    virtual PIECE_COLOR getColor() = 0;

    //returns the type of this chess piece
    virtual PIECE_TYPE getType() = 0;

    //move the piece to a random, legal position
    virtual void move() = 0;

    //returns the character representation of the piece
    virtual char representation() = 0;
};

#endif // CHESSPIECE_H
