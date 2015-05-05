#include "Rook.h"

vector<Move> Rook::getLegalMoves(const Board& board, vector<Move>& moves, int x, int y){
    int n = 1;
    while((y + n ) < 8 && board.getAt(x, y + n) == NULL){
        Move move(x, y + n);
        moves.push_back(move);
        n++;
        if(board.getAt(x, y + n) != NULL && (board.getAt(x, y + n)->getColor() != getColor())){
            Move move(x, y + n);
            moves.push_back(move);
        }
    }
    n = 1;
    while((y - n ) >= 0  && board.getAt(x, y - n) == NULL){
        Move move(x, y - n);
        moves.push_back(move);
        n++;
        if(board.getAt(x, y - n) != NULL && (board.getAt(x, y - n)->getColor() != getColor())){
            Move move(x, y - n);
            moves.push_back(move);
        }
    }
    n = 1;
    while((x + n ) < 8 && board.getAt(x  + n, y) == NULL){
        Move move(x + n, y);
        moves.push_back(move);
        n++;
        if(board.getAt(x + n, y) != NULL && (board.getAt(x + n, y)->getColor() != getColor())){
            Move move(x + n, y);
            moves.push_back(move);
        }
    }
    n = 1;
    while((x - n ) >= 0  && board.getAt(x + n, y) == NULL){
        Move move(x - n, y);
        moves.push_back(move);
        n++;
        if(board.getAt(x - n, y) != NULL && (board.getAt(x - n, y)->getColor() != getColor())){
            Move move(x - n, y);
            moves.push_back(move);
        }
    }
    return moves;
}
