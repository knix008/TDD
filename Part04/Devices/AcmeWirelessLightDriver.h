#ifndef __ACMEWIRELESSLIGHTDRIVER_H__
#define __ACMEWIRELESSLIGHTDRIVER_H__

#include "LightDriver.h"

LightDriver AcmeWirelessLightDriver_Create(int lightId, const char * ssid, const char * key, int channel);
void AcmeWirelessLightDriver_Destroy(LightDriver);
void AcmeWirelessLightDriver_TurnOn(LightDriver);
void AcmeWirelessLightDriver_TurnOff(LightDriver);

#endif
