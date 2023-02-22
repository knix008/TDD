#include <stdlib.h>
#include <memory.h>
#include "DVRecorder.h"

void DvrRecorder_Create(void)
{
}

void DvRecorder_RestorePrograms(DvRecorder *programs)
{
    programs = programs;
}

void DvRecorder_Destroy(void)
{
}

#if 0
#include <pthread.h>

void DvRecorder_startScheduledPrograms(void)
{
    ScheduledProgram p;
    File dest;
    
    boss_mutex_lock(ScheduledProgram_mutex);
    p = DvRecorder_getNextScheduledProgram();
    while (p)
    {       
        if (ScheduledProgram_isTimeToStart(p)) {
            if (dvr->isSleeping) {
                boss_mutex_lock(audioOut->mutex);
                audioOut->muted = TRUE;
                turnOffAudio(audioOut->port);
                boss_mutex_lock(dvr->mutex);
                if (dvr->activeRecordingsCount 
                        >= MAX_SIMULTANEOUS_RECORDINGS) {
                    boss_mutex_unlock(ScheduledProgram_mutex);
                    boss_mutex_unlock(dvr->mutex);
                    return;
                }
                dest = openRecordingFile(p);
                dvr->activeRecordingsCount++;
                record(dest, p->channel);
                boss_mutex_lock(audioOut->mutex);
                boss_mutex_lock(dvr->mutex);    
            } 
            /* ...more of the same... */
        }
        p = DvRecorder_getNextScheduledProgram(p);
     }    
    boss_mutex_unlock(ScheduledProgram_mutex);
}

void DvRecorder_startScheduledPrograms(void)
{
    ScheduledProgram p;
    
    Acquire_ProgramSchedule_locks();
    p = DvRecorder_getFirstScheduledProgram();

    while (p && ! recordingLimitReached())
    { 
        ScheduledProgram_startReadyProgram(p);
        p = DvRecorder_getNextScheduledProgram(p);
    }    
    Release_ProgramSchedule_locks();
}
#endif
