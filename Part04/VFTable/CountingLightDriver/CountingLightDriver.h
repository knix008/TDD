#ifndef __COUNTINGDRIVER_H__
#define __COUNTINGDRIVER_H__
#include "LightDriver.h"

LightDriver CountingLightDriver_Create(int id);
int CountingLightDriver_GetCallCount(LightDriver);

#endif