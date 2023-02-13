#include <stdio.h>
#include <stdbool.h>
#include "LightDriver.h"

static LightDriverInterface interface = NULL;

void LightDriver_SetInterface(LightDriverInterface i)
{
    interface = i;
}

static bool isValid(LightDriver self)
{
    return interface && self;
}

void LightDriver_TurnOn(LightDriver self)
{
    if (isValid(self))
        interface->TurnOn(self);
}

void LightDriver_TurnOff(LightDriver self)
{
    if (isValid(self))
        interface->TurnOff(self);
}

void LightDriver_Destroy(LightDriver self)
{
    if (isValid(self))
        interface->Destroy(self);
}

const char *LightDriver_GetType(LightDriver driver)
{
    return driver->type;
}

int LightDriver_GetId(LightDriver driver)
{
    return driver->id;
}