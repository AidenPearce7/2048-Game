#include "../src/Grid.h"

class GameGridMock : public Grid {
  public:
    GameGridMock();
    void AddSymbol(unsigned short x, unsigned short y, unsigned short symbol);
    void SpawnNewNumber() override;
    unsigned int GetPos(unsigned short x, unsigned short y);
    bool GetDirectionMove(unsigned short d);
};