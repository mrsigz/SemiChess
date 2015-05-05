#include "board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"

Board::Board(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            grid[i][j] = NULL;
            //cout << "i; " << i << "j: " << j << endl;
        }
    }
    generateChessPiece(WHITE);
    generateChessPiece(BLACK);
}

Board::~Board(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(grid[i][j] != NULL){
                delete grid[i][j];
            }
        }
    }
}

int Board::getTurn(){
    return turn;
}

//print out the board in ascii character form
void Board::display() const{
    for(int i = 10; i >= 0; --i){
        for(int j = 0; j < 11; ++j){
            if(i == 1 || i == 10){                       //print upper and lower frame
                if(j == 10){
                    cout << endl;
                }else{
                    cout << "--";
                }
            }else if((j == 1 || j == 10) && i != 0){   //print right and left frame
                if(j == 10){
                    cout << " |" << endl;;
                }else{
                    cout << "|";
                }
            }else if(i == 0){                          //print board letters
                if(j == 0 || j == 9){
                    cout << "  ";
                }else if(j == 10){
                    cout << endl;
                }else{
                    char letter = 96 + j;
                    cout << " " << letter;
                }
            }else if(j == 0 && i != 1 && i != 10){       //print board numbers
                cout << i - 1;
            }else{                                      //print chess pieces on board, spaces if empty
                if(grid[i - 2][j - 2] != NULL){
                    cout << " " << grid[i - 2][j - 2]->representation();
                }else{
                    cout << "  ";
                }
                //cout << "  ";
            }
        }
    }
    cout << endl;
}

ChessPiece* Board::getAt(int x, int y) const{
    if(x < 8 && x >= 0 && y >= 0 && y < 8){
        if(grid[x][y] != NULL){
            return grid[x][y];
        }
    }
    return NULL;
}

void Board::setAt(ChessPiece* piece, int x, int y){
    if(x < 8 && x > 0 && y > 0 && y < 8){
        grid[x][y] = piece;
    }
}

void Board::generateChessPiece(PIECE_COLOR color){
    if(color == WHITE){
        for(int i = 0; i < 8; i++){
            grid[1][i] = new Pawn(this, WHITE);
            //cout << "grid[1][i]; " << i << endl;
        }
        grid[0][0] = new Rook(this, WHITE);
        grid[0][7] = new Rook(this, WHITE);
        grid[0][1] = new Knight(this, WHITE);
        grid[0][6] = new Knight(this, WHITE);
        grid[0][2] = new Bishop(this ,WHITE);
        grid[0][5] = new Bishop(this, WHITE);
        grid[0][3] = new King(this, WHITE);
        grid[0][4] = new Queen(this, WHITE);
    }else{
        for(int i = 0; i < 8; i++){
            grid[6][i] = new Pawn(this, BLACK);
            //cout << "grid[6][i]; " << i << endl;
        }
        grid[7][0] = new Rook(this, BLACK);
        grid[7][7] = new Rook(this, BLACK);
        grid[7][1] = new Knight(this, BLACK);
        grid[7][6] = new Knight(this, BLACK);
        grid[7][2] = new Bishop(this ,BLACK);
        grid[7][5] = new Bishop(this, BLACK);
        grid[7][3] = new King(this, BLACK);
        grid[7][4] = new Queen(this, BLACK);
    }
}

vector<Move> getLegalMoves(ChessPiece piece, vector<Move>& moves)
