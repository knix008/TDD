#include <stdlib.h>
#include <memory.h>
#include "AcmeWirelessLightDriver.h"
#include "Explodes.h"

typedef struct AcmeWirelessLightDriverStruct * AcmeWirelessLightDriver;
typedef struct AcmeWirelessLightDriverStruct
{
    LightDriverStruct base;
    const char * ssid;
    const char * key;
    int channel;
} AcmeWirelessLightDriverStruct;


LightDriver AcmeWirelessLightDriver_Create(int id, const char * ssid, const char * key, int channel)
{
     AcmeWirelessLightDriver self = (AcmeWirelessLightDriverStruct *)calloc(1, sizeof(AcmeWirelessLightDriverStruct));
     self->base.type = "Acme Wireless";
     self->base.id = id;
     self->ssid = ssid;
     self->key = key;
     self->channel = channel;
     return (LightDriver)self;
}

void AcmeWirelessLightDriver_Destroy(LightDriver super)
{
    free(super);
}

void AcmeWirelessLightDriver_TurnOn(LightDriver super)
{
    explodesInTestEnvironment(super);
}

void AcmeWirelessLightDriver_TurnOff(LightDriver super)
{
    explodesInTestEnvironment(super);
}
