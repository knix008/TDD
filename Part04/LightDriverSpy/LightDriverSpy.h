#ifndef __LIGHTDRIVERSPY__H__
#define __LIGHTDRIVERSPY__H__

#include "LightDriver.h"

typedef struct LightDriverSpyStruct *LightDriverSpy;

LightDriver LightDriverSpy_Create(int id);

/* Functions just needed by the spy */
void LightDriverSpy_Reset(void);
void LightDriverSpy_InstallInterface(void);
int LightDriverSpy_GetState(int id);
int LightDriverSpy_GetLastId(void);
int LightDriverSpy_GetLastState(void);
void LightDriverSpy_AddSpiesToController(void);

enum
{
    LIGHT_ID_UNKNOWN = -1,
    LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0,
    LIGHT_ON = 1
};

#endif