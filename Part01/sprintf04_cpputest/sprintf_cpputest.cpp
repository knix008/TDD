TEST(sprintf, NoFormatOperations)
{
    char output[5] = "";

    LONGS_EQUAL(3, sprintf(output, "hey"));
    STRCMP_EQUAL("hey", output);
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