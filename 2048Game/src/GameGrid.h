#pragma once
#include "Grid.h"
#include <forward_list>
#include <random>
#include <vector>
class GameGrid : public Grid {
  public:
    GameGrid();
    GameGrid(unsigned short dimention, unsigned int MaxNumber);
    void GetValues();
    void StartGame();
    void SpawnNewNumber() override;

  private:
    std::default_random_engine generator;
    std::uniform_int_distribution<int> fieldDistribution;
    std::uniform_int_distribution<int> newNumberDistribuion;
    std::forward_list<int> availableSpaces;
};