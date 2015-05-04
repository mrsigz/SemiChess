#include "board.h"

Board::Board(){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            if(i == 0){
                if(j == 0 || j == 7){
                    grid[i][j] = new Black(this, CASTLE, CHAR(i), j);
                }else if(j == 1 || j == 6){
                    grid[i][j] = new Black(this, KNIGHT, CHAR(i), j);
                }else if(j == 2 || j == 5){
                    grid[i][j] = new Black(this, BISHOP, CHAR(i), j);
                }else if(j == 3){
                    grid[i][j] = new Black(this, QUEEN, CHAR(i), j);
                }else if(j == 5){
                    grid[i][j] = new Black(this, KING, CHAR(i), j);
                }
            }else if(i == 1){
                grid[i][j] = new Black(this, PAWN, CHAR(i), j);
            }else if(i == 7){
                if(j == 0 || j == 7){
                    grid[i][j] = new White(this, CASTLE, CHAR(i), j);
                }else if(j == 1 || j == 6){
                    grid[i][j] = new White(this, KNIGHT, CHAR(i), j);
                }else if(j == 2 || j == 5){
                    grid[i][j] = new White(this, BISHOP, CHAR(i), j);
                }else if(j == 3){
                    grid[i][j] = new White(this, QUEEN, CHAR(i), j);
                }else if(j == 5){
                    grid[i][j] = new White(this, KING, CHAR(i), j);
                }
            }else if(i == 6){
                grid[i][j] = new White(this, PAWN, CHAR(i), j);
            }else{
                grid[i][j] = NULL;
            }
        }
    }
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
    for(int i = 0; i < 11; ++i){
        for(int j = 0; j < 11; ++j){
            if(i == 0 || i == 9){                       //print upper and lower frame
                if(j == 10){
                    cout << endl;
                }else{
                    cout << "--";
                }
            }else if((j == 1 || j == 10) && i != 10){   //print right and left frame
                if(j == 10){
                    cout << " |" << endl;;
                }else{
                    cout << "|";
                }
            }else if(i == 10){                          //print board letters
                if(j == 0 || j == 9){
                    cout << "  ";
                }else if(j == 10){
                    cout << endl;
                }else{
                    char letter = 96 + j;
                    cout << " " << letter;
                }
            }else if(j == 0 && i != 0 && i != 9){       //print board numbers
                cout << 9 - i;
            }else{                                      //print chess pieces on board, spaces if empty
                if(grid[i - 1][j - 2] != NULL){
                    cout << " " << grid[i - 1][j - 2]->representation();
                }else{
                    cout << "  ";
                }
            }
        }
    }
    cout << endl;
}

ChessPiece* Board::getAt(int x, int y){
    if(x < 8 && x > 0 && y > 0 && y < 8){
        if(grid[x][y] != NULL){
            return grid[x][y]
        }
    }
    return (void *) -1;
}

void Board::setAt(ChessPiece* piece, int x, int y){
    if(x < 8 && x > 0 && y > 0 && y < 8){
        grid[x][y] = piece;
    }
}
