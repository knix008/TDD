#ifndef __CALCULATORTEST_H__
#define __CALCULATORTEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include "Calculator.h"

class CalculatorTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAdd);
    CPPUNIT_TEST_SUITE_END();
public:
    CalculatorTest(void) {}
    ~CalculatorTest(void) {}
    void setUp();
    void tearDown();
    void testAdd();
private:
    Calculator m_calc;
};

#endif