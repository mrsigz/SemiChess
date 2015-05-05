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
        ChessPiece* piece = myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'));
        vector<Move> moves;
        moves = piece->getLegalMoves(myBoard, moves);
        printMoves(moves);
    }
}

void parseInput(Board& myBoard, string& input){
    if(input.size() != 2 || input[0] < 'a' || input[0] > 'h' || (input[1] - '0') < 1 ||(input[1] - '0') > 8){
        cout << "Illegal input - please try again: ";
        cin >> input;
        parseInput(myBoard, input);
    }else if(myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a')) == NULL){
        cout << "Square is empty - please try again: ";
        cin >> input;
        parseInput(myBoard, input);
    }else if((myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'))->getColor() != WHITE && myBoard.getTurn() % 2 == 0) ||
             (myBoard.getAt((input[1] - '0') - 1, (int)(input[0] - 'a'))->getColor() == WHITE && myBoard.getTurn() % 2 != 0)){
        cout << "Not your turn - try again: ";
        cin >> input;
        parseInput(myBoard, input);
    }
}

void printMoves(vector<Move> moves){
    for(int i = 0; i < moves.size(); i++){
        cout << moves[i] << " ";
    }
    cout << endl;
}
