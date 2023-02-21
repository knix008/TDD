#ifndef __MEMORYMAPPEDLIGHTDRIVER_H__
#define __MEMORYMAPPEDLIGHTDRIVER_H__
#include <stdint.h>
#include "LightDriver.h"
#include "Explodes.h"

LightDriver MemMappedLightDriver_Create(int lightId, uint32_t * address);
void MemMappedLightDriver_Destroy(LightDriver);
void MemMappedLightDriver_TurnOn(LightDriver);
void MemMappedLightDriver_TurnOff(LightDriver);

#endif
