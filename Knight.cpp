#include "Knight.h"

vector<Move> Knight::getLegalMoves(const Board& board, vector<Move>& moves, int x, int y){
    if((x - 2) >= 0){
        if((y - 1) >= 0){
            if((board.getAt(x - 2, y - 1) == NULL) ||(board.getAt(x - 2, y - 1)->getColor() != getColor())){
                Move move(x - 2, y - 1);
                moves.push_back(move);
            }
        }
        if((y + 1) < 8){
            if((board.getAt(x - 2, y + 1) == NULL) ||(board.getAt(x - 2, y + 1)->getColor() != getColor())){
                Move move(x - 2, y + 1);
                moves.push_back(move);
            }
        }
    }
    if((x + 2) < 8){
        if((y - 1) >= 0){
            if((board.getAt(x + 2, y - 1) == NULL) ||(board.getAt(x + 2, y - 1)->getColor() != getColor())){
                Move move(x + 2, y - 1);
                moves.push_back(move);
            }
        }
        if((y + 1) < 8){
            if((board.getAt(x + 2, y + 1) == NULL) ||(board.getAt(x + 2, y + 1)->getColor() != getColor())){
                Move move(x + 2, y + 1);
                moves.push_back(move);
            }
        }
    }
    if((y - 2) >= 0){
        if((x + 1) < 8){
            if((board.getAt(x + 1, y - 2) == NULL) || (board.getAt(x + 1, y - 2)->getColor() != getColor())){
                Move move(x + 1, y - 2);
                moves.push_back(move);
            }
        }
        if((x - 1) >= 0){
            if((board.getAt(x - 1, y - 2) == NULL) || (board.getAt(x - 1, y - 2)->getColor() != getColor())){
                Move move(x - 1, y - 2);
                moves.push_back(move);
            }
        }
    }
    if((y + 2) < 8){
        if((x + 1) < 8){
            if((board.getAt(x + 1, y + 2) == NULL) || (board.getAt(x + 1, y + 2)->getColor() != getColor())){
                Move move(x + 1, y + 2);
                moves.push_back(move);
            }
        }
        if((x - 1) >= 0){
            if((board.getAt(x - 1, y + 2) == NULL) || (board.getAt(x - 1, y + 2)->getColor() != getColor())){
                Move move(x - 1, y + 2);
                moves.push_back(move);
            }
        }
    }
    return moves;
}
