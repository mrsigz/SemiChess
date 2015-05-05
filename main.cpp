#include <iostream>
#include <cctype> //for type checking
#include "board.h"
#include "Constants.h"

using namespace std;

void gameLoop(Board& myBoard);
void parseInput(Board& myBoard, string& inp);
void printMoves(vector<Move> moves);

int main()
{
    Board myBoard;
    gameLoop(myBoard);
    return 0;
}

void gameLoop(Board& myBoard){
    while(true){
        string input;
        myBoard.display();
        cout << (myBoard.getTurn() % 2 == 0 ? "White's " : "Blacks's ") << "move - input square: ";
        cin >> input;
        parseInput(myBoard, input);
        if(input == "x"){
            return;
        }
        ChessPiece* piece = myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'));
        vector<Move> moves;
        moves = piece->getLegalMoves(myBoard, moves, (input[1] - '0') - 1, (int)(input[0] - 'a'));
        while((int)moves.size() == 0){
            cout << "Piece on " << input << " cannot move! - please try again: ";
            cin >> input;
            parseInput(myBoard, input);
            if(input == "x"){
                return;
            }
            piece = myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'));
            moves = piece->getLegalMoves(myBoard, moves, (input[1] - '0') - 1, (int)(input[0] - 'a'));
        }
        printMoves(moves);
        myBoard.simulateOneMove(piece, moves, (input[1] - '0') - 1, (int)(input[0] - 'a'));
        myBoard.incrementTurn();
    }
}

void parseInput(Board& myBoard, string& input){
    if(input == "x"){
        return;
    }
    if(input.size() != 2 || input[0] < 'a' || input[0] > 'h' || (input[1] - '0') < 1 ||(input[1] - '0') > 8){
        cout << "Illegal input! - please try again: ";
        cin >> input;
        parseInput(myBoard, input);
        if(input == "x"){
            return;
        }
    }else if(myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a')) == NULL){
        cout << "Square is empty! - please try again: ";
        cin >> input;
        parseInput(myBoard, input);
        if(input == "x"){
            return;
        }
    }else if((myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'))->getColor() != WHITE && myBoard.getTurn() % 2 == 0) ||
             (myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'))->getColor() == WHITE && myBoard.getTurn() % 2 != 0)){
        cout << "Not your turn! - please try again: ";
        cin >> input;
        parseInput(myBoard, input);
        if(input == "x"){
            return;
        }
    }
}

void printMoves(vector<Move> moves){
    cout << "Possible squares: ";
    for(int i = 0; i < (int)moves.size(); i++){
        cout << moves[i] << " ";
    }
    cout << endl;
}
