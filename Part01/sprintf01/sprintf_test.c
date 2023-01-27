#include "unity.h"
#include <string.h>

static char output[100];
static const char *expected;

void setUp(void) {
    memset(output, 0xaa, sizeof output);
    expected = "";
}

void tearDown(void) {
}

static void expect(const char *s) {
    expected = s;
}

static void given(int charsWritten) {
    TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_EQUAL_CHAR(0xaa, output[strlen(expected) + 1]);
}

void test_function_NoFormatOperation(void) {
    char output[5];
    memset(output, 0xaa, sizeof output);

    TEST_ASSERT_EQUAL(3, sprintf(output, "hey"));
    TEST_ASSERT_EQUAL_STRING("hey", output);
    TEST_ASSERT_EQUAL_CHAR(0xaa, output[4]);
}

void test_function_InsertString(void) {
    char output[20];
    memset(output, 0xaa, sizeof output);

    TEST_ASSERT_EQUAL(12, sprintf(output, "Hello %s\n", "World"));
    TEST_ASSERT_EQUAL_STRING("Hello World\n", output);
    TEST_ASSERT_EQUAL_CHAR(0xaa, output[13]);
}

int main(void){
    UNITY_BEGIN();
    RUN_TEST(test_function_NoFormatOperation);
    RUN_TEST(test_function_InsertString);
    return UNITY_END();
}