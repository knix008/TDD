#include <CppUTest/CommandLineTestRunner.h>
#include <string.h>
/*#include <cstring>*/

TEST_GROUP(StringParser){
    void setup(){} void teardown(){}};

TEST(StringParser, ParseTwoElement)
{
    char input[] = "abc,def";
    char *token1 = strtok(input, "., ");
    char *token2 = strtok(0, "., ");
    STRCMP_EQUAL("abc", token1);
    STRCMP_EQUAL("def", token2);
}

/*
TEST(StringParser, ParseTwoElement)
{
    char *input = (char *)"abc,def";
    char *token1 = strtok(input, "., ");
    char *token2 = strtok(0, "., ");
    STRCMP_EQUAL("abc", token1);
    STRCMP_EQUAL("def", token2);
}
*/

TEST(StringParser, ParserOneElement)
{
    char *input = (char *)"abc";
    char *token = strtok(input, "., ");
    STRCMP_EQUAL(input, token);
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}