#include "unity.h"
#include "fibonacci.h"

void setUp(void) {
    // set stuff up here
    printf("You need to do something before running each test cases here.\n");
}

void tearDown(void) {
    // clean stuff up here
    printf("You need to do something after running each test cases here.\n");
}

void test_function_fibonacci_10(void) {
    //test stuff
    printf("This is the first test case.\n");
    TEST_ASSERT(55 == fibonacci(10));
}

void test_function_fibonacci_20(void) {
    //more test stuff
    printf("This is the second test case.\n");
    TEST_ASSERT(6765 == fibonacci(20));
}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_fibonacci_10);
    RUN_TEST(test_function_fibonacci_20);
    return UNITY_END();
}