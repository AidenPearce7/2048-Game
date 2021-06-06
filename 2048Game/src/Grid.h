#pragma once
#include <array>
#include <vector>
class Grid {
  public:
    enum Direction { Up, Down, Left, Right };

    bool GetHasWon();
    bool GetMoves();

    bool Move(Direction direction);

  protected:
    bool HasWon = false;
    std::array<bool, 4> availableMoves = {true, true, true, true};
    static constexpr short shortStep = 1;
    static constexpr short longStep = 4;
    unsigned int MaxNumber;
    short Dimention;
    std::vector<unsigned int> GameBoard;
    void CheckForMaxNumber();
    virtual void SpawnNewNumber() = 0;
    void Concat(std::vector<unsigned int>::iterator begining,
                std::vector<unsigned int>::iterator end, short step);
    void Concat(std::vector<unsigned int>::reverse_iterator begining,
                std::vector<unsigned int>::reverse_iterator end, short step);

    void UpdateMovementArray();
    bool TryMove(std::vector<unsigned int>::const_iterator begining,
                 std::vector<unsigned int>::const_iterator end, short step);
    bool TryMove(std::vector<unsigned int>::const_reverse_iterator begining,
                 std::vector<unsigned int>::const_reverse_iterator end,
                 short step);
};
