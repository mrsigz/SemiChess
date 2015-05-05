#include "Pawn.h"

vector<Move> Pawn::getLegalMoves(const Board& board, vector<Move>& moves, int x, int y){
    int mod = (getColor() == BLACK)? -1 : 1;
    if(board.getAt(x + (1 * mod), y) == NULL){
        Move move(x + (1 * mod), y);
        moves.push_back(Move(move));
        if(x == 1 && board.getAt(x + (2 * mod), y) == NULL){
            Move move(x + (2 * mod), y);
            moves.push_back(Move(move));
        }
    }
      if(board.getAt(x + (1 * mod), y + 1) != NULL && board.getAt(x - 1, y + 1)->getColor() != getColor()){
        Move move(x + (1 * mod), y + 1);
        moves.push_back(Move(move));
    }
    if(board.getAt(x + (1 * mod), y - 1) != NULL && board.getAt(x - 1, y - 1)->getColor() == getColor()){
        Move move(x + (1 * mod), y - 1);
        moves.push_back(Move(move));
    }
    return moves;
}
