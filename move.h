#ifndef MOVE_H
#define MOVE_H

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
