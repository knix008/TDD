#include <CppUTest/CommandLineTestRunner.h>
#include <stdint.h>
#include <memory.h>

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}

TEST_GROUP(sprintf)
{
    char output[100];
    const char *expected;
    void setup()
    {
        memset(output, 0xaa, sizeof output);
        expected = "";
    }
    void teardown()
    {
    }
    void expect(const char *s)
    {
        expected = s;
    }
    void given(int charsWritten)
    {
        LONGS_EQUAL(strlen(expected), charsWritten);
        STRCMP_EQUAL(expected, output);
        BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
    }
};

TEST(sprintf, NoFormatOperations)
{
    char output[5];
    
    LONGS_EQUAL(4, sprintf(output, "hey"));
    STRCMP_EQUAL("hey", output);
}

TEST(sprintf, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "%s\n", "Hello World"));
}