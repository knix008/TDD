#include <stdlib.h>
#include <memory.h>
#include "LightController.h"

static LightDriver lightDrivers[MAX_LIGHTS] = {NULL};

void LightController_Create(void)
{
    memset(lightDrivers, 0, sizeof lightDrivers);
}

static void destroy(LightDriver driver)
{
    if (!driver)
        return;

    switch (driver->type)
    {
    case X10:
        X10LightDriver_Destroy(driver);
        break;
    case AcmeWireless:
        AcmeWirelessLightDriver_Destroy(driver);
        break;
    case MemoryMapped:
        MemMappedLightDriver_Destroy(driver);
        break;
    case TestLightDriver:
        LightDriverSpy_Destroy(driver);
        break;
    default:
        /* now what? */
        break;
    }
}

void LightController_Destroy(void)
{
    int i;
    for (i = 0; i < MAX_LIGHTS; i++)
    {
        LightDriver driver = lightDrivers[i];
        destroy(driver);
        lightDrivers[i] = NULL;
    }
}

/*
void LightController_Destroy(void)
{
    int i;
    for (i = 0; i < MAX_LIGHTS; i++)
    {
        LightDriver driver = lightDrivers[i];
        LightDriver_Destroy(driver);
        lightDrivers[i] = NULL;
    }
}
*/

static bool isIdInBounds(int id)
{
    return id < 0 || id >= MAX_LIGHTS;
}

bool LightController_Add(int id, LightDriver lightDriver)
{
    if (isIdInBounds(id))
        return false;

    if (lightDriver == NULL)
        return false;

    LightDriver_Destroy(lightDrivers[id]);

    lightDrivers[id] = lightDriver;
    return true;
}

bool LightController_Remove(int id)
{
    if (isIdInBounds(id))
        return false;

    if (lightDrivers[id] == NULL)
        return false;

    LightDriver_Destroy(lightDrivers[id]);

    lightDrivers[id] = NULL;
    return true;
}

/*
void LightController_TurnOn(int id)
{
    LightDriver_TurnOn(lightDrivers[id]);
}
*/

void LightController_TurnOn(int id)
{
    LightDriver driver = lightDrivers[id];
    if (NULL == driver)
        return;
    switch (driver->type)
    {
    case X10:
        X10LightDriver_TurnOn(driver);
        break;
    case AcmeWireless:
        AcmeWirelessLightDriver_TurnOn(driver);
        break;
    case MemoryMapped:
        MemMappedLightDriver_TurnOn(driver);
        break;
    case TestLightDriver:
        LightDriverSpy_TurnOn(driver);
        break;
    default:
        /* now what? */
        break;
    }
}

void LightController_TurnOff(int id)
{
    LightDriver_TurnOff(lightDrivers[id]);
}