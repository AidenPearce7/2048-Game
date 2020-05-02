
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

Number::Number()
{
    number = 0;
    hasJoinedInThisTurn=false;
}
int Number::GetNumber(){
    return number;
}
void Number::SetNumber(int value){
    number = value;
}
//Joins numbers
//Doubles number on which it was called
//0s the number given in the argument.
//Locks both numbers.
void Number::Join(Number number){
    if (this->hasJoinedInThisTurn || number.hasJoinedInThisTurn)
    {
        return;
    }
    this->number *= 2;
    number.number = 0;
    this->hasJoinedInThisTurn = true;
    number.hasJoinedInThisTurn = true;
}
//Resets lock on Joining
void Number::ResetTurn(){
    hasJoinedInThisTurn = false;
}
//Returns true if numbers are the same and not equal to 0
bool Number::Compare(Number number){
    if (this->number != 0 && this->number == number.number) return true;
    return false;
}

Number::~Number()
{
}
