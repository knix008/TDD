#include "unity.h"
#include "fibonacci.h"

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_function_fibonacci_10(void) {
    //test stuff
    TEST_ASSERT(55 == fibonacci(10));
}

void test_function_fibonacci_20(void) {
    //more test stuff
    TEST_ASSERT(6765 == fibonacci(20));
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_fibonacci_10);
    RUN_TEST(test_function_fibonacci_20);
    return UNITY_END();
}