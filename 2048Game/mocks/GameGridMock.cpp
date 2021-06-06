#include "GameGridMock.h"
#include <vector>

void GameGridMock::AddSymbol(unsigned short x, unsigned short y,
                             unsigned short symbol) {
    this->GameBoard.at(x + 4 * y) += symbol;
}

GameGridMock::GameGridMock() {
    this->GameBoard = std::vector<unsigned int>{};
    this->GameBoard.resize(16);
    this->Dimention = 4;
    this->MaxNumber = 2048;
}
void GameGridMock::SpawnNewNumber() {
    // skip
}
unsigned int GameGridMock::GetPos(unsigned short x, unsigned short y) {
    return this->GameBoard.at(x + 4 * y);
}
bool GameGridMock::GetDirectionMove(unsigned short d) {
    return this->availableMoves[d];
}