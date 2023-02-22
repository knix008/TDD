#ifndef __DVRECORDER_H__
#define __DVRECORDER_H__

typedef struct Program
{
    const char *name;
    int repeat;
    int channel;
    int startHour;
    int startMinute;
    int durationInMinutes;
    int priority;
    int preferences;
} Program;

enum
{
    ALL_EPISODES,
    NEW_EPISODES,
    REPEATED_EPISODES,
    REPEAT,
    NO_REPEAT,
    LOW_PRIORITY,
    MEDIUM_PRIORITY,
    HIGH_PRIORITY
};

typedef struct
{
    int programCount;
    Program programs[100];
    /* etc... */
} DvRecorder;

void DvrRecorder_Create(void);
void DvRecorder_RestorePrograms(DvRecorder *);

void DvRecorder_Destroy(void);

#endif
