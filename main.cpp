#include <iostream>
#include <cctype> //for type checking
#include "board.h"

using namespace std;

void gameLoop(Board& myBoard);

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
        //myBoard.getLegalMoves(tolower(input[0]+ input[1]));
    }
}
