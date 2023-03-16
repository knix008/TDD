#include "CalculatorTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorTest);

void CalculatorTest::setUp()
{
}

void CalculatorTest::tearDown()
{
}

void CalculatorTest::testAddFailureWithMesssage()
{
    CPPUNIT_ASSERT_MESSAGE("The result will should be 20.", m_calc.add(10, 10) != 20 );
}

void CalculatorTest::testAddSuccessWithNoMessage()
{
    CPPUNIT_ASSERT(m_calc.add(10, 10) == 20 );
}