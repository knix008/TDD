#include <stdlib.h>
#include <stdbool.h>
#include "LightDriver.h"

static LightDriverInterface interface = NULL;

void LightDriver_SetInterface(LightDriverInterface i)
{
    interface = i;
}

void LightDriver_TurnOn(LightDriver self)
{
    /*
    if (self)
    {
        if(self->vtable->TurnOn)
            self->vtable->TurnOn(self);
    }
    */
    if (self && self->vtable && self->vtable->TurnOn)
        self->vtable->TurnOn(self);
}

void LightDriver_TurnOff(LightDriver self)
{
    /*
    if (self)
    {
        if(self->vtable->TurnOff)
            self->vtable->TurnOn(self);
    }
    */
    if (self && self->vtable && self->vtable->TurnOff)
        self->vtable->TurnOff(self);
}

void LightDriver_Destroy(LightDriver self)
{
    /*
    if (self)
    {
        if(self->vtable->Destroy)
            self->vtable->Destroy(self);
    }
    */
   if (self && self->vtable && self->vtable->Destroy)
        self->vtable->Destroy(self);
}

const char *LightDriver_GetType(LightDriver driver)
{
    return driver->type;
}

int LightDriver_GetId(LightDriver driver)
{
    return driver->id;
}