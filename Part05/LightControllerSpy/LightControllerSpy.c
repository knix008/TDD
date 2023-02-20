#include <stdbool.h>
#include <memory.h>
#include "LightDriver.h"
#include "LightDriverSpy.h"
#include "LightControllerSpy.h"

static int lastId;
static int lastState;
static int count;
static int lights[MAX_LIGHTS];
static LightDriver lightDrivers[MAX_LIGHTS] = {NULL};

void LightController_Create(void)
{
    lastId = LIGHT_ID_UNKNOWN;
    lastState = LIGHT_STATE_UNKNOWN;
    count = 0;
    memset(lights, LIGHT_STATE_UNKNOWN, sizeof lights);
}

void LightController_Destroy(void)
{
}

static int isIdInRange(int id)
{
    return id >= 0 && id <= 31;
}

void LightController_TurnOn(int id)
{
    lastId = id;
    lastState = 1;
    count++;
    if (isIdInRange(id))
        lights[id] = LIGHT_ON;
}

void LightController_TurnOff(int id)
{
    lastId = id;
    lastState = 0;
    count++;
    if (isIdInRange(id))
        lights[id] = LIGHT_OFF;
}

bool LightController_Add(int id, LightDriver lightDriver)
{
    if (isIdInRange(id))
        return false;

    if (lightDriver == NULL)
        return false;

    LightDriver_Destroy(lightDrivers[id]);

    lightDrivers[id] = lightDriver;
    return true;
}

int LightControllerSpy_GetLastId(void)
{
    return lastId;
}

int LightControllerSpy_GetLastState(void)
{
    return lastState;
}

int LightControllerSpy_GetEventCounts(void)
{
    return count;
}

int LightControllerSpy_GetLightState(int id)
{
    if (!isIdInRange(id))
        return LIGHT_STATE_UNKNOWN;
    return lights[id];
}