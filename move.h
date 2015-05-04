#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <vector>

using namespace std;

class Move{
private:
    string m_move;
public:
    Move(string input): m_move(input){};
    friend ostream& operator<<(ostream& out, const Move& rhs){
        out << rhs.m_move;
        return out;
    };
};

#endif // MOVE_H
