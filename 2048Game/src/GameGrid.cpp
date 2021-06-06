#include "GameGrid.h"
#include <chrono>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

GameGrid::GameGrid() {
    Dimention = 4;
    this->GameBoard.resize(Dimention * Dimention);
    this->MaxNumber = 2048;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);
    newNumberDistribuion = std::uniform_int_distribution<int>(0, 1);
    StartGame();
}
GameGrid::GameGrid(unsigned short dimentions, unsigned int MaxNumber) {
    this->Dimention = dimentions;
    this->MaxNumber = MaxNumber;
    this->GameBoard.resize(dimentions * dimentions);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    generator = std::default_random_engine(seed);
    newNumberDistribuion = std::uniform_int_distribution<int>(0, 1);
    StartGame();
}
void GameGrid::GetValues() {

    unsigned short y = 0;
    for (auto const &i : GameBoard) {
        std::cout << i << "\t";
        y++;
        if (y == this->Dimention) {
            y = 0;
            std::cout << std::endl;
        }
    }
}
void GameGrid::StartGame() {
    for (size_t i = 0; i < 3; i++) {
        SpawnNewNumber();
    }
}
void GameGrid::SpawnNewNumber() {
    availableSpaces.clear();
    for (int i = 0; i < GameBoard.size(); ++i) {
        if (GameBoard[i] == 0) {
            availableSpaces.push_front(i);
        }
    }
    auto distance =
        std::distance(availableSpaces.begin(), availableSpaces.end()) - 1;
    fieldDistribution = std::uniform_int_distribution<int>(0, distance - 1);
    unsigned int value;
    if (newNumberDistribuion(generator) == 0)
        value = 2;
    else
        value = 4;
    int offset = fieldDistribution(generator);
    if (offset < 0 || offset > distance) {
        offset = availableSpaces.front();
    } else {
        std::forward_list<int>::const_iterator it = availableSpaces.cbegin();

        for (int i = 0; i < offset; i++) {
            it++;
        }
        offset = *it;
    }

    GameBoard[offset] = value;
}
