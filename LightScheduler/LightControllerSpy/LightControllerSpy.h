#ifndef __LIGHTCONTROLLERSPY_H__
#define __LIGHTCONTROLLERSPY_H__

#include "LightDriver.h"
#include "LightDriverSpy.h"
#include "LightController.h"

int LightControllerSpy_GetLastId(void);
int LightControllerSpy_GetLastState(void);
int LightControllerSpy_GetEventCounts(void);
int LightControllerSpy_GetLightState(int id);

#endif