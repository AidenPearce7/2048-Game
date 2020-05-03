#pragma once

class Number
{
private:
     int number;
     bool hasJoinedInThisTurn;
public:
    int GetNumber();
    void SetNumber(int value);
    void Join(Number number);
    bool Compare(Number number);
    void ResetTurn();
    Number();
    ~Number();
};