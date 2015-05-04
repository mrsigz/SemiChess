#include "black.h"

Black::Black(Board* board, PIECE_TYPE type, int x, int y) : ChessPiece(board, type, x, y){
    //ctor
}

Black::~Black(){
    //dtor
}

PIECE_COLOR Black::getColor(){
    return BLACK;
}

    //returns the type of this chess piece
PIECE_TYPE Black::getType(){
    return m_type;
}

    //move the piece to a random, legal position
void Black::move(){

}

//returns the character representation of the piece
char Black::representation(){
    switch(m_type){
    case 0:
        return 'k';
    case 1:
        return 'q';
    case 2:
        return 'b';
    case 3:
        return 'n';
    case 4:
        return 'r';
    default:
        return 'p';
    }
}
