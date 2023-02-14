#ifndef __LIGHTCONTROLLER_H__
#define __LIGHTCONTROLLER_H__
#include <stdbool.h>
#include "LightDriver.h"

enum
{
    LIGHT_ID_UNKNOWN = -1,
    LIGHT_STATE_UNKNOWN = -1,
    LIGHT_OFF = 0,
    LIGHT_ON = 1
};

enum {MAX_LIGHTS = 32};

void LightController_Create(void);
void LightController_On(int id);
void LightController_Off(int id);
bool LightController_Add(int id, LightDriver);
bool LightController_Remove(int id);
void LightController_Destroy(void);

#endif