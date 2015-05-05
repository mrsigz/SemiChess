#include "King.h"

vector<Move> King::getLegalMoves(const Board& board, vector<Move>& moves, int x, int y){
    if((x + 1) < 8){
        if(board.getAt(x + 1, y) == NULL || board.getAt(x + 1, y)->getColor() != getColor()){
            Move move(x + 1, y);
            moves.push_back(move);
        }
        if((y + 1) < 8 && (board.getAt(x + 1, y + 1) == NULL || board.getAt(x + 1, y + 1)->getColor() != getColor())){
            Move move(x + 1, y + 1);
            moves.push_back(move);
        }
        if((y - 1) >= 0 && (board.getAt(x + 1, y - 1) == NULL || board.getAt(x + 1, y - 1)->getColor() != getColor())){
            Move move(x + 1, y - 1);
            moves.push_back(move);
        }
    }

    if((x - 1) >= 0){
        if(board.getAt(x - 1, y) == NULL || board.getAt(x - 1, y)->getColor() != getColor()){
            Move move(x - 1, y);
            moves.push_back(move);
        }
        if((y + 1) < 8 && (board.getAt(x + 1, y + 1) == NULL || board.getAt(x + 1, y + 1)->getColor() != getColor())){
            Move move(x - 1, y + 1);
            moves.push_back(move);
        }
        if((y - 1) >= 0 && (board.getAt(x + 1, y - 1) == NULL || board.getAt(x + 1, y - 1)->getColor() != getColor())){
            Move move(x - 1, y - 1);
            moves.push_back(move);
        }
    }

    if((y + 1) < 8 && (board.getAt(x, y + 1) == NULL || board.getAt(x, y + 1)->getColor() != getColor())){
        Move move(x, y + 1);
        moves.push_back(move);
    }

    if((y - 1) >= 0 && (board.getAt(x, y - 1) == NULL || board.getAt(x, y - 1)->getColor() != getColor())){
        Move move(x, y - 1);
        moves.push_back(move);
    }
    return moves;
}
