#include "GameGridTest.h"
#include <cppunit/TestAssert.h>
void GameGridTest::setUp() { grid = new GameGridMock(); }
void GameGridTest::tearDown() { delete grid; }
void GameGridTest::ConcatTest_simple_Up() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 1, 2);
    grid->Move(Grid::Up);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 4);
}
void GameGridTest::ConcatTest_advanced_Up() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 1, 2);
    grid->AddSymbol(0, 2, 4);
    grid->AddSymbol(0, 3, 8);
    grid->Move(Grid::Up);
    grid->Move(Grid::Up);
    grid->Move(Grid::Up);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 16);
}
void GameGridTest::ConcatTest_simple_Down() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 1, 2);
    grid->Move(Grid::Down);
    CPPUNIT_ASSERT(grid->GetPos(0, 3) == 4);
}
void GameGridTest::ConcatTest_simple_Right() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(1, 0, 2);
    grid->Move(Grid::Right);
    CPPUNIT_ASSERT(grid->GetPos(3, 0) == 4);
}
void GameGridTest::ConcatTest_simple_Left() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(1, 0, 2);
    grid->Move(Grid::Left);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 4);
}
void GameGridTest::ConcatTest_advanced_Down() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 1, 2);
    grid->AddSymbol(0, 2, 4);
    grid->AddSymbol(0, 3, 8);
    grid->Move(Grid::Down);
    grid->Move(Grid::Down);
    grid->Move(Grid::Down);
    CPPUNIT_ASSERT(grid->GetPos(0, 3) == 16);
}
void GameGridTest::ConcatTest_advanced_Right() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(1, 0, 2);
    grid->AddSymbol(2, 0, 4);
    grid->AddSymbol(3, 0, 8);
    grid->Move(Grid::Right);
    grid->Move(Grid::Right);
    grid->Move(Grid::Right);
    CPPUNIT_ASSERT(grid->GetPos(3, 0) == 16);
}
void GameGridTest::ConcatTest_advanced_Left() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(1, 0, 2);
    grid->AddSymbol(2, 0, 4);
    grid->AddSymbol(3, 0, 8);
    grid->Move(Grid::Left);
    grid->Move(Grid::Left);
    grid->Move(Grid::Left);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 16);
}
void GameGridTest::WinTest() {
    grid->AddSymbol(0, 0, 1024);
    grid->AddSymbol(0, 1, 1024);
    grid->Move(Grid::Up);
    CPPUNIT_ASSERT(grid->GetHasWon());
}
void GameGridTest::LoseTest() {
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 1, 1024);
    grid->AddSymbol(0, 2, 4);
    grid->AddSymbol(0, 3, 8);
    grid->AddSymbol(1, 0, 1024);
    grid->AddSymbol(1, 1, 2);
    grid->AddSymbol(1, 2, 16);
    grid->AddSymbol(1, 3, 32);
    grid->AddSymbol(2, 0, 64);
    grid->AddSymbol(2, 1, 256);
    grid->AddSymbol(2, 2, 128);
    grid->AddSymbol(2, 3, 2);
    grid->AddSymbol(3, 0, 512);
    grid->AddSymbol(3, 1, 16);
    grid->AddSymbol(3, 2, 32);
    grid->AddSymbol(3, 3, 4);
    grid->Move(Grid::Up);
    CPPUNIT_ASSERT(!grid->GetMoves());
}
void GameGridTest::ConcatTest_split_Up() {
    grid->AddSymbol(0, 1, 4);
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 2, 2);
    grid->Move(Grid::Up);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 2 && grid->GetPos(0, 2) == 2 &&
                   grid->GetPos(0, 1) == 4);
}
void GameGridTest::ConcatTest_split_Down() {
    grid->AddSymbol(0, 1, 4);
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(0, 2, 2);
    grid->Move(Grid::Down);
    CPPUNIT_ASSERT(grid->GetPos(0, 1) == 2 && grid->GetPos(0, 2) == 4 &&
                   grid->GetPos(0, 3) == 2);
}
void GameGridTest::ConcatTest_split_Left() {
    grid->AddSymbol(1, 0, 4);
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(2, 0, 2);
    grid->Move(Grid::Left);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 2 && grid->GetPos(1, 0) == 4 &&
                   grid->GetPos(2, 0) == 2);
}
void GameGridTest::ConcatTest_split_Right() {
    grid->AddSymbol(1, 0, 4);
    grid->AddSymbol(0, 0, 2);
    grid->AddSymbol(2, 0, 2);
    grid->Move(Grid::Right);
    CPPUNIT_ASSERT(grid->GetPos(1, 0) == 2 && grid->GetPos(2, 0) == 4 &&
                   grid->GetPos(3, 0) == 2);
}
void GameGridTest::LockRight() {
    grid->AddSymbol(0, 0, 2);
    grid->Move(Grid::Right);
    CPPUNIT_ASSERT(grid->GetPos(3, 0) == 2 && !grid->GetDirectionMove(3));
}
void GameGridTest::LockUp() {
    grid->AddSymbol(0, 1, 2);
    grid->Move(Grid::Up);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 2 && !grid->GetDirectionMove(0));
}
void GameGridTest::LockLeft() {
    grid->AddSymbol(3, 0, 2);
    grid->Move(Grid::Left);
    CPPUNIT_ASSERT(grid->GetPos(0, 0) == 2 && !grid->GetDirectionMove(2));
}
void GameGridTest::LockDown() {
    grid->AddSymbol(0, 0, 2);
    grid->Move(Grid::Down);
    CPPUNIT_ASSERT(grid->GetPos(0, 3) == 2 && !grid->GetDirectionMove(1));
}