#include <CppUTest/CommandLineTestRunner.h>
#include <memory.h>
#include "DVRecorder.h"

static DvRecorder recorderData = {
    4,
    {{"Rocky and Bullwinkle", REPEAT, 2, 8, 30, 30, HIGH_PRIORITY, ALL_EPISODES},
     {"Bugs Bunny", REPEAT, 9, 8, 30, 30, HIGH_PRIORITY, ALL_EPISODES},
     {"Dr. Who", REPEAT, 11, 23, 0, 90, HIGH_PRIORITY, REPEATED_EPISODES},
     {"Law and Order", REPEAT, 5, 21, 0, 60, HIGH_PRIORITY, ALL_EPISODES},
     {0}}};

#if 0 // START: firstSetup
TEST_GROUP(DvRecorder)
{
    DvRecorder recorder;
    void setup()
    {
        memcpy(&recorder, &recorderData, sizeof(recorder));
        DvrRecorder_Create();
        DvRecorder_RestorePrograms(&recorder);
    }
    
    void teardown()
    {
        DvRecorder_Destroy();
    }
};
//END: firstSetup
#endif

TEST_GROUP(DvRecorder)
{
    DvRecorder recorder;
    void setup()
    {
        memcpy(&recorder, &recorderData, sizeof(recorder));
        DvrRecorder_Create();
    }
    void teardown()
    {
        DvRecorder_Destroy();
    }
};

TEST(DvRecorder, RestoreSomePrograms)
{
    DvRecorder_RestorePrograms(&recorder);
    // etc...
}

TEST(DvRecorder, RestoreNoPrograms)
{
    recorder.programCount = 0;
    recorder.programs[0].name = 0;
    DvRecorder_RestorePrograms(&recorder);
    // etc...
}

TEST(DvRecorder, RecordWithRepeat)
{
    DvRecorder_RestorePrograms(&recorder);
    // etc...
}

TEST(DvRecorder, RecordWithNoRepeat)
{
    recorder.programs[0].repeat = NO_REPEAT;
    recorder.programs[1].repeat = NO_REPEAT;
    recorder.programs[2].repeat = NO_REPEAT;
    DvRecorder_RestorePrograms(&recorder);
    // etc...
}

TEST(DvRecorder, RecordConflictFirstHighPriorityWins)
{
    DvRecorder_RestorePrograms(&recorder);
    // etc...
}

TEST(DvRecorder, RecordConflictHighPriorityWins)
{
    recorder.programs[0].priority = LOW_PRIORITY;
    DvRecorder_RestorePrograms(&recorder);
    // etc...
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}
