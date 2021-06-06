#include "Grid.h"
#include "GameGrid.h"
#include <algorithm>
#include <vector>
bool Grid::Move(Direction direction) {
    switch (direction) {
    case Up: {
        if (!availableMoves[Up])
            return false;
        for (int column = 0; Dimention > column; column++) {
            Concat(GameBoard.begin() + column, GameBoard.end() + column,
                   longStep);
        }
        break;
    }
    case Grid::Direction::Down: {
        if (!availableMoves[Down])
            return false;
        for (int column = 0; Dimention > column; column++) {
            Concat(GameBoard.rbegin() + column, GameBoard.rend() + column,
                   longStep);
        }
        break;
    }
    case Left: {
        if (!availableMoves[Left])
            return false;
        for (int row = 0; Dimention > row; row++) {
            Concat(GameBoard.begin() + Dimention * row,
                   GameBoard.begin() + Dimention * (row + 1), shortStep);
        }
        break;
    }
    case Right: {
        if (!availableMoves[Right])
            return false;
        for (int row = 0; Dimention > row; row++) {
            Concat(GameBoard.rbegin() + Dimention * row,
                   GameBoard.rbegin() + Dimention * (row + 1), shortStep);
        }
        break;
    }
    default: {
        throw "Invalid value passed";
    }
    }
    CheckForMaxNumber();
    SpawnNewNumber();
    UpdateMovementArray();
    return true;
}
void Grid::UpdateMovementArray() {
    bool tmp = false;
    // Up
    for (int column = 0; Dimention > column; column++) {
        tmp += TryMove(GameBoard.cbegin() + column, GameBoard.cend() + column,
                       longStep);
        if (tmp)
            break;
    }
    availableMoves[Up] = tmp;
    tmp = false;
    // Down
    for (int column = 0; Dimention > column; column++) {
        tmp += TryMove(GameBoard.crbegin() + column, GameBoard.crend() + column,
                       longStep);
        if (tmp)
            break;
    }
    availableMoves[Down] = tmp;
    tmp = false;
    // Left
    for (int row = 0; Dimention > row; row++) {
        tmp += TryMove(GameBoard.cbegin() + Dimention * row,
                       GameBoard.cbegin() + Dimention * (row + 1), shortStep);
        if (tmp)
            break;
        ;
    }
    availableMoves[Left] = tmp;
    tmp = false;
    // Right
    for (int row = 0; Dimention > row; row++) {
        tmp += TryMove(GameBoard.crbegin() + Dimention * row,
                       GameBoard.crbegin() + Dimention * (row + 1), shortStep);
        if (tmp)
            break;
        ;
    }
    availableMoves[Right] = tmp;
}
bool Grid::TryMove(std::vector<unsigned int>::const_iterator begining,
                   std::vector<unsigned int>::const_iterator end, short step) {
    bool allAre0 = true;
    for (auto it = begining + step; it != end; it += step) {
        if (*it != 0) {
            allAre0 = false;
            break;
        }
    }
    if (allAre0)
        return false;
    for (; begining != end - step; begining += step) {
        if (*begining == 0)
            return true;
        if (*begining == *(begining + step))
            return true;
    }
    return false;
}
bool Grid::TryMove(std::vector<unsigned int>::const_reverse_iterator begining,
                   std::vector<unsigned int>::const_reverse_iterator end,
                   short step) {
    bool allAre0 = true;
    for (auto it = begining + step; it != end; it += step) {
        if (*it != 0) {
            allAre0 = false;
            break;
        }
    }
    if (allAre0)
        return false;
    for (; begining != end - step; begining += step) {
        if (*begining == 0)
            return true;
        if (*begining == *(begining + step))
            return true;
    }
    return false;
}

void Grid::Concat(std::vector<unsigned int>::iterator begining,
                  std::vector<unsigned int>::iterator end, short step) {

    for (; begining != end; begining += step) {
        for (auto next = begining + step; next < end; next += step) {
            if (*next != 0) {
                if (*begining == 0) {
                    *begining += *next;
                    *next = 0;
                    continue;
                } else if (*next == *begining) {
                    *begining += *next;
                    *next = 0;
                }
                break;
            }
        }
    }
}
void Grid::Concat(std::vector<unsigned int>::reverse_iterator begining,
                  std::vector<unsigned int>::reverse_iterator end, short step) {

    for (; begining != end; begining += step) {
        for (auto next = begining + step; next < end; next += step) {
            if (*next != 0) {
                if (*begining == 0) {
                    *begining += *next;
                    *next = 0;
                    continue;
                } else if (*next == *begining) {
                    *begining += *next;
                    *next = 0;
                }
                break;
            }
        }
    }
}

void Grid::CheckForMaxNumber() {
    std::find(GameBoard.begin(), GameBoard.end(), MaxNumber) == GameBoard.end()
        ? HasWon = false
        : HasWon = true;
}

bool Grid::GetHasWon() { return HasWon; }
bool Grid::GetMoves() {
    return std::any_of(availableMoves.begin(), availableMoves.end(),
                       [](bool i) { return i; });
}