#include "white.h"

White::White(Board* board, PIECE_TYPE type, int x, int y) : ChessPiece(board, type, x, y){
    //ctor
}

White::~White(){
    //dtor
}

PIECE_COLOR White::getColor(){
    return WHITE;
}

    //returns the type of this chess piece
PIECE_TYPE White::getType(){
    return m_type;
}

    //move the piece to a random, legal position
void White::move(){

}

//returns the character representation of the piece
char White::representation(){
    switch(m_type){
    case 0:
        return 'K';
    case 1:
        return 'Q';
    case 2:
        return 'B';
    case 3:
        return 'N';
    case 4:
        return 'R';
    default:
        return 'P';
    }
}
