#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#define FULL_TEST

int main(int argc, char *argv[])
{
    // Adds the test to the list of test to run
    CPPUNIT_NS::TextUi::TestRunner runner;

#ifdef FULL_TEST
    // Get the top level suite from the registry
    CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();
    runner.addTest(suite);
    // Change the default outputter to a compiler error format outputter
    runner.setOutputter(new CPPUNIT_NS::CompilerOutputter(&runner.result(), CPPUNIT_NS::stdCOut()));
#else
    CalculatorTest test;
    runner.addTest(test.suite());
    // Change the default outputter to a compiler error format outputter
    runner.setOutputter(new CPPUNIT_NS::CompilerOutputter(&runner.result(), CPPUNIT_NS::stdCOut()));
#endif

    // Run the test.
    bool wasSucessful = runner.run();
    // Return error code 1 if the one of test failed.
    return wasSucessful ? 0 : 1;
}