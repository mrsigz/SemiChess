#ifndef MOVE_H
#define MOVE_H
#include <string>
#include <vector>

using namespace std;

class Move{
private:
    string m_move;
public:
    Move(int x, int y): m_move(toMove(x, y)){};
    friend ostream& operator<<(ostream& out, const Move& rhs){
        out << rhs.m_move;
        return out;
    };
    string toMove(int x, int y){
        string ret;
        char a = (char)(x + 1) + '0';
        char b = (char)y + 'a';
        ret += b;
        ret += a;
        return ret;
    }
    string getMove(){ return m_move; }
};

#endif // MOVE_H
