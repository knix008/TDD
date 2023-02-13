#ifndef __LIGHTDRIVER_H__
#define __LIGHTDRIVER_H__

typedef struct LightDriverStruct *LightDriver;

typedef enum LightDriverType
{
    TestLightDriver,
    X10,
    AcmeWireless,
    MemoryMapped
} LightDriverType;

void LightDriver_Destroy(LightDriver);
void LightDriver_TurnOn(LightDriver);
void LightDriver_TurnOff(LightDriver);
const char *LightDriver_GetType(LightDriver driver);
int LightDriver_GetId(LightDriver driver);

#include "LightDriverPrivate.h"

#endif