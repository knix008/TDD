#ifndef __CALCULATORTEST_H__
#define __CALCULATORTEST_H__

#include <cppunit/extensions/HelperMacros.h>
#include "Calculator.h"

class CalculatorTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(CalculatorTest);
    CPPUNIT_TEST(testAddFailureWithMesssage);
    CPPUNIT_TEST(testAddSuccessWithNoMessage);
    CPPUNIT_TEST_SUITE_END();
public:
    CalculatorTest(void) {}
    ~CalculatorTest(void) {}
    void setUp();
    void tearDown();
    void testAddFailureWithMesssage();
    void testAddSuccessWithNoMessage();
private:
    Calculator m_calc;
};

#endif