#ifndef BOARD_H
#define BOARD_H
#include "chessPiece.h"

struct Position{
    int x;
    int y;
};

class Board{
private:

public:
    Board();
    ~Board();
    ChessPiece* getAt(string input);

};

#endif // BOARD_H
