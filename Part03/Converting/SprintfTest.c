/* Generated code, edit at your own risk */
#include "unity_fixture.h"
#include "Sprintf.h"

TEST_GROUP(PlatformSpecificSprintf);

TEST_SETUP(PlatformSpecificSprintf)
{
}

TEST_TEAR_DOWN(PlatformSpecificSprintf)
{
}

/* Make sure you invoke RUN_TEST_GROUP(PlatformSpecificSprintf) from unity main */
TEST(PlatformSpecificSprintf, OutputFitsInBuffer)
{
    char buf[10];
    int count = PlatformSpecificSprintf(buf, sizeof buf, "%s", "12345");
    TEST_ASSERT_EQUAL_STRING("12345", buf);
    TEST_ASSERT_EQUAL(5, count);
}

TEST_GROUP_RUNNER(PlatformSpecificSprintf)
{
    RUN_TEST_CASE(PlatformSpecificSprintf, OutputFitsInBuffer);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(PlatformSpecificSprintf);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}