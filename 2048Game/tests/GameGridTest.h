#include "../mocks/GameGridMock.h"
#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>
class GameGridTest : public CppUnit::TestCase {
    CPPUNIT_TEST_SUITE(GameGridTest);
    CPPUNIT_TEST(ConcatTest_simple_Up);
    CPPUNIT_TEST(ConcatTest_simple_Right);
    CPPUNIT_TEST(ConcatTest_simple_Left);
    CPPUNIT_TEST(ConcatTest_simple_Down);
    CPPUNIT_TEST(ConcatTest_advanced_Down);
    CPPUNIT_TEST(ConcatTest_advanced_Up);
    CPPUNIT_TEST(ConcatTest_advanced_Right);
    CPPUNIT_TEST(ConcatTest_advanced_Left);
    CPPUNIT_TEST(WinTest);
    CPPUNIT_TEST(LoseTest);
    CPPUNIT_TEST(ConcatTest_split_Down);
    CPPUNIT_TEST(ConcatTest_split_Up);
    CPPUNIT_TEST(ConcatTest_split_Right);
    CPPUNIT_TEST(ConcatTest_split_Left);
    CPPUNIT_TEST(LockUp);
    CPPUNIT_TEST(LockDown);
    CPPUNIT_TEST(LockLeft);
    CPPUNIT_TEST(LockRight);
    CPPUNIT_TEST_SUITE_END();

  public:
    void setUp();
    void tearDown();

  protected:
    void ConcatTest_advanced_Down();
    void ConcatTest_simple_Down();
    void ConcatTest_advanced_Up();
    void ConcatTest_simple_Up();
    void ConcatTest_advanced_Right();
    void ConcatTest_simple_Right();
    void ConcatTest_advanced_Left();
    void ConcatTest_simple_Left();
    void LoseTest();
    void WinTest();
    void ConcatTest_split_Up();
    void ConcatTest_split_Down();
    void ConcatTest_split_Left();
    void ConcatTest_split_Right();
    void LockRight();
    void LockLeft();
    void LockUp();
    void LockDown();

  private:
    GameGridMock *grid;
};
CPPUNIT_TEST_SUITE_REGISTRATION(GameGridTest);
