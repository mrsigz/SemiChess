#include "Bishop.h"

vector<Move> Bishop::getLegalMoves(const Board& board, vector<Move>& moves, int x, int y){
    int n = 1;
    while((x + n) < 8 && (y + n ) < 8 && board.getAt(x + n, y + n) == NULL){
        Move move(x + n, y + n);
        moves.push_back(move);
        n++;
        if(board.getAt(x + n, y + n) != NULL && (board.getAt(x + n, y + n)->getColor() != getColor())){
            Move move(x + n, y + n);
            moves.push_back(move);
        }
    }
    n = 1;
    while((x - n ) >= 0  && (y - n ) >= 0  && board.getAt(x - n, y - n) == NULL){
        Move move(x - n, y - n);
        moves.push_back(move);
        n++;
        if(board.getAt(x - n, y - n) != NULL && (board.getAt(x - n, y - n)->getColor() != getColor())){
            Move move(x - n, y - n);
            moves.push_back(move);
        }
    }
    n = 1;
    while((x + n ) < 8 && (y - n ) >= 0 && board.getAt(x  + n, y - n) == NULL){
        Move move(x + n, y - n);
        moves.push_back(move);
        n++;
        if(board.getAt(x + n, y - n) != NULL && (board.getAt(x + n, y - n)->getColor() != getColor())){
            Move move(x + n, y - n);
            moves.push_back(move);
        }
    }
    n = 1;
    while((x - n ) >= 0  && (y + n ) < 8 && board.getAt(x + n, y + n) == NULL){
        Move move(x - n, y + n);
        moves.push_back(move);
        n++;
        if(board.getAt(x - n, y + n) != NULL && (board.getAt(x - n, y + n)->getColor() != getColor())){
            Move move(x - n, y + n);
            moves.push_back(move);
        }
    }
    return moves;
}
