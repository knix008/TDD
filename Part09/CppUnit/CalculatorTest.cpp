#include "CalculatorTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION(CalculatorTest);

void CalculatorTest::setUp()
{
}

void CalculatorTest::tearDown()
{
}

void CalculatorTest::testAdd()
{
    CPPUNIT_ASSERT(m_calc.add(10, 10) == 20);
}