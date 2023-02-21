#ifndef __LIGHTCONTROLLER_H__
#define __LIGHTCONTROLLER_H__

#include "LightDriver.h"

enum
{
    MAX_LIGHTS = 32
};

void LightController_Create(void);
void LightController_TurnOn(int id);
void LightController_TurnOff(int id);
bool LightController_Add(int id, LightDriver);
bool LightController_Remove(int id);
void LightController_Destroy(void);

#endif